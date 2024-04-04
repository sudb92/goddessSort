#ifndef Unpack_h
#define Unpack_h

#include "GRETINA.h"
#include "RunList.h"
#include "TypeDef.h"
#include "UnpackGRETINA.h"
#include "UnpackORRUBA.h"
#include "Utilities.h"

#include <bitset>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include <TCanvas.h>
#include <TCutG.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TObject.h>
#include <TRint.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>

#include <Compression.h>

class Unpack {
public:
    Unpack();

private:
    void CombineReader(fileListStruct run);
    void CombineReader2(fileListStruct run);
    void CombineReaderCompare(fileListStruct run);

    // TSAscSort lambda form could be directly put in functions
    //auto TSAscSort = [](const std::pair<Int_t,Long64_t>& a, const std::pair<Int_t,Long64_t>& b) { return a.second < b.second;};

    static bool TSAscSort(const std::pair<Int_t,Long64_t>& a, const std::pair<Int_t,Long64_t>& b) { return a.second < b.second;}


    // General variables
    int RunNumber;

    // QQQ5 dE Detectors
    int dQQQ5RingMul_dE;
    int dQQQ5DetRingMul_dE[2]; // The number of rings hit in each detector
    int dQQQ5DetRing_dE[128]; // The detector for each ring hit in event (ordered by detector)
    int dQQQ5Ring_dE[128]; // The ring number for each ring hit in event (ordered by detector)
    int dQQQ5RingChannel_dE[128]; // The channel number for each ring hit in event (ordered by detector)
    int dQQQ5RingADC_dE[128]; // ADC value for each ring hit in event (ordered by detector)

    int dQQQ5SectorMul_dE;
    int dQQQ5DetSectorMul_dE[2];
    int dQQQ5DetSector_dE[128];
    int dQQQ5Sector_dE[128];
    int dQQQ5SectorChannel_dE[128];
    int dQQQ5SectorADC_dE[128];


    // QQQ5 E Detectors
    int dQQQ5RingMul_E;
    int dQQQ5DetRingMul_E[4]; // The number of rings hit in each detector
    int dQQQ5DetRing_E[128]; // The detector for each ring hit in event (ordered by detector)
    int dQQQ5Ring_E[128]; // The ring number for each ring hit in event (ordered by detector)
    int dQQQ5RingChannel_E[128]; // The channel number for each ring hit in event (ordered by detector)
    int dQQQ5RingADC_E[128]; // ADC value for each ring hit in event (ordered by detector)

    int dQQQ5SectorMul_E;
    int dQQQ5DetSectorMul_E[4];
    int dQQQ5DetSector_E[128];
    int dQQQ5Sector_E[128];
    int dQQQ5SectorChannel_E[128];
    int dQQQ5SectorADC_E[128];




    // QQQ5 Upstream Detectors
    int uQQQ5RingMul;
    int uQQQ5DetRingMul[4]; // The number of rings hit in each detector
    int uQQQ5DetRing[128]; // The detector for each ring hit in event (ordered by detector)
    int uQQQ5Ring[128]; // The ring number for each ring hit in event (ordered by detector)
    int uQQQ5RingChannel[128]; // The channel number for each ring hit in event (ordered by detector)
    int uQQQ5RingADC[128]; // ADC value for each ring hit in event (ordered by detector)

    int uQQQ5SectorMul;
    int uQQQ5DetSectorMul[4];
    int uQQQ5DetSector[128];
    int uQQQ5Sector[128];
    int uQQQ5SectorChannel[128];
    int uQQQ5SectorADC[128];


    // BB10 Detectors
    int BB10Mul;
    int BB10DetMul[12];
    int BB10Det[256];
    int BB10Strip[256];
    int BB10Channel[256];
    int BB10ADC[256];

    // Super X3 Downstream Detectors
    int dSX3LeftMul;
    int dSX3RightMul;
    int dSX3DetLeftMul[12]={}; // Left multiplicity for each detector
    int dSX3DetRightMul[12]={}; // Right multiplicity for each detector
    int dSX3DetLeft[128]; // Detector for each left hit
    int dSX3DetRight[128]; // Detector for each right hit
    int dSX3LeftStrip[128]; // Strip for each left hit
    int dSX3RightStrip[128]; // Strip for each right hit
    int dSX3LeftChannel[128]; // Channel for each left hit
    int dSX3RightChannel[128];
    int dSX3LeftADC[128]; // ADC for each right hit
    int dSX3RightADC[128];

