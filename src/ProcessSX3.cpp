#include "ProcessSX3.h"

std::vector<SuperX3Detector> ProcessSX3(std::vector<SuperX3Back> back_, std::vector<SuperX3Front> front_, bool up) {
    std::vector<SuperX3Detector> outputSX3_;

    RemoveSX3BackDuplicates(back_);
    RemoveSX3FrontDuplicates(front_);

    // Match fronts
    std::vector<SuperX3FrontMatched> frontMatched_;
    size_t frontSize = front_.size();
    size_t i = 0;
    while(i < frontSize - 1) {
        if(front_[i + 1].channel - 1 == front_[i].channel && front_[i + 1].strip == front_[i].strip) {
            SuperX3Front left, right;
            if(front_[i].leftSide) {
                left = front_[i];
                right = front_[i + 1];
            }
            else {
                left = front_[i + 1];
                right = front_[i];
            }
            SuperX3FrontMatched hit = {left.detector, left.strip, left.channel, left.adc, right.channel, right.adc};
            frontMatched_.push_back(hit);
            i += 2;
        }
        else i++;
    }

    for(auto back: back_) {
        for(auto front: frontMatched_) {
            if(back.detector == front.detector) {
                float backEnergy = 0.;
                float frontEnergy = 0.;
                SuperX3Detector hit = {up, front.detector, back.sector, back.channel, back.adc, backEnergy, front.strip,
                                       front.stripLeftChannel, front.stripLeftADC, front.stripRightChannel, front.stripRightADC, frontEnergy};
                outputSX3_.push_back(hit);
            }
        }
    }

    return outputSX3_;
}

void RemoveSX3BackDuplicates(std::vector<SuperX3Back>& back_) {
    std::sort(back_.begin(), back_.end(), predBack);
    auto last = std::unique(back_.begin(), back_.end(), compBack);
    back_.erase(last, back_.end());
}

void RemoveSX3FrontDuplicates(std::vector<SuperX3Front>& front_) {
    std::sort(front_.begin(), front_.end(), predFront);
    auto last = std::unique(front_.begin(), front_.end(), compFront);
    front_.erase(last, front_.end());
}

//bool ProcessSX3(int Id, SX3det &SX3) {
//
//    Calibrations* calibrations = Calibrations::Instance();
//    auto SX3UpCalibrations = calibrations->GetSuperX3Calibrations();
//    auto SX3UpPeds = calibrations->GetSuperX3Pedestals();
//
//    for(int i = 0; i < SX3.GetLmult(); i++) {
//        for(int j = 0; j < SX3.GetRmult(); j++) {
//            if(SX3.GetLeftHits(i) == SX3.GetRightHits(j)) {
//                SX3.SetStrip(SX3.GetLeftHits(i));
//                SX3.SetLeft(SX3.GetRawLeft(i) - SX3UpPeds[Id - 1][SX3.GetLeftHits(i) * 2]);
//                SX3.SetRight((SX3.GetRawRight(j) - SX3UpPeds[Id - 1][(SX3.GetLeftHits(i) * 2) + 1]));
//                SX3.SetRawEnergy(SX3.GetRawLeft(i) + SX3.GetRawRight(j));
//                SX3.SetEnergy(SX3.GetRawLeft(i) + SX3.GetRawRight(j)); // Eventually add calibration here
//                SX3.SetPos(static_cast<float>((SX3.GetRight(SX3.GetMult()) - SX3.GetLeft(SX3.GetMult())) /
//                                 SX3.GetEnergy(SX3.GetMult())));
//                SX3.IncrementMult();
//            }
//        }
//    }
//
//    for (int i = 0; i < SX3.GetBmult(); i++) {
//        SX3.SetBackEnergy(SX3.GetRawBackEnergy(i));
//        SX3.SetBack(SX3.GetBackHits(i));
//    }
//
//    return true;
//}

//// I'm not sure that this is working correctly at the moment
//bool ApplyGainMatch(int Id, SX3det &SX3){
//
//    Calibrations* calibrations = Calibrations::Instance();
//    auto SX3UpCalibrations = calibrations->GetSuperX3Calibrations();
//    auto SX3UpPeds = calibrations->GetSuperX3Pedestals();
//
//	if(SX3.GetBmult() != SX3.GetMult()){
//		std::cout << "Mismatch front and back multiplicities :  f " <<SX3.GetMult()<<"  b "<< SX3.GetBmult() << std::endl;
//		return false;
//	}
//
//	for(int i=0; i<SX3.GetMult(); i++){
//		for(int j=0; j<SX3.GetBmult(); j++){
//			SX3.SetRight(SX3UpCalibrations[Id-1][SX3.GetStrip(i)][SX3.GetBack(j)].first + SX3.GetRight(i) * SX3UpCalibrations[Id-1][SX3.GetStrip(i)][SX3.GetBack(j)].second);
//		}
//	}
//
//	for(int i=0; i<SX3.GetMult(); i++){
//		SX3.SetPos( (SX3.GetRight(i)-SX3.GetLeft(i))/(SX3.GetEnergy(i)) );
//	}
//
//	return true;
//}



