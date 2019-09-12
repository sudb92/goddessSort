#ifndef UNPACK_H
#define UNPACK_H

#include "ProcessBB10.h"
#include "ProcessQQQ5.h"
#include "ProcessSX3.h"
#include "RunList.h"
//#include "SortingStructures.h"
#include "TypeDef.h"
#include "Utilities.h"

#include <bitset>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
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

class Unpack {
public:
    Unpack();

private:

    ////////////////////
    // Tree variables //
    ////////////////////

    // BB10 Detectors
    int fBB10Mul;
    int fBB10Det[256];
    int fBB10Strip[256];
    int fBB10Channel[256];
    int fBB10ADC[256];
    float fBB10Energy[256];

    // QQQ5 Detectors
    int fQQQ5Mul;
    bool fQQQ5Upstream[256];
    int fQQQ5Det[256];
    int fQQQ5Ring[256];
    int fQQQ5RingChannel[256];
    int fQQQ5Sector[256];
    int fQQQ5SectorChannel[256];
    int fQQQ5RingADC[256];
    float fQQQ5RingEnergy[256];
    int fQQQ5SectorADC[256];
    float fQQQ5SectorEnergy[256];
    float fQQQ5Angle[256];

    // Super X3 Detectors
    int fSX3Mul;
    bool fSX3Upstream[256];
    int fSX3Det[256];
    int fSX3Sector[256];
    int fSX3SectorChannel[256];
    int fSX3SectorADC[256];
    float fSX3SectorEnergy[256];
    int fSX3Strip[256];
    int fSX3StripLeftChannel[256];
    int fSX3StripRightChannel[256];
    int fSX3StripLeftADC[256];
    int fSX3StripRightADC[256];
    float fSX3StripEnergy[256];

    int fICdE;
    int fICE;
    int fTDC;

    unsigned long long fTimeStamp;

};

#endif
