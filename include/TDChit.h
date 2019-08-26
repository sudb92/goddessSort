#ifndef TDCHIT_H
#define TDCHIT_H

class TDChit {

public:
	TDChit();
	void SetValue(int fValue);
	int GetValue();
	void ResetAll();
private:
	int Value;
};

#endif
