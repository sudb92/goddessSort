#include "ProcessIC.h"

bool ProcessIC(IChit &IC, float dE, float E){
	IC.SetdE(dE);
	IC.SetE(E);
}