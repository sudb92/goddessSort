#include "SX3det.h"

//Constructor
SX3det::SX3det() {
    ResetAll();
}

//Setters
void SX3det::SetRawLeft(int Value){
    RawLeft.push_back(Value);
}

void SX3det::SetRawRight(int Value){
    RawRight.push_back(Value);
}

void SX3det::SetRawBackEnergy(int Value){
    RawBackEnergy.push_back(Value);
}

void SX3det::SetLeftHits(int Value){
    LeftHits.push_back(Value);
}

void SX3det::SetRightHits(int Value){
    RightHits.push_back(Value);
}

void SX3det::SetBackHits(int Value){
    BackHits.push_back(Value);
}

void SX3det::SetLeft(float Value){
    Left.push_back(Value);
}

void SX3det::SetRight(float Value){
    Right.push_back(Value);
}

void SX3det::SetRawEnergy(float Value){
    RawEnergy.push_back(Value);
}

void SX3det::SetEnergy(float Value){
    Energy.push_back(Value);
}

void SX3det::SetStrip(int Value){
    Strip.push_back(Value);
}

void SX3det::SetBackEnergy(float Value){
    BackEnergy.push_back(Value);
}

void SX3det::SetBack(int Value){
    Back.push_back(Value);
}

void SX3det::SetPos(float Value){
    Pos.push_back(Value);
}

void SX3det::SetMult(int Value){
    Mult=Value;
}

void SX3det::SetLmult(int Value){
    Lmult=Value;
}

void SX3det::SetRmult(int Value){
    Rmult=Value;
}

void SX3det::SetBmult(int Value){
    Bmult=Value;
}

//Getters
int SX3det::GetRawLeft(int Index){
    return RawLeft[Index];
}

int SX3det::GetRawRight(int Index){
    return RawRight[Index];
}

int SX3det::GetRawBackEnergy(int Index){
    return RawBackEnergy[Index];
}

int SX3det::GetLeftHits(int Index){
    return LeftHits[Index];
}

int SX3det::GetRightHits(int Index){
    return RightHits[Index];
}

int SX3det::GetBackHits(int Index){
    return BackHits[Index];
}

float SX3det::GetLeft(int Index){
    return Left[Index];
}

float SX3det::GetRight(int Index){
    return Right[Index];
}

float SX3det::GetRawEnergy(int Index){
    return RawEnergy[Index];
}

float SX3det::GetEnergy(int Index){
    return Energy[Index];
}

int SX3det::GetStrip(int Index){
    return Strip[Index];
}

float SX3det::GetBackEnergy(int Index){
    return BackEnergy[Index];
}

int SX3det::GetBack(int Index){
    return Back[Index];
}

float SX3det::GetPos(int Index){
    return Pos[Index];
}

int SX3det::GetMult(){
    return Mult;
}

int SX3det::GetLmult(){
    return Lmult;
}

int SX3det::GetRmult(){
    return Rmult;
}

int SX3det::GetBmult(){
    return Bmult;
}

//Other
void SX3det::IncrementMult(){
    Mult++;
}

void SX3det::IncrementLmult(){
    Lmult++;
}

void SX3det::IncrementRmult(){
    Rmult++;
}

void SX3det::IncrementBmult(){
    Bmult++;
}

void SX3det::ResetAll(){
    RawLeft.clear();
    RawRight.clear();
    RawBackEnergy.clear();
    LeftHits.clear();
    RightHits.clear();
    BackHits.clear();
    Left.clear();
    Right.clear();
    RawEnergy.clear();
    Energy.clear();
    Strip.clear();
    BackEnergy.clear();
    Back.clear();
    Pos.clear();
    Mult=0;
    Lmult=0;
    Rmult=0;
    Bmult=0;
}