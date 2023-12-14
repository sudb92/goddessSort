#ifndef ProcessIC_h
#define ProcessIC_h

#include "TypeDef.h"

auto pred = [] (const ICTracking& lhs, const ICTracking& rhs) {return lhs.adc > rhs.adc;};
void SortICTrack(std::vector<ICTracking>& IC_);
std::vector<ICTrackingDetector> ProcessIC(std::vector<ICTracking> ICx_, std::vector<ICTracking> ICy_);

#endif // ProcessIC_h
