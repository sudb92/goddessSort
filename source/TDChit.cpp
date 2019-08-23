#include "TDChit.h"

TDChit::TDChit() { }

void TDChit::SetValue(int fValue){
	Value = fValue;
}

int TDChit::GetValue(){
	return Value;
}

void TDChit::ResetAll(){
	Value = 0;
}
