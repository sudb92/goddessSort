#include "ParticleHit.h"

//Constructor
ParticleHit::ParticleHit() { }

//Setters
void ParticleHit::SetRawEnergy(int fValue){
    RawEnergy.push_back(fValue);
}

void ParticleHit::SetEnergy(float fValue){
    Energy.push_back(fValue);
}

void ParticleHit::SetRawBackEnergy(int fValue){
    RawBackEnergy.push_back(fValue);
}

void ParticleHit::SetBackEnergy(float fValue){
    BackEnergy.push_back(fValue);
}

void ParticleHit::SetTime(float fTime){
    Time.push_back(fTime);
}
void ParticleHit::SetRing(int fRing){
    Ring.push_back(fRing);
}
void ParticleHit::SetSector(int fSector){
    Sector.push_back(fSector);
}
void ParticleHit::SetRmult(int fRmult){
    Rmult=fRmult;
}
void ParticleHit::SetSmult(int fSmult){
    Smult=fSmult;
}

void ParticleHit::SetPIDlinear(float Value){
    PIDlinear=Value;
}
void ParticleHit::SetAngle(float fAngle){
    Angle.push_back(fAngle);
}

void ParticleHit::SetEx(float fEx){
    Ex.push_back(fEx);
}
void ParticleHit::SetRecoilAngle(float fRecoilAngle){
    RecoilAngle=fRecoilAngle;
}

//Getters
float ParticleHit::GetEnergy(int Index){
    return Energy[Index];
}
float ParticleHit::GetRawEnergy(int Index){
    return RawEnergy[Index];
}
float ParticleHit::GetTime(int Index){
    return Time[Index];
}
int ParticleHit::GetRing(int Index){
    return Ring[Index];
}
int ParticleHit::GetSector(int Index){
    return Sector[Index];
}
int ParticleHit::GetRmult(){
    return Rmult;
}
int ParticleHit::GetSmult(){
    return Smult;
}

float ParticleHit::GetPIDlinear(){
    return PIDlinear;
}
float ParticleHit::GetAngle(int Index){
    return Angle[Index];
}

float ParticleHit::GetEx(int Index){
    return Ex[Index];
}
float ParticleHit::GetRecoilAngle(){
    return RecoilAngle;
}

//Other functions
void ParticleHit::IncrementRmult(){
    Rmult++;
}
void ParticleHit::IncrementSmult(){
    Smult++;
}
void ParticleHit::ResetAll(){

    RawEnergy.clear();
    Energy.clear();

    BackEnergy.clear();
    RawBackEnergy.clear();

    Time.clear();
    Ring.clear();
    Sector.clear();
    Rmult=0;
    Smult=0;
    PIDlinear=0;
    Angle.clear();

    Ex.clear();
    RecoilAngle=0;
}



