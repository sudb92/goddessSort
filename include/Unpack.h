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

class Unpack {
public:
    Unpack();

private:
    void Combine(fileListStruct run);
    void CombineTrees(TTree* orruba, TTree* gretina);

    void CombineReader(fileListStruct run);
};

#endif
