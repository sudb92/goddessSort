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

    std::map<int, std::map<int, std::pair<double, double> > > GetQQQ5DownCalibrations() {return fQQQ5DownCalibrations;}
    std::map<int, std::map<int, std::pair<double, double> > > GetQQQ5UpCalibrations() {return fQQQ5UpCalibrations;}
    std::map<int, double> GetQQQ5Angles() {return fQQQ5Angles;}

    std::map<int, std::map<int, std::map<int, std::pair<double, double> > > > GetSuperX3Calibrations() {return fSuperX3UpCalibrations;}
    std::map<int, std::map<int, double> > GetSuperX3Pedestals() {return fSuperX3UpPedestals;}

private:
    static Calibrations* fInstance;

    void ReadQQQ5DownCalibrations();
    void ReadQQQ5DownPedestals();
    void ReadQQQ5UpCalibrations();
    void ReadQQQ5UpPedestals();
    void ReadQQQ5Angles();

    void ReadSuperX3UpCalibrations();
    void ReadSuperX3UpPedestals();

    std::map<int, std::map<int, std::pair<double, double> > > fQQQ5DownCalibrations;
    std::map<int, double> fQQQ5DownPedestals;
    std::map<int, std::map<int, std::pair<double, double> > > fQQQ5UpCalibrations;
    std::map<int, double> fQQQ5UpPedestals;

    std::map<int, double> fQQQ5Angles;

    std::map<int, std::map<int, std::map<int, std::pair<double, double> > > > fSuperX3UpCalibrations;
    std::map<int, std::map<int, double> > fSuperX3UpPedestals;
};

#endif
