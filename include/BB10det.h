#ifndef BB10det_h
#define BB10det_h

#include <vector>

class BB10det {

public:
    //constructor
    BB10det();

    //Setters
    void SetRawEnergy(float Value);
    void SetEnergy(float Value);
    void SetStrip(int Value);
    void SetFrontHits(int Value);
    void SetMult(int Value);


    //Getters
    float GetRawEnergy(int Index);
    float GetEnergy(int Index);
    int GetStrip(int Index);
    int GetFrontHits(int Index);
    int GetMult();

    //Other
    void IncrementMult();
    void ResetAll();

private:
    std::vector<float> RawEnergy;
    std::vector<float> Energy;
    std::vector<int> Strip;
    std::vector<int> FrontHits;

    int Mult;
};

#endif
