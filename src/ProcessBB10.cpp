#include "ProcessBB10.h"

std::vector<BB10Detector> ProcessBB10(std::vector<BB10Hit> BB10Hit_) {
    std::vector<BB10Detector> outputBB10_;

    for(auto BB10: BB10Hit_) {
        float energy = 0.;
        BB10Detector hit = {BB10.channel, BB10.detector, BB10.strip, BB10.adc, energy};
        outputBB10_.push_back(hit);
    }

    return outputBB10_;
}