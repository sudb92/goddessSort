#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <cassert>
#include <string>

typedef struct fileListStruct {
    std::string pathToFolder;
    std::string outputPath;
    std::string ldfPath;
    std::string rootPath;
    std::string runNumber;
    std::string preCutPath;
    std::string cutPath;
    bool copyCuts;
} fileListStruct;

// Detector structures

typedef struct BB10Hit {
    int channel;
    int detector;
    int strip;
    int adc;
} BB10Hit;

typedef struct BB10Detector {
    int channel;
    int detector;
    int strip;
    int adc;
    float energy;
} BB10Detector;

typedef struct QQQ5Ring {
    int channel;
    int detector;
    int ring;
    int adc;
} QQQ5Ring;

typedef struct QQQ5Sector {
    int channel;
    int detector;
    int sector;
    int adc;
} QQQ5Sector;

typedef struct QQQ5Detector {
    bool upstream;
    int detector;
    int ring;
    int ringChannel;
    int sector;
    int sectorChannel;
    int ringEnergyADC;
    float ringEnergy;
    int sectorEnergyADC;
    float sectorEnergy;
    float angle;
} QQQ5Detector;

typedef struct SuperX3Back {
    int channel;
    int detector;
    int sector;
    int adc;
} SuperX3Back;

typedef struct SuperX3Front {
    int channel;
    int detector;
    int strip;
    bool leftSide;
    int adc;
} SuperX3Front;

typedef struct SuperX3FrontMatched {
    int detector;
    int strip;
    int stripLeftChannel;
    int stripLeftADC;
    int stripRightChannel;
    int stripRightADC;
} SuperX3FrontMatched;

typedef struct SuperX3Detector {
    bool upstream;
    int detector;
    int sector;
    int sectorChannel;
    int sectorADC;
    float sectorEnergy;
    int strip;
    int stripLeftChannel;
    int stripLeftADC;
    int stripRightChannel;
    int stripRightADC;
    float stripEnergy;
} SuperX3Detector;

typedef struct ICTracking{
    bool x;
    int wire;
    int adc;
} ICTracking;

typedef struct ICTrackingDetector {
    int wireX;
    int wireY;
    float positionX;
    float positionY;
    float positionWeightedX;
    float positionWeightedY;
} ICTrackingDetector;

#endif