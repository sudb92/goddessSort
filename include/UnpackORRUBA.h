#ifndef UnpackORRUBA_h
#define UnpackORRUBA_h

#include "ProcessBB10.h"
// #include "ProcessIC.h"
#include "ProcessQQQ5.h"
#include "ProcessSX3.h"
#include "RunList.h"
#include "TypeDef.h"
#include "Utilities.h"
#include "Calibrations.h"

#include <bitset>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

#include <TCanvas.h>
#include <TCutG.h>
#include <signal.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TObject.h>
#include <TRint.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TTree.h>

class UnpackORRUBA {
public:
    UnpackORRUBA() {};
    UnpackORRUBA(fileListStruct run);
    ~UnpackORRUBA() {};

    bool GetCompleted() {return completed;}

    TTree* GetTree() {return tree;}



private:
    inline static bool received_sigint;
    static void handle_sigint(int signal){
        if(signal==2) {
            received_sigint = true;
            std::cout << "Received Ctrl+C, skipping rest of the loop.." << std::endl;
        }
    }

    //bool CompareBB10Det(BB10Detector &BB10A, BB10Detector &BB10B);
    //bool CompareQQQ5Det(QQQ5Detector &QQQ5A, QQQ5Detector &QQQ5B);
    //bool CompareSX3Det(SuperX3Detector &SX3A, SuperX3Detector &SX3B);

    bool completed;

    ////////////////////
    // Tree variables //
    ////////////////////

    TTree* tree;

    // General variables
    int fRunNumber;

    // QQQ5 dE Detectors
	int fdQQQ5RingMul_dE;
	int fdQQQ5DetRingMul_dE[2]={}; // The number of rings hit in each detector, index is detector number
    int fdQQQ5DetRing_dE[128]={}; // The detector for each ring hit in event (ordered by detector)
    int fdQQQ5Ring_dE[128]={}; // The ring number for each ring hit in event (ordered by detector)
    int fdQQQ5RingChannel_dE[128]={}; // The channel number for each ring hit in event (ordered by detector)
    int fdQQQ5RingADC_dE[128]={}; // ADC value for each ring hit in event (ordered by detector)

	int fdQQQ5SectorMul_dE;
	int fdQQQ5DetSectorMul_dE[2]={};
    int fdQQQ5DetSector_dE[128]={};
    int fdQQQ5Sector_dE[128]={};
    int fdQQQ5SectorChannel_dE[128]={};
    int fdQQQ5SectorADC_dE[128]={};


    // QQQ5 E Detectors
	int fdQQQ5RingMul_E;
	int fdQQQ5DetRingMul_E[4]={}; // The number of rings hit in each detector, index is detector number
    int fdQQQ5DetRing_E[128]={}; // The detector for each ring hit in event (ordered by detector)
    int fdQQQ5Ring_E[128]={}; // The ring number for each ring hit in event (ordered by detector)
    int fdQQQ5RingChannel_E[128]={}; // The channel number for each ring hit in event (ordered by detector)
    int fdQQQ5RingADC_E[128]={}; // ADC value for each ring hit in event (ordered by detector)

	int fdQQQ5SectorMul_E;
	int fdQQQ5DetSectorMul_E[4]={};
    int fdQQQ5DetSector_E[128]={};
    int fdQQQ5Sector_E[128]={};
    int fdQQQ5SectorChannel_E[128]={};
    int fdQQQ5SectorADC_E[128]={};


    // QQQ5 Upstream Detectors
	int fuQQQ5RingMul;
	int fuQQQ5DetRingMul[4]={}; // The number of rings hit in each detector, index is detector number
    int fuQQQ5DetRing[128]={}; // The detector for each ring hit in event (ordered by detector)
    int fuQQQ5Ring[128]={}; // The ring number for each ring hit in event (ordered by detector)
    int fuQQQ5RingChannel[128]={}; // The channel number for each ring hit in event (ordered by detector)
    int fuQQQ5RingADC[128]={}; // ADC value for each ring hit in event (ordered by detector)

	int fuQQQ5SectorMul;
	int fuQQQ5DetSectorMul[4]={};
    int fuQQQ5DetSector[128]={};
    int fuQQQ5Sector[128]={};
    int fuQQQ5SectorChannel[128]={};
    int fuQQQ5SectorADC[128]={};

    // BB10 Detectors
    int fBB10Mul;
    int fBB10DetMul[12]={};
    int fBB10Det[256]={};
    int fBB10Strip[256]={};
    int fBB10Channel[256]={};
    int fBB10ADC[256]={};

    // Super X3 Downstream Detectors
    int fdSX3LeftMul;
    int fdSX3RightMul;
    int fdSX3DetLeftMul[12]={}; // Left multiplicity for each detector, index is detector number
    int fdSX3DetRightMul[12]={}; // Right multiplicity for each detector, index is detector number
    int fdSX3DetLeft[128]={}; // Detector for each left hit
    int fdSX3DetRight[128]={}; // Detector for each right hit
    int fdSX3LeftStrip[128]={}; // Strip for each left hit
    int fdSX3RightStrip[128]={}; // Strip for each right hit
    int fdSX3LeftChannel[128]={}; // Channel for each left hit
    int fdSX3RightChannel[128]={};
    int fdSX3LeftADC[128]={}; // ADC for each right hit
    int fdSX3RightADC[128]={};

    int fdSX3BackMul;
    int fdSX3DetBackMul[12]={}; // Back multiplicity for each detector
    int fdSX3DetBack[128]={}; // Detector for each back hit
    int fdSX3BackSector[128]={}; // Sector for each back hit
    int fdSX3BackChannel[128]={}; // Channel for each back hit
    int fdSX3BackADC[128]={}; // ADC for each back hit


    // Super X3 Upstream Detectors
    int fuSX3LeftMul;
    int fuSX3RightMul;
    int fuSX3DetLeftMul[12]={}; // Left multiplicity for each detector
    int fuSX3DetRightMul[12]={}; // Right multiplicity for each detector
    int fuSX3DetLeft[128]={}; // Detector for each left hit
    int fuSX3DetRight[128]={}; // Detector for each right hit
    int fuSX3LeftStrip[128]={}; // Strip for each left hit
    int fuSX3RightStrip[128]={}; // Strip for each right hit
    int fuSX3LeftChannel[128]={}; // Channel for each left hit
    int fuSX3RightChannel[128]={};
    int fuSX3LeftADC[128]={}; // ADC for each right hit
    int fuSX3RightADC[128]={};

    int fuSX3BackMul;
    int fuSX3DetBackMul[12]={}; // Back multiplicity for each detector
    int fuSX3DetBack[128]={}; // Detector for each back hit
    int fuSX3BackSector[128]={}; // Sector for each back hit
    int fuSX3BackChannel[128]={}; // Channel for each back hit
    int fuSX3BackADC[128]={}; // ADC for each back hit


    int fTDCSilicon;
    int fTDCSiliconDivTrig;
    int fTDCSiliconGRETINATrig;
    int fTDCRF;
    int fTDCGRETINA;
    int fTDCSiliconAlt;
    int fTDCSiliconUpstream;


    unsigned long long fTimeStamp, fGRETINATimeStamp;
	unsigned long long ftStamps[512];
};

#endif
