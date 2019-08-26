#include "ProcessQQQ5.h"

using namespace std;

bool ProcessQQQ5(ParticleHit *Qu[4], ParticleHit *Qd[3], QQQ5ParticleIn *QuIn, QQQ5ParticleIn *QdIn){

    Calibrations* calibrations = Calibrations::Instance();
    auto QdGains = calibrations->GetQQQ5DownCalibrations();
    auto QuGains = calibrations->GetQQQ5UpCalibrations();
    auto QQQAngles = calibrations->GetQQQ5Angles();

	float RandomOffset;

    float BeamEnergy = 227.0;
	float Ta = BeamEnergy*1000;
	float Tb = 0;

    float Ma = 29.97831; //Beam mass
    float Mx = 2.01410; //Target Mass

    float Mb = 1.00782; //Ejectile mass
    float My = 30.97376; // Recoil mass

    float Qgs = 10.087; //Ground State Q-Value (MeV)

	float Energy, Exe;

	//Upstream QQQ5
	for(int i = 0; i < 4; i++) {
	    Qu[i]->SetRmult(QuIn[i].Ring.Emult);
	    Qu[i]->SetSmult(QuIn[i].Sector.Emult);
	}

	//Downstream QQQ5
    for(int i = 0; i < 3; i++) {
        Qd[i]->SetRmult(QdIn[i].Ring.Emult);
        Qd[i]->SetSmult(QdIn[i].Sector.Emult);
    }

	//Upstream QQQ5
	for(int k = 0; k < 4; k++){
		for(int i = 0; i < QuIn[k].Ring.Emult; i++){
		    Qu[k]->SetEnergy(QuIn[k].Ring.ReadE[i]);
		    Qu[k]->SetRing(QuIn[k].Ring.Echan[i]);
		    // Calibrate
            Energy = QuGains[k][QuIn[k].Ring.Echan[i] - 1].first + QuIn[k].Ring.ReadE[i]*QuGains[k][QuIn[k].Ring.Echan[i] - 1].second;
            Qu[k]->SetEnergy(Energy);
            //Get Excitation Energy
            Tb = Energy;
            Exe = (Qgs*1000.0) - (1.0/My)*((My + Mb)*Tb - (My - Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)*cos(QQQAngles[QuIn[k].Ring.Echan[i] - 1]*(M_PI/180.0))));
            Qu[k]->SetEx(Exe);
            Qu[k]->SetAngle(QQQAngles[QuIn[k].Ring.Echan[i]]);
		}
		for(int i = 0; i < QuIn[k].Sector.Emult; i++){
            Qu[k]->SetRawBackEnergy(QuIn[k].Sector.ReadE[i]);
            Qu[k]->SetSector(QuIn[k].Sector.Echan[i]);

            Energy = QuGains[k][32 + QuIn[k].Ring.Echan[i] - 1].first + QuIn[k].Sector.ReadE[i]*QuGains[k][32 + QuIn[k].Ring.Echan[i] - 1].second;
            // Energy = Qu1Gains[32 + QuIn[k].Sector.Echan[i] - 1][0] + ((QuIn[k].Sector.ReadE[i] - QuPedestals[QuIn[k].Sector.Echan[i] - 1]))*Qu1Gains[32 + QuIn[k].Ring.Echan[i] - 1][1];
            Qu[k]->SetBackEnergy(Energy);
		}

	}	

	//Downstream QQQ5
	for(int k = 0; k < 3; k++){
		for(int i = 0; i < QdIn[k].Ring.Emult; i++){
            Qd[k]->SetEnergy(QdIn[k].Ring.ReadE[i]);
            Qd[k]->SetRing(QuIn[k].Ring.Echan[i]);
            //Calibrate
            Energy = QdGains[k][QdIn[k].Ring.Echan[i] - 1].first + QdIn[k].Ring.ReadE[i]*QdGains[k][QdIn[k].Ring.Echan[i] - 1].second;
            // Energy = Qd1Gains[QdIn[j].Ring.Echan[l]-1][0]+(QdIn[j].Ring.ReadE[l])*Qd1Gains[QdIn[j].Ring.Echan[l]-1][1];
            Qd[k]->SetEnergy(Energy);
            //Get Excitation Energy
            Tb = Energy;
            Exe = (Qgs*1000.0) -  (1.0/My)*((My+Mb)*Tb - (My-Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)*cos(QQQAngles[QdIn[k].Ring.Echan[i] - 1]*(M_PI/180.0))));
            Qd[k]->SetEx(Exe);
            Qd[k]->SetAngle(QQQAngles[QdIn[k].Ring.Echan[i]]);
		}
		for(int i = 0; i < QdIn[k].Sector.Emult; i++){
            Qd[k]->SetRawBackEnergy(QdIn[k].Sector.ReadE[i]);
            Qd[k]->SetSector(QdIn[k].Sector.Echan[i]);

            Energy = QdGains[k][32 + QuIn[k].Ring.Echan[i] - 1].first + QdIn[k].Sector.ReadE[i]*QdGains[k][32 + QdIn[k].Ring.Echan[i] - 1].second;
            // Energy = Qd1Gains[32 + QuIn[j].Sector.Echan[l] - 1][0] + ((QdIn[j].Sector.ReadE[l] - QdPedestals[QdIn[j].Sector.Echan[j] - 1]))*Qd1Gains[32 + QdIn[j].Ring.Echan[l] - 1][1];
            Qd[k]->SetBackEnergy(Energy);
		}
	}

	return true;
}



