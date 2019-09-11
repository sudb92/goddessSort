#ifndef PROCESSSX3_H
#define PROCESSSX3_H

#include "Calibrations.h"
#include "TypeDef.h"

#include <iostream>
#include <vector>

auto compBack = [] (const SuperX3Back& lhs, const SuperX3Back& rhs) {return lhs.channel == rhs.channel;};
auto predBack = [] (const SuperX3Back& lhs, const SuperX3Back& rhs) {return lhs.channel < rhs.channel;};
auto compFront = [] (const SuperX3Front& lhs, const SuperX3Front& rhs) {return lhs.channel == rhs.channel;};
auto predFront = [] (const SuperX3Front& lhs, const SuperX3Front& rhs) {return lhs.channel < rhs.channel;};

std::vector<SuperX3Detector> ProcessSX3(std::vector<SuperX3Back> back_, std::vector<SuperX3Front> front_, bool up);
void RemoveSX3BackDuplicates(std::vector<SuperX3Back>& back_);
void RemoveSX3FrontDuplicates(std::vector<SuperX3Front>& front_);
//bool ApplyGainMatch(int Id, SX3det &SX3);

#endif
