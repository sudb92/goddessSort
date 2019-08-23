#ifndef Sort_h
#define Sort_h

#include "BB10det.h"
#include "IChit.h"
#include "ParticleHit.h"
#include "ProcessIC.h"
#include "ProcessQQQ5.h"
#include "ProcessSX3.h"
#include "SX3det.h"
#include "TDChit.h"
#include "TypeDef.h"
#include "Utility.h"

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

extern QQQ5ParticleIn Qu1in;
extern QQQ5ParticleIn Qu2in;
extern QQQ5ParticleIn Qu3in;
extern QQQ5ParticleIn Qu4in;

extern QQQ5ParticleIn Qd1in;
extern QQQ5ParticleIn Qd2in;
extern QQQ5ParticleIn Qd3in;

extern QQQ5ParticleIn QuIn[4];
extern QQQ5ParticleIn QdIn[3];

extern int ICdEin;
extern int ICEin;
extern int TDCin;

extern float BeamEnergy,Ma,Mb,Mx,Qgs;
extern float My;

#endif
