#ifndef TDC_h
#define TDC_h

class TDC {

public:
	TDC();
	void SetValue(int fValue);
	int GetValue();
	void ResetAll();

private:
	int Value;
};

#endif
