#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <TObject.h>
#include <TRint.h>
#include <TROOT.h>
#include <TSystem.h>

unsigned int ExtractBits(unsigned int value, int begin, int end);
unsigned int ReverseBits(unsigned int n);
std::string PrintOutput(std::string Output, std::string Color);

#endif