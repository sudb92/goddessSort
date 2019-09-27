#include "ProcessIC.h"

void SortICTrack(std::vector<ICTracking>& IC_) {
    std::sort(IC_.begin(), IC_.end(), pred);
}

std::vector<ICTrackingDetector> ProcessIC(std::vector<ICTracking> ICx_, std::vector<ICTracking> ICy_) {
    std::vector<ICTrackingDetector> outputIC;

    SortICTrack(ICx_);
    SortICTrack(ICy_);

    // Gain match here

    // Go through x wires
    // Assuming 2 mm spacing between wires
    int wireX = ICx_[0].wire;
    float positionX = 15.5*2. - static_cast<float>(wireX)*2.;
    float positionWeightedX = positionX;
    bool doubleHitX = false;
    if(ICx_.size() > 1) {
        if(abs(wireX - ICx_[1].wire) == 1) {
            doubleHitX = true;
        }
    }
    if(doubleHitX) {
        float secondPositionX = 15.5*2. - static_cast<float>(ICx_[1].wire)*2.;
        positionWeightedX = (positionX*ICx_[0].adc + secondPositionX*ICx_[1].adc)/(ICx_[0].adc + ICx_[1].adc);
    }

    // Go through y wires
    // Assuming 2 mm spacing between wires
    int wireY = ICy_[0].wire;
    float positionY = static_cast<float>(wireY)*2. - 15.5*2.;
    float positionWeightedY = positionY;
    bool doubleHitY = false;
    if(ICy_.size() > 1) {
        if(abs(wireY - ICy_[1].wire) == 1) {
            doubleHitY = true;
        }
    }
    if(doubleHitY) {
        float secondPositionY = static_cast<float>(ICy_[1].wire)*2. - 15.5*2.;
        positionWeightedY = (positionY*ICy_[0].adc + secondPositionY*ICy_[1].adc)/(ICy_[0].adc + ICy_[1].adc);
    }

    ICTrackingDetector hit = {wireX, wireY, positionX, positionY, positionWeightedX, positionWeightedY};
    outputIC.push_back(hit);

    // Why did I think to put this as a vector? Maybe change later.
    return outputIC;
}