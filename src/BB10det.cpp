#include "BB10det.h"

//Constructor
BB10det::BB10det() {
    this->ResetAll();
}

//Setters
void BB10det::SetRawEnergy(float Value){
    RawEnergy.push_back(Value);
}

void BB10det::SetEnergy(float Value){
    Energy.push_back(Value);
}

void BB10det::SetStrip(int Value){
    Strip.push_back(Value);
}

void BB10det::SetFrontHits(int Value){
    FrontHits.push_back(Value);
}

void BB10det::SetMult(int Value){
    Mult=Value;
}

//Getters
float BB10det::GetRawEnergy(int Index){
    return RawEnergy[Index];
}

float BB10det::GetEnergy(int Index){
    return Energy[Index];
}

int BB10det::GetStrip(int Index){
    return Strip[Index];
}

int BB10det::GetFrontHits(int Index){
    return FrontHits[Index];
}

int BB10det::GetMult(){
    return Mult;
}

//Other
void BB10det::IncrementMult(){
    Mult++;
}

void BB10det::ResetAll(){
    RawEnergy.clear();
    Energy.clear();
    Strip.clear();
    Mult=0;
}

