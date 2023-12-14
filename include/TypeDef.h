#ifndef TypeDef_h
#define TypeDef_h
#include <cassert>
#include <string>
#include "Rtypes.h"

typedef struct fileListStruct {
    std::string pathToFolder;
    std::string outputPath;
    std::string ldfPath;
    std::string rootPathRaw;
    std::string runNumber;
    std::string preCutPath;
    std::string cutPath;
    std::string globalPath;
    std::string gretinaPath;
    std::string combinedPath;
    bool copyCuts;
    bool unpackORRUBA;
    bool unpackGRETINA;
    bool withTracked;
    bool mergeTrees;
} fileListStruct;

// Detector structures

typedef struct BB10Hit {
    int channel;
    int detector;
    int strip;
    int adc;
} BB10Hit;

typedef struct BB10DetRaw {
    int Mul;
    int DetMul[12]={};
    int Det[256];
    int Strip[256];
    int Channel[256];
    int ADC[256];
} BB10DetRaw;

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

typedef struct QQQ5DetRaw {
    bool upstream;
    bool dE;

    int RingMul;
    int DetRingMul[4]={}; // The number of rings hit in each detector
    int DetRing[128]; // The detector for each ring hit in event (ordered by detector)
    int Ring[128]; // The ring number for each ring hit in event (ordered by detector)
    int RingChannel[128]; // The channel number for each ring hit in event (ordered by detector)
    int RingADC[128]; // ADC value for each ring hit in event (ordered by detector)

    int SectorMul;
    int DetSectorMul[4]={};
    int DetSector[128];
    int Sector[128];
    int SectorChannel[128];
    int SectorADC[128];
} QQQ5DetRaw;

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

typedef struct SX3DetRaw {
    bool upstream;
    int LeftMul;
    int RightMul;
    int DetLeftMul[12]={}; // Left multiplicity for each detector
    int DetRightMul[12]={}; // Right multiplicity for each detector
    int DetLeft[128]; // Detector for each left hit
    int DetRight[128]; // Detector for each right hit
    int LeftStrip[128]; // Strip for each left hit
    int RightStrip[128]; // Strip for each right hit
    int LeftChannel[128]; // Channel for each left hit
    int RightChannel[128];
    int LeftADC[128]; // ADC for each right hit
    int RightADC[128];

    int BackMul;
    int DetBackMul[12]={}; // Back multiplicity for each detector
    int DetBack[128]; // Detector for each back hit
    int BackSector[128]; // Sector for each back hit
    int BackChannel[128]; // Channel for each back hit
    int BackADC[128]; // ADC for each back hit
} SX3DetRaw;



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

typedef struct matchedEvents {
    size_t orrubaNumber;
    size_t gretinaNumber;
    Long64_t orrubaTimeStamp;
    Long64_t gretinaTimeStamp;
} matchedEvents;

typedef struct out4Mario {
    float ccEnergy;
    float segEnergy[36];
    float pad;
    short wf[37][300];
} out4Mario;

typedef struct AllFolderPath {
    std::string runName;
    int run;
} AllFolderPath;

#endif // TypeDef_h
