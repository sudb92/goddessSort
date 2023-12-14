#include "ProcessBB10.h"

BB10DetRaw ProcessBB10(std::vector<BB10Hit> BB10Hit_) {
    
    int Mul=0;
    
    BB10DetRaw outputDetRaw;
    
    for(auto BB10: BB10Hit_) {
        outputDetRaw.Det[Mul] = BB10.detector;
        outputDetRaw.Strip[Mul] = BB10.strip;
        outputDetRaw.Channel[Mul] = BB10.channel;
        outputDetRaw.ADC[Mul] = BB10.adc;
        outputDetRaw.DetMul[BB10.detector]++;
        Mul++;
    }
    outputDetRaw.Mul = Mul;
    
    return outputDetRaw;
}
