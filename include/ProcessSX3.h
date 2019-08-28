#ifndef PROCESSSX3_H
#define PROCESSSX3_H

#include "Calibrations.h"
#include "SX3det.h"

#include <iostream>

bool ProcessSX3(int Id, SX3det &SX3);
bool ApplyGainMatch(int Id, SX3det &SX3);

#endif
