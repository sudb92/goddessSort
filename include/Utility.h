#ifndef Utility_h
#define Utility_h

#include <string>

unsigned int ExtractBits(unsigned int value, int begin, int end);
unsigned int ReverseBits(unsigned int n);
void ResetInStructs();
std::string PrintOutput(std::string Output, std::string Color);

#endif