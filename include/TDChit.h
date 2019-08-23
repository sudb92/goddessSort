#ifndef TDChit_h
#define TDChit_h

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