    // Super X3 Upstream Detectors
    int uSX3LeftMul;
    int uSX3RightMul;
    int uSX3DetLeftMul[12]={}; // Left multiplicity for each detector
    int uSX3DetRightMul[12]={}; // Right multiplicity for each detector
    int uSX3DetLeft[128]; // Detector for each left hit
    int uSX3DetRight[128]; // Detector for each right hit
    int uSX3LeftStrip[128]; // Strip for each left hit
    int uSX3RightStrip[128]; // Strip for each right hit
    int uSX3LeftChannel[128]; // Channel for each left hit
    int uSX3RightChannel[128];
    int uSX3LeftADC[128]; // ADC for each right hit
    int uSX3RightADC[128];

    int uSX3BackMul;
    int uSX3DetBackMul[12]={}; // Back multiplicity for each detector
    int uSX3DetBack[128]; // Detector for each back hit
    int uSX3BackSector[128]; // Sector for each back hit
    int uSX3BackChannel[128]; // Channel for each back hit
    int uSX3BackADC[128]; // ADC for each back hit


    int dSX3BackMul;
    int dSX3DetBackMul[12]={}; // Back multiplicity for each detector
    int dSX3DetBack[128]; // Detector for each back hit
    int dSX3BackSector[128]; // Sector for each back hit
    int dSX3BackChannel[128]; // Channel for each back hit
    int dSX3BackADC[128]; // ADC for each back hit

    int TDCSilicon;
    int TDCSiliconDivTrig;
    int TDCSiliconGRETINATrig;
    int TDCRF;
    int TDCGRETINA;
    int TDCSiliconAlt;
    int TDCSiliconUpstream;

    unsigned long long TimeStamp;
    unsigned long long tStamps[512];


    // General variables
    int fRunNumber;


    // QQQ5 dE Detectors
    int fdQQQ5RingMul_dE;
    int fdQQQ5DetRingMul_dE[2]; // The number of rings hit in each detector
    int fdQQQ5DetRing_dE[128]; // The detector for each ring hit in event (ordered by detector)
    int fdQQQ5Ring_dE[128]; // The ring number for each ring hit in event (ordered by detector)
    int fdQQQ5RingChannel_dE[128]; // The channel number for each ring hit in event (ordered by detector)
    int fdQQQ5RingADC_dE[128]; // ADC value for each ring hit in event (ordered by detector)

    int fdQQQ5SectorMul_dE;
    int fdQQQ5DetSectorMul_dE[2];
    int fdQQQ5DetSector_dE[128];
    int fdQQQ5Sector_dE[128];
    int fdQQQ5SectorChannel_dE[128];
    int fdQQQ5SectorADC_dE[128];

    // QQQ5 E Detectors
    int fdQQQ5RingMul_E;
    int fdQQQ5DetRingMul_E[4]; // The number of rings hit in each detector
    int fdQQQ5DetRing_E[128]; // The detector for each ring hit in event (ordered by detector)
    int fdQQQ5Ring_E[128]; // The ring number for each ring hit in event (ordered by detector)
    int fdQQQ5RingChannel_E[128]; // The channel number for each ring hit in event (ordered by detector)
    int fdQQQ5RingADC_E[128]; // ADC value for each ring hit in event (ordered by detector)

    int fdQQQ5SectorMul_E;
    int fdQQQ5DetSectorMul_E[4];
    int fdQQQ5DetSector_E[128];
    int fdQQQ5Sector_E[128];
    int fdQQQ5SectorChannel_E[128];
    int fdQQQ5SectorADC_E[128];

    // QQQ5 Upstream Detectors
    int fuQQQ5RingMul;
    int fuQQQ5DetRingMul[4]; // The number of rings hit in each detector
    int fuQQQ5DetRing[128]; // The detector for each ring hit in event (ordered by detector)
    int fuQQQ5Ring[128]; // The ring number for each ring hit in event (ordered by detector)
    int fuQQQ5RingChannel[128]; // The channel number for each ring hit in event (ordered by detector)
    int fuQQQ5RingADC[128]; // ADC value for each ring hit in event (ordered by detector)

