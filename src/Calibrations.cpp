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

    // Read and parse config.json
    Json::Value config;
    std::ifstream config_stream("config.json");
    ASSERT_WITH_MESSAGE(config_stream.is_open(),
                        "Could not find 'config.json'\n");
    config_stream >> config;
    config_stream.close();

    BB10Threshold = config["BB10Threshold"].asInt(); // Original Value: 500
    QQQThreshold = config["QQQThreshold"].asInt(); // Original Value: 400
    SX3Threshold = config["SX3Threshold"].asInt(); // Original Value: 500
    ICTrackingThreshold = config["ICTrackingThreshold"].asInt(); // Original Value: 300
}

void Calibrations::ReadQQQ5DownCalibrations() {
    std::cout << PrintOutput("\t\tReading QQQ5DownCalibrations.dat", "blue") << std::endl;
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
    std::cout << PrintOutput("\t\tReading QQQ5DownPedestals.dat", "blue") << std::endl;
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
    std::cout << PrintOutput("\t\tReading QQQ5UpCalibrations.dat", "blue") << std::endl;
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
    std::cout << PrintOutput("\t\tReading QQQ5UpPedestals.dat", "blue") << std::endl;
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
    std::cout << PrintOutput("\t\tReading QQQ5Angles.dat", "blue") << std::endl;
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
    std::cout << PrintOutput("\t\tReading SuperX3UpCalibrations.dat", "blue") << std::endl;
    std::ifstream in("SuperX3UpCalibrations.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open SuperX3UpCalibrations.dat");

    int det, strip, back;
    double intercept, slope;

    while(in >> det >> strip >> back >> intercept >> slope) {
        fSuperX3UpCalibrations[det][strip][back] = std::make_pair(intercept, slope);
    }

    in.close();
}

void Calibrations::ReadSuperX3UpPedestals() {
    std::cout << PrintOutput("\t\tReading SuperX3UpPedestals.dat", "blue") << std::endl;
    std::ifstream in("SuperX3UpPedestals.dat");
    ASSERT_WITH_MESSAGE(in.is_open(), "Could not open SuperX3UpPedestals.dat");

    int det, something;
    double pedestal;

    while(in >> det >> something >> pedestal) {
        fSuperX3UpPedestals[det][something] = pedestal;
    }

    in.close();
}