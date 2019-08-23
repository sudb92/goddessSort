#include "TDC.h"

TDC::TDC() { }

void TDC::SetValue(int fValue){
	Value = fValue;
}

int TDC::GetValue(){
	return Value;
}

void TDC::ResetAll(){
	Value = 0;
}
