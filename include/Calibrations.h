#ifndef CALIBRATIONS_H
#define CALIBRATIONS_H

#include "TypeDef.h"
#include "Utilities.h"

#include <cassert>
#include <fstream>
#include <map>
#include <utility>

class Calibrations {
public:
    Calibrations();
    static Calibrations* Instance();

    std::map<int, std::map<int, std::pair<float, float> > > GetQQQ5DownCalibrations() {return fQQQ5DownCalibrations;}
    std::map<int, std::map<int, std::pair<float, float> > > GetQQQ5UpCalibrations() {return fQQQ5UpCalibrations;}
    std::map<int, float> GetQQQ5Angles() {return fQQQ5Angles;}

    std::map<int, std::map<int, std::map<int, std::pair<float, float> > > > GetSuperX3Calibrations() {return fSuperX3UpCalibrations;}
    std::map<int, std::map<int, float> > GetSuperX3Pedestals() {return fSuperX3UpPedestals;}

private:
    static Calibrations* fInstance;

    void ReadQQQ5DownCalibrations();
    void ReadQQQ5DownPedestals();
    void ReadQQQ5UpCalibrations();
    void ReadQQQ5UpPedestals();
    void ReadQQQ5Angles();

    void ReadSuperX3UpCalibrations();
    void ReadSuperX3UpPedestals();

    std::map<int, std::map<int, std::pair<float, float> > > fQQQ5DownCalibrations;
    std::map<int, float> fQQQ5DownPedestals;
    std::map<int, std::map<int, std::pair<float, float> > > fQQQ5UpCalibrations;
    std::map<int, float> fQQQ5UpPedestals;

    std::map<int, float> fQQQ5Angles;

    std::map<int, std::map<int, std::map<int, std::pair<float, float> > > > fSuperX3UpCalibrations;
    std::map<int, std::map<int, float> > fSuperX3UpPedestals;
};

#endif
