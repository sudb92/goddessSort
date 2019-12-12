/****************************************************************************/
/****************************************************************************/
/*                                                                          */
/* Stefanos Paschalis & Heather Crawford                                    */
/*                                                                          */
/* Unpacking (and optionally event building) GRETINA decomposed data        */
/* and storing them in a ROOT tree, or creating and saving histograms.      */
/*                                                                          */
/* Usage:                                                                   */
/*  Unpack <g, m, or t> <Directory, i.e. CR-5> <Run#s, separated by spaces> */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/

/* Standard library includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iomanip>
#include "Riostream.h"
#include <vector>
#include <signal.h>
#include <deque>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <fstream>

/* ROOT includes */
#include "TString.h"
#include "TStyle.h"
#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"
#include "TSortedList.h"
#include "TStopwatch.h"
#include "TCanvas.h"
#include "TPostScript.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TGraph.h"
#include "TVector3.h"
#include "TMath.h"
#include "TCutG.h"

/* Program header files */
#include "Globals.h"
#include "Defines.h"
#include "UnpackGRETINARaw.h"

/* GRETINA-specific header files */
#include "GRETINA.h"
#include "SortingStructures.h"
#include "INLCorrection.h"
#include "UnpackUtilities.h"

/* Tracking... */
#include "Track.h"

#include "Tree.h"

#include "Utilities.h"

#define DEBUG2AND3 0

/****************************************************/

void PrintHelpInformation();
void PrintConditions();

void GetData(FILE* inf, controlVariables* ctrl, counterVariables* cnt,
            INLCorrection *inlCor, UShort_t junk[]);

void ReadMario(FILE* inf);
void SkipData(FILE* inf, UShort_t junk[]);

/****************************************************/

Int_t gotsignal;
void breakhandler(int dummy) {
    std::cout << "Got break signal.  Aborting sort cleanly..." << std::endl;
    gotsignal = 1;
}

/****************************************************/

