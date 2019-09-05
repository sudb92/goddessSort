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

#endif