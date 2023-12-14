#include "ProcessSX3.h"

SX3DetRaw ProcessSX3(std::vector<SuperX3Front> front_, std::vector<SuperX3Back> back_, bool up) {

    int LeftMul=0;
    int RightMul=0;
    int BackMul=0;
    
    SX3DetRaw outputDetRaw;
    
    for(auto front: front_) {
        if (front.leftSide) {
            outputDetRaw.DetLeft[LeftMul] = front.detector;
            outputDetRaw.LeftStrip[LeftMul] = front.strip;
            outputDetRaw.LeftChannel[LeftMul] = front.channel;
            outputDetRaw.LeftADC[LeftMul] = front.adc;
            outputDetRaw.DetLeftMul[front.detector]++;
            LeftMul++;
        }
        else {
            outputDetRaw.DetRight[RightMul] = front.detector;
            outputDetRaw.RightStrip[RightMul] = front.strip;
            outputDetRaw.RightChannel[RightMul] = front.channel;
            outputDetRaw.RightADC[RightMul] = front.adc;
            outputDetRaw.DetRightMul[front.detector]++;
            RightMul++;
        }
    }
    
    for(auto back: back_) {
        outputDetRaw.DetBack[BackMul] = back.detector;
        outputDetRaw.BackSector[BackMul] = back.sector;
        outputDetRaw.BackChannel[BackMul] = back.channel;
        outputDetRaw.BackADC[BackMul] = back.adc;
        outputDetRaw.DetBackMul[back.detector]++;
        BackMul++;
    }
    
    outputDetRaw.LeftMul = LeftMul;
    outputDetRaw.RightMul = RightMul;
    outputDetRaw.BackMul = BackMul;
    
    
    return outputDetRaw;
    
}