int main(int argc, char *argv[]) {

    /* Some CTRL-C interrupt handling stuff... */
    gotsignal = 0;
    signal(SIGINT, breakhandler);

    /* When not enough arguments, print the help information */
    if(argc < 3) {PrintHelpInformation(); exit(1);}

    /* Initialize analysis control flags to default values,
       then read in the command line arguments. */
    controlVariables *ctrl = new controlVariables();
    ctrl->Initialize();
    Int_t good2Go = ctrl->InterpretCommandLine(argc, argv);
    if(good2Go != 1) {exit(-1);}
    PrintConditions();
    good2Go = ctrl->ReportRunFlags();
    if(good2Go != 1) {exit(-2);}
    printf("\n");

    gret = new GRETINA();
    gret->Initialize();
    gret->var.Initialize();
    gret->var.InitializeGRETINAVariables("gretina.set");

    counterVariables *cnt = new counterVariables();

    /* Initialize the GRETINA data structures. */

    /* Superpulse analysis */
    gret->sp.Initialize(ctrl, &gret->var);

    /* INL correction parameters */
    INLCorrection *inlCor = new INLCorrection();
    inlCor->Initialize(ctrl, &gret->var);

    /* Initialize tracking stuff. */
    if(ctrl->doTRACK) {
        gret->track.Initialize();
    }

    /* And data arrays... */
    /* Throw-away/skip data */
    UShort_t junk[8192];

    /* Get the parameters for mapping from crystal coordinate frame
       to the lab frame, for Doppler correction. */
    gret->rot.ReadMatrix("crmat.dat");

    /* Get the calibration parameters. */
    if(ctrl->specifyCalibration) {
        gret->var.ReadGeCalFile(ctrl->calibrationFile);
    } else {
        std::cout << PrintOutput("\t\tUsing default GRETINA energy calibration file.\n", "blue");
        gret->var.ReadGeCalFile("gretinaCalibrations/gCalibration.dat");
    }
    std::cout << std::endl;


    FILE *inf;

    FILE *generalOut = NULL;
    if(ctrl->outputON) {
        if(ctrl->outputName) {
            generalOut = fopen(ctrl->outputFileName.Data(), "wb");
            if(!generalOut) {
                std::cout << PrintOutput("\t\tCannot open general output file: ", "red") << ctrl->outputFileName.Data() << std::endl;
                exit(2);
            }
        } else {
            generalOut = fopen("GeneralFile.out", "wb");
            if(!generalOut) {
                std::cout << PrintOutput("\t\tCannot open general output file: GeneralFile.out\n", "red");
                exit(2);
            }
        }
    }

    TStopwatch timer;

    /* Loop over each run given at the command line. */
    if(ctrl->fileType == "f1" || ctrl->fileType == "f2" ||
        ctrl->fileType == "f") {
        ctrl->startRun = 0; argc = 1;
    } /* For specific file name, once through loop only. */

    for(Int_t mm = ctrl->startRun; mm < argc; mm++) {
        if(!gotsignal) { /* We haven't aborted for some reason. */

            timer.Reset(); timer.Start();
            cnt->ResetRunCounters();

            TString runNumber = argv[mm];
            cnt->runNum = atoi(argv[mm]);

            Int_t fileOK = OpenInputFile(&inf, ctrl, runNumber);
            if(fileOK != 0) {exit(2);}

            /* Open output file, set up tree and/or histograms. */
            TFile *fout_root = NULL;
            if(ctrl->withTREE || ctrl->withHISTOS) {
                fout_root = new TFile(ctrl->outfileName.Data(), "RECREATE");
                fout_root->SetCompressionAlgorithm(1);
                fout_root->SetCompressionLevel(2);
                std::cout << PrintOutput("\t\tOutput file: ", "blue") << ctrl->outfileName << PrintOutput(" (compression ", "blue") <<
                             fout_root->GetCompressionLevel() << PrintOutput(")\n", "blue");
            } else {
                std::cout << PrintOutput("\t\tNo ROOT output requested -- no histos or trees.\n", "blue");
            }

            if(ctrl->withTREE) {
                InitializeTree();
            }

            // teb->SetMaxTreeSize(1000000000LL); /* Max tree size is 1GB */

            std::cout << PrintOutput("\t\t********************************************************\n\n", "blue");

            /* Reset variables needed for unpacking, histogramming, etc. */
            cnt->ResetRunCounters();
            Bool_t GO_FOR_BUILD = 1;

            Int_t TSerrors = 0;
            long long int currTS = 0;  long long int lastTS = 0;
            long long int deltaEvent = 0;
            Int_t siz = 0;
            Int_t remaining = 0;
            Int_t s800Length = 0;
            Int_t timeToOptimize = 0;
            Int_t atSTARTFile2 = 1; Int_t BonusMode3 = 0;

            /********************************************************/
            /*  THE MAIN EVENT -- SORTING LOOP                      */
            /********************************************************/

            /* Loop over file, reading data, and building events... */
            if(ctrl->pgh == 0) { /* We expect global headers, so read one */
                siz = fread(&gHeader, sizeof(struct globalHeader), 1, inf);
            }

            while(siz && !gotsignal) {

                if(cnt->TSFirst == 0 && gHeader.timestamp > 0) {cnt->TSFirst = gHeader.timestamp;}
                cnt->TSLast = gHeader.timestamp;

                gHeader.timestamp++; /* For simulation - first TS is 0, so just
                                        adding 1 solves a bunch of problems... */

                if(ctrl->noEB) { /* Just get the data, don't event build. */

                    GetData(inf, ctrl, cnt, inlCor, junk);

                    /* Fill singles spectra as appropriate */
                    if(ctrl->withHISTOS && ctrl->calibration && !ctrl->xtalkAnalysis) {
                        gret->fillHistos(1);
                    }
                    ResetEvent(ctrl, cnt);
                    cnt->event = 0.0;
                } else { /* !ctrl->noEB */

                    /* We are building events (i.e. grouping by timestamp) --
                       Check against timestamps in file being out of order... */

                    if(gHeader.timestamp < lastTS) {
                        if(!ctrl->suppressTS) {
                            std::cout << ALERTTEXT;
                            printf("Unpack(): TS out of order: lastTS %lld, current %lld\n",
                                      lastTS, gHeader.timestamp);
                            std::cout << RESET_COLOR;  fflush(stdout);
                        }
                        TSerrors++;
                    }
                    lastTS = gHeader.timestamp;

                    if((gHeader.timestamp != 0) && (currTS == 0) ) {
                        currTS = gHeader.timestamp;
                    }

                    /* Just throw out stupid events with no valid TS. */
                    if(gHeader.timestamp != 0 && remaining != 5) {
                        GO_FOR_BUILD = 1;
                    } else {GO_FOR_BUILD = 0;}

                    if(GO_FOR_BUILD) {

                        /* Build events based on timestamp differences between the
                           start of an event and current timestamp. */
                        deltaEvent = (Float_t)(gHeader.timestamp - currTS);

                        if(abs(deltaEvent) < EB_DIFF_TIME) {
                            GetData(inf, ctrl, cnt, inlCor, junk);
                            if(ctrl->superPulse) {
                                if(gHeader.type == RAW) {
                                    gret->sp.trLength = gret->g3Temp[0].wf.raw.size();
                                }
                            }
                        } else { /* Time difference is big...old event should be closed. */

                            /* We need to be careful of tracelengths in superPulse analysis... */
                            if(ctrl->superPulse) {
                                if(gHeader.type == RAW) {
                                    gret->sp.trLength = gret->g3Temp[0].wf.raw.size();
                                }
                            }

                            if(ctrl->gateTree) {} else {
                                Int_t evtOK = ProcessEvent(currTS, ctrl, cnt);
                                if (evtOK < 0) { raise(SIGINT); }
                            }

                            /* Check on gate conditions...do we write filtered output? */
                            if(ctrl->outputON) {} // S800 crap
                            ResetEvent(ctrl, cnt);
                            cnt->event = 0.0;

                            /* Update timestamp information for beginning of new event,
                                and start filling new event. */
                            currTS = gHeader.timestamp;
                            deltaEvent = (Float_t)(gHeader.timestamp - currTS);

                            GetData(inf, ctrl, cnt, inlCor, junk);
                        }
                    } else { /* End of "if (GO_FOR_BUILD)" */
                        SkipData(inf, junk);
                        cnt->Increment(gHeader.length);
                    }
                } /* End of !ctrl->noEB */

                if(cnt->bytes_read_since_last_time > 2*1024*1024) {
                    if(cnt->bytes_read > 1024*1024*1024) {
                        std::cerr << "\t\tProcessing " << (Float_t)cnt->bytes_read/(1024.*1024.*1024.) << " GB         " <<"\r";
                    } else {
                        std::cerr << "\t\tProcessing " << cnt->bytes_read/(1024*1024) << " MB    " <<"\r";
                    }
                    cnt->MBread+=2;
                    cnt->bytes_read_since_last_time = 0;
                }

                siz = fread(&gHeader, sizeof(struct globalHeader), 1, inf);

            } /* End of "while we still have data and no interrupt signal" */

            if(ctrl->superPulse) {
                gret->checkSPIntegrity();
                gret->sp.MakeSuperPulses();
            }

            if(ctrl->outputON) {} // S800 crap

            /* Write the last event... */
            if(ctrl->gateTree) {} else {
                if(ctrl->withTREE) {teb->Fill();  cnt->treeWrites++;}
            }

            timer.Stop();

            std::cout << PrintOutput("\t\tCPU time: ", "yellow") << timer.CpuTime() << PrintOutput("; Real time: ", "yellow") << timer.RealTime() << std::endl;
            std::cout << PrintOutput("\t\tAverage processing speed: ", "yellow") << (cnt->bytes_read/(1024*1024))/timer.RealTime() << PrintOutput("MB/s -- File size was ", "yellow") << cnt->bytes_read/(1024*1024) << PrintOutput("MB\n", "yellow");
            // std::cout << "\n CPU time: " << timer.CpuTime() << "\tReal time: " << timer.RealTime() << std::endl;
            // std::cout << " Average processing speed: " << (cnt->bytes_read/(1024*1024))/timer.RealTime()
            //        << "MB/s -- File size was " << cnt->bytes_read/(1024*1024) << " MB \n" << std::endl;

            cnt->PrintRunStatistics(ctrl->pgh, ctrl->withWAVE, ctrl->superPulse, ctrl->analyze2AND3);
            cnt->ResetRunCounters();

            if(ctrl->withTREE) {
                std::cout << PrintOutput("\t\tWriting ROOT tree...\n", "blue");
                teb->Write();
                if(ctrl->withWAVE) {
                    if(ctrl->WITH_TRACETREE) {
                        wave->Write();
                    }
                }
            }

            if(ctrl->withHISTOS) {
                std::cout << PrintOutput("\t\tWriting histograms...\n", "blue");
                gret->gHist.writeHistos(1);
            }
            if(ctrl->withHISTOS || ctrl->withTREE) {
                std::cout << PrintOutput("\t\tROOT file \"", "blue") << ctrl->outfileName.Data() << PrintOutput("\" closing...\n", "blue");
                //fout_root->Write();
                fout_root->Close();
            }

            std::cout << PrintOutput("\t\t*******************************************************\n\n", "blue");

        } /* End of if !gotsignal */
    } /* End of iterating over different run # */

    if(ctrl->superPulse) {
        gret->checkSPIntegrity();
        gret->sp.MakeSuperPulses();
        gret->sp.FinishSuperPulses();
        gret->sp.WriteSuperPulses();
    }

    if(ctrl->outputON) {
        std::cout << std::endl;
        std::cout << "Closing output file...";
        fclose(generalOut);
        std::cout << "Done. " << std::endl;
    }

    /* Declare victory!!! */
    std::cout << std::endl;
    timer.Delete();

    return 1;
}

