#ifndef PARTICLEHIT_H
#define PARTICLEHIT_H

#include <vector>

#include <TObject.h>

class ParticleHit {

public:
    //Constructor
    ParticleHit();

    //Setters
    void SetRawEnergy(int fValue);
    void SetEnergy(float fValue);

    void SetRawBackEnergy(int fValue);
    void SetBackEnergy(float fValue);

    void SetTime(float fTime);
    void SetRing(int fRing);
    void SetSector(int fSector);
    void SetRmult(int fRmult);
    void SetSmult(int fSmult);
    void SetPIDlinear(float Value);
    void SetAngle(float fAngle);

    void SetEx(float fEx);
    void SetRecoilAngle(float fRecoilAngle);

    //Getters
    float GetEnergy(int Index);
    float GetRawEnergy(int Index);
    float GetTime(int Index);
    int GetRing(int Index);
    int GetSector(int Index);
    int GetRmult();
    int GetSmult();
    float GetPIDlinear();
    float GetAngle(int Index);

    float GetEx(int Index);
    float GetRecoilAngle();

    //Other functions
    void IncrementRmult();
    void IncrementSmult();
    void ResetAll();

private:
    std::vector<int> RawEnergy;
    std::vector<float> Energy;

    std::vector<int> RawBackEnergy;
    std::vector<float> BackEnergy;

    std::vector<float> Time;
    std::vector<int> Ring;
    std::vector<int> Sector;

    int Rmult;
    int Smult;
    
    float PIDlinear;

    std::vector<float> Angle;
    std::vector<float> Ex;

    float RecoilAngle;
};

#endif
