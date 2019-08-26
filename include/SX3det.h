#ifndef SX3DET_H
#define SX3DET_H

#include <vector>

class SX3det {
public:
	//constructor
	SX3det();

	//Setters
	void SetRawLeft(int Value);
	void SetRawRight(int Value);
	void SetRawBackEnergy(int Value);

	void SetLeftHits(int Value);
	void SetRightHits(int Value);
	void SetBackHits(int Value);

	void SetLeft(float Value);
	void SetRight(float Value);

	void SetRawEnergy(float Value);
	void SetEnergy(float Value);
	void SetStrip(int Value);
	void SetBackEnergy(float Value);
	void SetBack(int Value);

	void SetPos(float Value);

	void SetMult(int Value);
	void SetLmult(int Value);
	void SetRmult(int Value);
	void SetBmult(int Value);

	//Getters
	int GetRawLeft(int Index);
	int GetRawRight(int Index);
	int GetRawBackEnergy(int Index);

	int GetLeftHits(int Index);
	int GetRightHits(int Index);
	int GetBackHits(int Index);

	float GetLeft(int Index);
	float GetRight(int Index);

	float GetRawEnergy(int Index);
	float GetEnergy(int Index);
	int GetStrip(int Index);
	float GetBackEnergy(int Index);
	int GetBack(int Index);

	float GetPos(int Index);

	int GetMult();
	int GetLmult();
	int GetRmult();
	int GetBmult();

	//Other
	void IncrementMult();
	void IncrementLmult();
	void IncrementRmult();
	void IncrementBmult();
	void ResetAll();

private:
	std::vector<int> RawLeft;
	std::vector<int> RawRight;
	std::vector<int> RawBackEnergy;

	std::vector<int> LeftHits;
	std::vector<int> RightHits;
	std::vector<int> BackHits;

	std::vector<float> Left;
	std::vector<float> Right;

	std::vector<float> RawEnergy;
	std::vector<float> Energy;
	std::vector<int> Strip;

	std::vector<float> BackEnergy;
	std::vector<int> Back;

	std::vector<float> Pos;

	int Mult;
	int Lmult;
	int Rmult;
	int Bmult;
};

#endif
