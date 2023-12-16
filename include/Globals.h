#ifndef Globals_h
#define Globals_h

#include "colors.h"
#include "GRETINA.h"
#include "GRETINAWavefunction.h"
#include "Track.h"
#include "S800Parameters.h"
#include "S800Definitions.h"

#include <TTree.h>

/*************************************************/
/****            Global variables             ****/
/*************************************************/

/*------ GRETINA DATA STRUCTURES ------*/

extern globalHeader gHeader;
extern globalHeader gHeaderOUT;

/* Waveforms...easier as globals */
extern GRETINAWF *gWf;

extern Float_t WFbaseline;
extern Float_t WFrunningBaseline;
extern Int_t WFid;
extern Float_t WFenergy;

extern GRETINA *gret;

extern Track *track;

/*------ ROOT TREES ------*/
extern TTree *teb;
extern TTree *wave;
extern TTree *scaler;

extern S800Full *s800;
extern S800Scaler *s800Scaler;

#endif // Globals_h
