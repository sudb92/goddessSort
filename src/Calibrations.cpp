#include "Calibrations.h"

Calibrations* Calibrations::fInstance = NULL;

Calibrations* Calibrations::Instance() {
    if(!fInstance) {
        fInstance = new Calibrations();
    }
    return fInstance;
}

Calibrations::Calibrations() {

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

