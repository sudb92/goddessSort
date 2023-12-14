#ifndef ProcessSX3_h
#define ProcessSX3_h

#include "TypeDef.h"

#include <iostream>
#include <vector>


SX3DetRaw ProcessSX3(std::vector<SuperX3Front> front_, std::vector<SuperX3Back> back_, bool up);

#endif // ProcessSX3_h
