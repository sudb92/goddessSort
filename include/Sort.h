#ifndef SORT_H
#define SORT_H

#include "BB10det.h"
#include "ProcessQQQ5.h"
#include "ProcessSX3.h"
#include "RunList.h"
#include "SX3det.h"
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

extern float BeamEnergy,Ma,Mb,Mx,Qgs;
extern float My;

class Sort {
public:
    Sort();

private:

    // Tree variables
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

    int fICdE;
    int fICE;
    int fTDC;

};

#endif