    int fuQQQ5SectorMul;
    int fuQQQ5DetSectorMul[4];
    int fuQQQ5DetSector[128];
    int fuQQQ5Sector[128];
    int fuQQQ5SectorChannel[128];
    int fuQQQ5SectorADC[128];


    // BB10 Detectors
    int fBB10Mul;
    int fBB10DetMul[12];
    int fBB10Det[256];
    int fBB10Strip[256];
    int fBB10Channel[256];
    int fBB10ADC[256];

    // Super X3 Downstream Detectors
    int fdSX3LeftMul;
    int fdSX3RightMul;
    int fdSX3DetLeftMul[12]={}; // Left multiplicity for each detector
    int fdSX3DetRightMul[12]={}; // Right multiplicity for each detector
    int fdSX3DetLeft[128]; // Detector for each left hit
    int fdSX3DetRight[128]; // Detector for each right hit
    int fdSX3LeftStrip[128]; // Strip for each left hit
    int fdSX3RightStrip[128]; // Strip for each right hit
    int fdSX3LeftChannel[128]; // Channel for each left hit
    int fdSX3RightChannel[128];
    int fdSX3LeftADC[128]; // ADC for each right hit
    int fdSX3RightADC[128];

    int fdSX3BackMul;
    int fdSX3DetBackMul[12]={}; // Back multiplicity for each detector
    int fdSX3DetBack[128]; // Detector for each back hit
    int fdSX3BackSector[128]; // Sector for each back hit
    int fdSX3BackChannel[128]; // Channel for each back hit
    int fdSX3BackADC[128]; // ADC for each back hit


    // Super X3 Upstream Detectors
    int fuSX3LeftMul;
    int fuSX3RightMul;
    int fuSX3DetLeftMul[12]={}; // Left multiplicity for each detector
    int fuSX3DetRightMul[12]={}; // Right multiplicity for each detector
    int fuSX3DetLeft[128]; // Detector for each left hit
    int fuSX3DetRight[128]; // Detector for each right hit
    int fuSX3LeftStrip[128]; // Strip for each left hit
    int fuSX3RightStrip[128]; // Strip for each right hit
    int fuSX3LeftChannel[128]; // Channel for each left hit
    int fuSX3RightChannel[128];
    int fuSX3LeftADC[128]; // ADC for each right hit
    int fuSX3RightADC[128];

    int fuSX3BackMul;
    int fuSX3DetBackMul[12]={}; // Back multiplicity for each detector
    int fuSX3DetBack[128]; // Detector for each back hit
    int fuSX3BackSector[128]; // Sector for each back hit
    int fuSX3BackChannel[128]; // Channel for each back hit
    int fuSX3BackADC[128]; // ADC for each back hit


    int fTDCSilicon;
    int fTDCSiliconDivTrig;
    int fTDCSiliconGRETINATrig;
    int fTDCRF;
    int fTDCGRETINA;
    int fTDCSiliconAlt;
    int fTDCSiliconUpstream;


    unsigned long long fTimeStamp, fGRETINATimeStamp;

    unsigned long long ftStamps[512];

    bool foundGRETINA;
    Int_t xtalsMul;
    Float_t xtals_xlab[128];
    Float_t xtals_ylab[128];
    Float_t xtals_zlab[128];
    Float_t xtals_cc[128];
    Float_t xtals_edop[128];
    Float_t xtals_edopMaxInt[128];
    Float_t xtals_edopSeg[128];
    Float_t xtals_edopXtal[128];
    Int_t xtals_crystalNum[128];
    Int_t xtals_quadNum[128];
    Float_t xtals_t0[128];
    Float_t xtals_t0Q2[128];
    Float_t xtals_t0NQ2[128];
    Long64_t xtals_timestamp[128];
    Int_t gammasMul;
    Float_t gammas_cc[64];
    Float_t gammas_xlab[64];
    Float_t gammas_ylab[64];
    Float_t gammas_zlab[64];
    Long64_t gammas_timestamp[64];


};

#endif
