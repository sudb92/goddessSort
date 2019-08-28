#include "ProcessQQQ5.h"

std::vector<QQQ5Detector> ProcessQQQ5(std::vector<QQQ5Ring> ring_, std::vector<QQQ5Sector> sector_, bool up) {
    Calibrations* calibrations = Calibrations::Instance();
    auto QdGains = calibrations->GetQQQ5DownCalibrations();
    auto QuGains = calibrations->GetQQQ5UpCalibrations();
    auto QQQAngles = calibrations->GetQQQ5Angles();

    std::map<int, std::map<int, std::pair<float, float> > > QGains;
    QGains = up ? QuGains : QdGains;

    std::vector<QQQ5Detector> outputQQQ5_;

    // Remove duplicates in the data stream (based on channel number)
    // No idea why this is happening in the sectors
    RemoveQQQ5RingDuplicates(ring_);
    RemoveQQQ5SectorDuplicates(sector_);

    for(auto ring: ring_) {
        for(auto sector: sector_) {
            if(ring.detector == sector.detector) {
                int detector = ring.detector;
                int ringNumber = ring.ring;
                int ringChannel = ring.channel;
                int sectorNumber = sector.sector;
                int sectorChannel = sector.channel;
                int ringADC = ring.adc;
                int sectorADC = sector.adc;

                float ringEnergy = QGains[detector][ringNumber].first + static_cast<float>(ringADC)*QGains[detector][ringNumber].second;
                float sectorEnergy = QGains[detector][sectorNumber + 32].first + static_cast<float>(sectorADC)*QGains[detector][sectorNumber + 32].second;

                float angle = QQQAngles[ringNumber];
                angle = up ? angle : 180 - angle;

                QQQ5Detector hit = {up, detector, ringNumber, ringChannel, sectorNumber, sectorChannel, ringADC, ringEnergy, sectorADC, sectorEnergy, angle};
                outputQQQ5_.push_back(hit);
            }
        }
    }

    return outputQQQ5_;
}

void RemoveQQQ5RingDuplicates(std::vector<QQQ5Ring>& ring_) {
    std::sort(ring_.begin(), ring_.end(), predRing);
    auto last = std::unique(ring_.begin(), ring_.end(), compRing);
    ring_.erase(last, ring_.end());
}

void RemoveQQQ5SectorDuplicates(std::vector<QQQ5Sector>& sector_) {
    std::sort(sector_.begin(), sector_.end(), predSector);
    auto last = std::unique(sector_.begin(), sector_.end(), compSector);
    sector_.erase(last, sector_.end());
}
