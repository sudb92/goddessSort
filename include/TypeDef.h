#ifndef TypeDef_h
#define TypeDef_h

struct QQQ5RingIn{
	//All values read in
	float ReadE[32];
	int Echan[32];

	float RawE[32];
	int Eid[32];

	int Emult;
};

struct QQQ5SectorIn{
	//All values read in
	float ReadE[4];
	int Echan[4];

	float RawE[4];
	int Eid[4];

	int Emult;
};

struct QQQ5ParticleIn{
	QQQ5RingIn Ring;
	QQQ5SectorIn Sector;
};

#endif