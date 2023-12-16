#include "Globals.h"

/*************************************************/
/****            Global variables             ****/
/*************************************************/

/*------ GRETINA DATA STRUCTURES ------*/

globalHeader gHeader;
globalHeader gHeaderOUT;

/* Waveforms...easier as globals */
GRETINAWF *gWf;

Float_t WFbaseline;
Float_t WFrunningBaseline;
Int_t WFid;
Float_t WFenergy;

GRETINA *gret;

Track *track;

/*------ ROOT TREES ------*/
TTree *teb;
TTree *wave;
TTree *scaler;

S800Full *s800;
S800Scaler *s800Scaler;
