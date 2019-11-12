#ifndef UnpackGRETINA_h
#define UnpackGRETINA_h

#include "TypeDef.h"
#include "UnpackGRETINARaw.h"
#include "Utilities.h"

class UnpackGRETINA {
public:
    UnpackGRETINA() {};
    UnpackGRETINA(fileListStruct run);
    ~UnpackGRETINA() {};
    bool GetCompleted() {return completed;}

    // TTree* GetTree() {return tree;}

private:
    bool completed = false;

};

#endif // UnpackGRETINA_h