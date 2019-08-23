#ifndef ProcessSX3_h
#define ProcessSX3_h

#include "SX3det.h"
#include "SX3gains.h"

#include <iostream>

bool ProcessSX3(int Id, SX3det &SX3);
bool ApplyGainMatch(int Id, SX3det &SX3);

#endif