/****************************************************/

void GetData(FILE* inf, controlVariables* ctrl, counterVariables* cnt,
         INLCorrection *inlCor, UShort_t junk[]) {

    cnt->Increment(sizeof(struct globalHeader));

    switch(gHeader.type) {

        case DECOMP:
            if(cnt->headerType[DECOMP] == 0 && ctrl->withTREE) {
                InitializeTreeMode2();
                for(Int_t i = 0; i < cnt->treeWrites; i++) {
                    teb->FindBranch("g2")->Fill();
                }
            }
            gret->getMode2(inf, gHeader.length, cnt);
            break;

        case TRACK:
            if(cnt->headerType[TRACK] == 0 && ctrl->withTREE) {
                InitializeTreeMode1();
                for(Int_t i = 0; i < cnt->treeWrites; i++) {
                    teb->FindBranch("g1")->Fill();
                }
            }
            gret->getMode1(inf, cnt);
            break;

        case RAW:
            if(cnt->headerType[RAW] == 0 && ctrl->withTREE) {
                InitializeTreeMode3();
                for(Int_t i = 0; i < cnt->treeWrites; i++) {
                    teb->FindBranch("g3")->Fill();
                }
            }
            gret->getMode3(inf, gHeader.length, cnt, ctrl);
            break;

        case RAWHISTORY:
            if(cnt->headerType[RAWHISTORY] == 0 && ctrl->withTREE) {
                InitializeTreeHistory();
                for(Int_t i = 0; i < cnt->treeWrites; i++) {
                    teb->FindBranch("g3H")->Fill();
                }
            }
            gret->getMode3History(inf, gHeader.length, gHeader.timestamp, cnt);
            break;

        case BGS:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case S800:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case S800AUX:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case S800AUX_TS:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case S800PHYSICS:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case BANK88:
            if(cnt->headerType[BANK88] == 0 && ctrl->withTREE) {
                InitializeTreeBank88();
                for(Int_t i = 0; i < cnt->treeWrites; i++) {
                    teb->FindBranch("b88")->Fill();
                }
            }
            gret->getBank88(inf, gHeader.length, cnt);  cnt->Increment(gHeader.length);
            break;

        case GRETSCALER:
            gret->getScaler(inf, gHeader.length);  cnt->Increment(gHeader.length);
            break;

        case G4SIM:
            if(cnt->headerType[G4SIM] == 0 && ctrl->withTREE) {
                InitializeTreeSimulation();
                for(Int_t i = 0; i < cnt->treeWrites; i++) {
                    teb->FindBranch("gSim")->Fill();
                }
            }
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case CHICO:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case PWALL:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case PWALLAUX:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case GODDESS:
            SkipData(inf, junk);  cnt->Increment(gHeader.length);
            break;

        case LENDA:
            SkipData(inf, junk); cnt->Increment(gHeader.length);
            break;

        case DFMA:
            SkipData(inf, junk); cnt->Increment(gHeader.length);
            break;

        case 0:
            std::cout << "GlobalHeader type = 0.  Ignoring." << std::endl;
            cnt->Increment(gHeader.length);
            break;

        case 100:
            std::cout << "GlobalHeader Mario found. " << std::endl;
            ReadMario(inf);
            cnt->Increment(gHeader.length);
            break;

        default:
            std::cout << "GlobalHeader type not recognized: " << gHeader.type << std::endl;
            SkipData(inf, junk);
            cnt->Increment(gHeader.length);
            break;
    }

    if(gHeader.type < 50) {
        cnt->headerType[gHeader.type]++;
        cnt->setEventBit(gHeader.type);
    }
    if(gHeader.type == RAWHISTORY) {
        cnt->setEventBit(RAW);
        cnt->headerType[RAW]++;
    }
}

