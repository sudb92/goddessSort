#ifndef ProcessQQQ5_h
#define ProcessQQQ5_h

#include "Calibrations.h"
#include "TypeDef.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

auto compRing = [] (const QQQ5Ring& lhs, const QQQ5Ring& rhs) {return lhs.channel == rhs.channel;};
auto predRing = [] (const QQQ5Ring& lhs, const QQQ5Ring& rhs) {return lhs.channel < rhs.channel;};
auto compSector = [] (const QQQ5Sector& lhs, const QQQ5Sector& rhs) {return lhs.channel == rhs.channel;};
auto predSector = [] (const QQQ5Sector& lhs, const QQQ5Sector& rhs) {return lhs.channel < rhs.channel;};

void RemoveQQQ5RingDuplicates(std::vector<QQQ5Ring>& ring_);
void RemoveQQQ5SectorDuplicates(std::vector<QQQ5Sector>& sector_);
std::vector<QQQ5Detector> ProcessQQQ5(std::vector<QQQ5Ring> ring_, std::vector<QQQ5Sector> sector_, bool up);

#endif // ProcessQQQ5_h
