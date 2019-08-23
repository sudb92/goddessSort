#include "IChit.h"

//Constructor
IChit::IChit() {}

//Setters
void IChit::SetdE(float fdE){
    dE=fdE;
}
void IChit::SetE(float fE){
    E=fE;
}

//Getters
float IChit::GetdE(){
    return dE;
}
float IChit::GetE(){
    return E;
}

//Other functions
void IChit::ResetAll(){
    dE=0;
    E=0;
}