/****************************************************/

void ReadMario(FILE* inf) {
    out4Mario mario;
    fread(&mario, 1, sizeof(struct out4Mario), inf);
    std::cout << mario.ccEnergy << std::endl;
    for(Int_t i = 0; i < 36; i++) {
        std::cout << mario.segEnergy[i] << std::endl;
    }
}

/****************************************************/

void SkipData(FILE* inf, UShort_t junk[]) {
    Int_t siz = fread(junk, 1, gHeader.length, inf);
    if(siz != gHeader.length) {
        std::cout << ALERTTEXT;
        printf("SkipData(): Failed.\n");
        std::cout << RESET_COLOR;  fflush(stdout);
    }
}

/****************************************************/

void PrintHelpInformation() {
    printf("\n");
    printf("Usage: ./Unpack <File Type> <Usage flags> -d <Subdirectory, i.e. CR-5> -run <input run ### (separate multiple files by a space)>\n");
    printf("    Valid file types: -g  (Global.dat)\n");
    printf("                      -gr (GlobalRaw.dat)\n");
    printf("                      -m  (Merged.dat, externally merged file, usually GRETINA mode 3)\n");
    printf("                      -m2 (Merged.Mode2.dat, GRETINA mode2 externally merged file)\n");
    printf("                      -f  <FILENAME> (specific file -- do not require subdirectory or run #)\n");
    printf("    Valid usage flags: -preGH2 (file is Mode2, from the pre global header (pGH) era) \n");
    printf("                       -preGH3 (file is Mode3, from the pre global header (pGH) era)\n");
    printf("                       -wf (do waveform analysis; algorithms to run flagged in Unpack.h)\n");
    printf("                       -noEB (DISABLE event building; default is to BUILD events)\n");
    printf("                       -calibrationRun (DISABLE event building, and fill calibration histograms)\n");
    printf("                       -superPulse <lowE> <highE> <detMapFile directory> <XtalkFile>\n");
    printf("                               (turns off tree and histograms, builds superpulse .spn files)\n");
    printf("                       -noSeg (DISABLE segment analysis, i.e. segment summing; default is ON \n");
    printf("                       -track (do tracking, such as it is -- options specified in track.chat)\n");
    printf("                       -zip (compressed data file, will append .gz to filename)\n");
    printf("                       -bzip (compressed data file, will append .bz2 to filename)\n");
    printf("                       -withHistos (turn ON histograms, as defined in Histos.h, default is OFF)\n");
    printf("                       -noTree (turn OFF root tree, default is ON)\n");
    printf("                       -noHFC (turn OFF HFC presort piping; default is ON)\n");
    printf("                       -dopplerSimple (use simple GRETINA decomp position for Doppler correction)\n");
    printf("                       -suppressTS (suppress TS error warnings in analysis)\n");
    /* 2015-04-21 CMC added command-line flag descriptions, as I understand them, feel free to correct or update */
    printf("                       -outputName <FILENAME> (set the PID-gated output event file name)\n");
    printf("                       -rootName <FILENAME> (set the output ROOT file name)\n");
    printf("                       -analyze2and3 (analyze Mode2 and Mode3, matching by timestamps)\n");
    printf("                       -gateTree (gates tree and histogramm by a PID gate)\n");
    printf("                       -readCal <FILENAME> (read in a calibration file)\n");
    printf("                       -xtalkAnalysis <ID> <lowE> <highE> \n");
    printf("                               (turns off tree, builds histograms for segment cross-talk analysis)\n");
    printf("                       -INLcorrect <INLCConly> <digMapFileName> \n");
    printf("                               (turns on waveform analysis, attempts to correct energy filter INL)\n");
    printf("\n");
}

/****************************************************/

void PrintConditions() {
    std::cout << "\n\t\t" << PrintOutput("***************************************************************************\n", "blue") << std::endl;
    std::cout << "\t\t" << PrintOutput("Initializing -- GRETINA sort...", "blue") << std::endl;
}
