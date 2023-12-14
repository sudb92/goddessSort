#ifndef Calibrations_h
#define Calibrations_h

#include "json/json.h"
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



    int GetBB10Threshold() {return BB10Threshold;}
    int GetQQQThreshold() {return QQQThreshold;}
    int GetSX3Threshold() {return SX3Threshold;}
    int GetICTrackingThreshold() {return ICTrackingThreshold;}

private:
    static Calibrations* fInstance;

    int BB10Threshold;
    int QQQThreshold;
    int SX3Threshold;
    int ICTrackingThreshold;

};

#endif // Calibrations_h
