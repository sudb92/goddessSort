#include "ProcessQQQ5.h"

QQQ5DetRaw ProcessQQQ5(std::vector<QQQ5Ring> ring_, std::vector<QQQ5Sector> sector_, bool up, bool dE) {

    int RingMul=0;
    int SectorMul=0;
    QQQ5DetRaw outputDetRaw;

    for(auto ring: ring_) {
        outputDetRaw.DetRing[RingMul] = ring.detector;
        outputDetRaw.Ring[RingMul] = ring.ring;
        outputDetRaw.RingChannel[RingMul] = ring.channel;
        outputDetRaw.RingADC[RingMul] = ring.adc;
        outputDetRaw.DetRingMul[ring.detector]++;
        RingMul++;
    }
    outputDetRaw.RingMul = RingMul;
    //if(RingMul > 32) {std::cout << "RingMul = " << RingMul << std::endl;}

    for(auto sector: sector_) {
        outputDetRaw.DetSector[SectorMul] = sector.detector;
        outputDetRaw.Sector[SectorMul] = sector.sector;
        outputDetRaw.SectorChannel[SectorMul] = sector.channel;
        outputDetRaw.SectorADC[SectorMul] = sector.adc;
        outputDetRaw.DetSectorMul[sector.detector]++;
        SectorMul++;
    }
    outputDetRaw.SectorMul = SectorMul;
    //if(SectorMul > 4) {std::cout << "SectorMul = " << SectorMul << std::endl;}

    return outputDetRaw;

}
