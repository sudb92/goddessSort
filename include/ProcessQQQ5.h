#ifndef PROCESSQQQ5_H
#define PROCESSQQQ5_H

#include "Calibrations.h"
#include "ParticleHit.h"
#include "TypeDef.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

bool ProcessQQQ5(ParticleHit *Qu[4], ParticleHit *Qd[3], QQQ5ParticleIn *QuIn, QQQ5ParticleIn *QdIn);
//std::vector<std::vector<std::vector<float>>> CalculateAngles();

#endif
