#include "Utilities.h"

unsigned int ExtractBits(unsigned int Source, int Begin, int Length){
    return (Source >> Begin) & ((1 << Length) - 1);
}

 std::string PrintOutput(std::string Output, std::string Color){
	int ColorCode = 0;
	if(Color.compare("red") == 0){
		ColorCode = 31;
	} else if(Color.compare("green") == 0){
		ColorCode = 32;
	} else if(Color.compare("yellow") == 0){
		ColorCode = 33;
	} else if(Color.compare("blue") == 0) {
        ColorCode = 34;
    } else if(Color.compare("magenta") == 0) {
        ColorCode = 35;
    } else if(Color.compare("cyan") == 0) {
	    ColorCode = 36;
	} else {
		std::cout << Form("Output Color not recognized : %s", Color.c_str()) << std::endl;
		return Form("%s", Output.c_str());
	}

	return Form("\033[1;%dm%s\033[0m", ColorCode, Output.c_str());
}

void PrintConditions() {
    printf("\n***************************************************************************\n\n");
    printf("    Initializing -- GRETINA ");
    printf("unpacker...\n");
}

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
