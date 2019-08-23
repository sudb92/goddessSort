#ifndef IChit_h
#define IChit_h

#include <TObject.h>

class IChit {

public:
    //Constructor
    IChit();

    //Setters
    void SetdE(float fdE);
    void SetE(float fE);

    //Getters
    float GetdE();
    float GetE();

    //Other functions
    void ResetAll();

private:
    float dE;
    float E;
};

#endif
