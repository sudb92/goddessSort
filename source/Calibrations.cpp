#include "Calibrations.h"

Calibrations* Calibrations::fInstance = NULL;

Calibrations* Calibrations::Instance() {
    if(!fInstance) {
        fInstance = new Calibrations();
    }
    return fInstance;
}

Calibrations::Calibrations() {
    ReadQQQ5DownCalibrations();
    ReadQQQ5DownPedestals();
    ReadQQQ5UpCalibrations();
    ReadQQQ5UpPedestals();
    ReadQQQ5Angles();

    ReadSuperX3UpCalibrations();
    ReadSuperX3UpPedestals();
}

void Calibrations::ReadQQQ5DownCalibrations() {
    std::ifstream in("QQQ5DownCalibrations.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open QQQ5DownCalibrations.dat");

    int detector, ring;
    double intercept, slope;

    while(in >> detector >> ring >> intercept >> slope) {
        fQQQ5DownCalibrations[detector][ring] = std::make_pair(intercept, slope);
    }

    in.close();
}

void Calibrations::ReadQQQ5DownPedestals() {
    std::ifstream in("QQQ5DownPedestals.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open QQQ5DownPedestals.dat");

    int ring;
    double pedestal;

    while(in >> ring >> pedestal) {
        fQQQ5DownPedestals[ring] = pedestal;
    }

    in.close();
}

void Calibrations::ReadQQQ5UpCalibrations() {
    std::ifstream in("QQQ5UpCalibrations.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open QQQ5UpCalibrations.dat");

    int detector, ring;
    double intercept, slope;

    while(in >> detector >> ring >> intercept >> slope) {
        fQQQ5UpCalibrations[detector][ring] = std::make_pair(intercept, slope);
    }

    in.close();
}

void Calibrations::ReadQQQ5UpPedestals() {
    std::ifstream in("QQQ5UpPedestals.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open QQQ5UpPedestals.dat");

    int ring;
    double pedestal;

    while(in >> ring >> pedestal) {
        fQQQ5UpPedestals[ring] = pedestal;
    }

    in.close();
}

void Calibrations::ReadQQQ5Angles() {
    std::ifstream in("QQQ5Angles.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open QQQ5Angles.dat");

    int ring;
    double angle;

    while(in >> ring >> angle) {
        fQQQ5Angles[ring] = angle;
    }

    in.close();
}

void Calibrations::ReadSuperX3UpCalibrations() {
    std::ifstream in("SuperX3Calibrations.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open SuperX3UpCalibrations.dat");

    int det, strip, back;
    double intercept, slope;

    while(in >> det >> strip >> back >> intercept >> slope) {
        fSuperX3UpCalibrations[det][strip][back] = std::make_pair(intercept, slope);
    }

    in.close();
}

void Calibrations::ReadSuperX3UpPedestals() {
    std::ifstream in("SuperX3UpPedestals.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open SuperX3UpPedestals.dat");

    int det, something;
    double pedestal;

    while(in >> det >> something >> pedestal) {
        fSuperX3UpPedestals[det][something] = pedestal;
    }

    in.close();
}