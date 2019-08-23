#include "ProcessQQQ5.h"

#define PI 3.14159265

using namespace std;

bool ProcessQQQ5(ParticleHit &Qu1, ParticleHit &Qu2, ParticleHit &Qu3, ParticleHit &Qu4, ParticleHit &Qd1, ParticleHit &Qd2, ParticleHit &Qd3){

	float RandomOffset;

	float Ta = BeamEnergy*1000;
	float Tb = 0;

	float Energy, Exe;

	//Upstream QQQ5	
	Qu1.SetRmult(QuIn[0].Ring.Emult);
	Qu1.SetSmult(QuIn[0].Sector.Emult);
	Qu2.SetRmult(QuIn[1].Ring.Emult);
	Qu2.SetSmult(QuIn[1].Sector.Emult);
	Qu3.SetRmult(QuIn[2].Ring.Emult);
	Qu3.SetSmult(QuIn[2].Sector.Emult);
	Qu4.SetRmult(QuIn[3].Ring.Emult);
	Qu4.SetSmult(QuIn[3].Sector.Emult);

	//Downstream QQQ5
	Qd1.SetRmult(QdIn[0].Ring.Emult);
	Qd1.SetSmult(QdIn[0].Sector.Emult);
	Qd2.SetRmult(QdIn[1].Ring.Emult);
	Qd2.SetSmult(QdIn[1].Sector.Emult);
	Qd3.SetRmult(QdIn[2].Ring.Emult);
	Qd3.SetSmult(QdIn[2].Sector.Emult);

	//Upstream QQQ5
	for(int k=0; k<4; k++){
		for(int i=0; i<QuIn[k].Ring.Emult; i++){
			if(k==0){
				Qu1.SetEnergy(QuIn[k].Ring.ReadE[i]);
				Qu1.SetRing(QuIn[k].Ring.Echan[i]);
				//Calibrate
				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qu1Gains[QuIn[k].Ring.Echan[i]-1][0]+(QuIn[k].Ring.ReadE[i])*Qu1Gains[QuIn[k].Ring.Echan[i]-1][1];
				Qu1.SetEnergy(Energy);
				//Get Excitation Energy
				Tb = Energy;
				Exe = (Qgs*1000.0) -  (1.0/My) * ( (My+Mb)*Tb - (My-Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)* cos( QQQAngles[QuIn[k].Ring.Echan[i]] * (PI/180.0) ) ) ) ;
				Qu1.SetEx(Exe);	
				Qu1.SetAngle(QQQAngles[QuIn[k].Ring.Echan[i]]);	
			}else if(k==1){
				//Get raw energy and ring ID
				Qu2.SetRawEnergy(QuIn[k].Ring.ReadE[i]);
				Qu2.SetRing(QuIn[k].Ring.Echan[i]);
				//Calibrate
				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qu2Gains[QuIn[k].Ring.Echan[i]-1][0]+(QuIn[k].Ring.ReadE[i])*Qu2Gains[QuIn[k].Ring.Echan[i]-1][1];
				Qu2.SetEnergy(Energy);
				//Get Excitation Energy
				Tb = Energy;
				Exe = (Qgs*1000.0) -  (1.0/My) * ( (My+Mb)*Tb - (My-Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)* cos( QQQAngles[QuIn[k].Ring.Echan[i]] * (PI/180.0) ) ) ) ;
				Qu2.SetEx(Exe);	
				Qu2.SetAngle(QQQAngles[QuIn[k].Ring.Echan[i]]);				
			}else if(k==2){
				//Get raw energy and ring ID
				Qu3.SetRawEnergy(QuIn[k].Ring.ReadE[i]);
				Qu3.SetRing(QuIn[k].Ring.Echan[i]);
				//Calibrate
				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qu3Gains[QuIn[k].Ring.Echan[i]-1][0]+(QuIn[k].Ring.ReadE[i])*Qu3Gains[QuIn[k].Ring.Echan[i]-1][1];
				Qu3.SetEnergy(Energy);
				//Get Excitation Energy
				Tb = Energy;
				Exe = (Qgs*1000.0) -  (1.0/My) * ( (My+Mb)*Tb - (My-Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)* cos( QQQAngles[QuIn[k].Ring.Echan[i]] * (PI/180.0) ) ) ) ;
				Qu3.SetEx(Exe);
				Qu3.SetAngle(QQQAngles[QuIn[k].Ring.Echan[i]]);				
			}else if(k==3){
				//Get raw energy and ring ID
				Qu4.SetRawEnergy(QuIn[k].Ring.ReadE[i]);
				Qu4.SetRing(QuIn[k].Ring.Echan[i]);
				//Calibrate
				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qu4Gains[QuIn[k].Ring.Echan[i]-1][0]+(QuIn[k].Ring.ReadE[i])*Qu4Gains[QuIn[k].Ring.Echan[i]-1][1];
				Qu4.SetEnergy(Energy);
				//Get Excitation Energy
				Tb = Energy;
				Exe = (Qgs*1000.0) -  (1.0/My) * ( (My+Mb)*Tb - (My-Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)* cos( QQQAngles[QuIn[k].Ring.Echan[i]] * (PI/180.0) ) ) ) ;
				Qu4.SetEx(Exe);
				Qu4.SetAngle(QQQAngles[QuIn[k].Ring.Echan[i]]);	
			}
		}
		for(int i=0; i<QuIn[k].Sector.Emult; i++){

			if(k==0){
				Qu1.SetRawBackEnergy(QuIn[k].Sector.ReadE[i]);
				Qu1.SetSector(QuIn[k].Sector.Echan[i]);

				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qu1Gains[32+QuIn[k].Sector.Echan[i]-1][0]+((QuIn[k].Sector.ReadE[i]-QuPedestals[QuIn[k].Sector.Echan[i]-1]))*Qu1Gains[32+QuIn[k].Ring.Echan[i]-1][1];
				Qu1.SetBackEnergy(Energy);

			}else if(k==1){
				Qu2.SetRawBackEnergy(QuIn[k].Sector.ReadE[i]);
				Qu2.SetSector(QuIn[k].Sector.Echan[i]);

				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qu2Gains[32+QuIn[k].Sector.Echan[i]-1][0]+( (QuIn[k].Sector.ReadE[i]-QuPedestals[3+QuIn[k].Sector.Echan[i]]))*Qu2Gains[32+QuIn[k].Ring.Echan[i]-1][1];
				Qu2.SetBackEnergy(Energy);


			}else if(k==2){
				Qu3.SetRawBackEnergy(QuIn[k].Sector.ReadE[i]);
				Qu3.SetSector(QuIn[k].Sector.Echan[i]);

				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qu3Gains[32+QuIn[k].Sector.Echan[i]-1][0]+( (QuIn[k].Sector.ReadE[i]-QuPedestals[7+QuIn[k].Sector.Echan[i]]))*Qu3Gains[32+QuIn[k].Ring.Echan[i]-1][1];
				Qu3.SetBackEnergy(Energy);


			}else if(k==3){
				Qu4.SetRawBackEnergy(QuIn[k].Sector.ReadE[i]);
				Qu4.SetSector(QuIn[k].Sector.Echan[i]);

				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qu4Gains[32+QuIn[k].Sector.Echan[i]-1][0]+( (QuIn[k].Sector.ReadE[i]-QuPedestals[11+QuIn[k].Sector.Echan[i]] ))*Qu4Gains[32+QuIn[k].Ring.Echan[i]-1][1];
				Qu4.SetBackEnergy(Energy);


			}


		}

	}	

	//Downstream QQQ5
	for(int j=0; j<3; j++){
		for(int l=0; l<QdIn[j].Ring.Emult; l++){
			if(j==0){
				Qd1.SetEnergy(QdIn[j].Ring.ReadE[l]);
				Qd1.SetRing(QuIn[j].Ring.Echan[l]);
				//Calibrate
				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qd1Gains[QdIn[j].Ring.Echan[l]-1][0]+(QdIn[j].Ring.ReadE[l])*Qd1Gains[QdIn[j].Ring.Echan[l]-1][1];
				Qd1.SetEnergy(Energy);
				//Get Excitation Energy
				Tb = Energy;
				Exe = (Qgs*1000.0) -  (1.0/My) * ( (My+Mb)*Tb - (My-Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)* cos( QQQAngles[QdIn[j].Ring.Echan[l]] * (PI/180.0) ) ) ) ;
				Qd1.SetEx(Exe);	
				Qd1.SetAngle(QQQAngles[QdIn[j].Ring.Echan[l]]);	
			}else if(j==1){
				//Get raw energy and ring ID
				Qd2.SetRawEnergy(QdIn[j].Ring.ReadE[l]);
				Qd2.SetRing(QdIn[j].Ring.Echan[l]);
				//Calibrate
				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qd2Gains[QdIn[j].Ring.Echan[l]-1][0]+(QdIn[j].Ring.ReadE[l])*Qd2Gains[QdIn[j].Ring.Echan[l]-1][1];
				Qd2.SetEnergy(Energy);
				//Get Excitation Energy
				Tb = Energy;
				Exe = (Qgs*1000.0) -  (1.0/My) * ( (My+Mb)*Tb - (My-Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)* cos( QQQAngles[QdIn[j].Ring.Echan[l]] * (PI/180.0) ) ) ) ;
				Qd2.SetEx(Exe);	
				Qd2.SetAngle(QQQAngles[QdIn[j].Ring.Echan[l]]);				
			}else if(j==2){
				//Get raw energy and ring ID
				Qd3.SetRawEnergy(QdIn[j].Ring.ReadE[l]);
				Qd3.SetRing(QdIn[j].Ring.Echan[l]);
				//Calibrate
				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qd3Gains[QdIn[j].Ring.Echan[l]-1][0]+(QdIn[j].Ring.ReadE[l])*Qd3Gains[QdIn[j].Ring.Echan[l]-1][1];
				Qd3.SetEnergy(Energy);
				//Get Excitation Energy
				Tb = Energy;
				Exe = (Qgs*1000.0) -  (1.0/My) * ( (My+Mb)*Tb - (My-Ma)*Ta - (2.0*sqrt(Ma*Mb*Ta*Tb)* cos( QQQAngles[QdIn[j].Ring.Echan[l]] * (PI/180.0) ) ) ) ;
				Qd3.SetEx(Exe);
				Qd3.SetAngle(QQQAngles[QdIn[j].Ring.Echan[l]]);				
			}
		}
		for(int l=0; l<QdIn[j].Sector.Emult; l++){

			if(j==0){
				Qd1.SetRawBackEnergy(QdIn[j].Sector.ReadE[l]);
				Qd1.SetSector(QdIn[j].Sector.Echan[l]);

				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qd1Gains[32+QuIn[j].Sector.Echan[l]-1][0]+((QdIn[j].Sector.ReadE[l]-QdPedestals[QdIn[j].Sector.Echan[j]-1]))*Qd1Gains[32+QdIn[j].Ring.Echan[l]-1][1];
				Qd1.SetBackEnergy(Energy);

			}else if(j==1){
				Qd2.SetRawBackEnergy(QdIn[j].Sector.ReadE[l]);
				Qd2.SetSector(QuIn[j].Sector.Echan[l]);

				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qd2Gains[32+QdIn[j].Sector.Echan[l]-1][0]+( (QdIn[j].Sector.ReadE[l]-QdPedestals[3+QdIn[j].Sector.Echan[l]]))*Qd2Gains[32+QdIn[j].Ring.Echan[l]-1][1];
				Qd2.SetBackEnergy(Energy);


			}else if(j==2){
				Qd3.SetRawBackEnergy(QdIn[j].Sector.ReadE[l]);
				Qd3.SetSector(QdIn[j].Sector.Echan[l]);

				RandomOffset = rand()/((float)RAND_MAX+1);
				Energy=Qd3Gains[32+QdIn[j].Sector.Echan[l]-1][0]+( (QdIn[j].Sector.ReadE[l]-QdPedestals[7+QdIn[j].Sector.Echan[l]]))*Qd3Gains[32+QdIn[j].Ring.Echan[l]-1][1];
				Qd3.SetBackEnergy(Energy);


			}


		}

	}


	return true;

/*
	//Set acceptable dE to E1 ring combinations for raytracing
	//Value stored is E1 ring for dE ring = index
	//dE Ring #s	 {0, 1, 2, 3, 4, 5, 6, 7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}
	int E1Low[24] =  {1, 2, 3, 4, 5, 6, 7, 8,  10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 22, 22, -1, -1, -1, -1};
	int E1High[24] = {3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22, 23, 23, -1, -1, -1, -1};

	int i, j;
	//Store dE energy, time, id, and multiplicity for rings and sectors
	int dErmult=0, dEsmult=0, dErid=-1, dEsid=-1;
	float dEre=0, dErre=0, dErt=0, dEse=0, dErse=0, dEst=0;
	//Store E1 energy, time, id, and multiplicity for rings and sectors
	int E1rmult=0, E1smult=0, E1rid=-1, E1sid=-1;
	float E1re=0, E1rre=0, E1rt=0, E1rse=0, E1se=0, E1st=0;
	//Store Upstream energy, time, id, and multiplicity for rings and sectors
	int Uprmult=0, Upsmult=0, Uprid=-1, Upsid=-1;
	float Upre=0, Uprre=0, Uprt=0, Upse=0, Uprse=0, Upst=0;
	//Store Telescope energy, time, id, Particle type (PID), Linear PID value
	float Tee=0, Tere=0, PIDlinear=0, Exe=0;
	//int Teid=-1, PID=0;

	//Store energy and time of event
	float dEe=0, E1e=0, Upe=0;
	float dEt=0, E1t=0, Upt=0;

	float RandomOffset,OldValue;

	float Tb = 0, Ta = 0;

	float s1e=0, s2e=0; 

	float RecoilAngle;

	//////////////////////////////////////////////////
	//	Check for events with Energy and Time	//
	//////////////////////////////////////////////////

	//cout << "Check for events with Energy and Time" << endl;
	
	//Find dE Ring hits that have Energy and Time
	for(i=0; i<dEin.Ring.Emult; i++){
		//cout <<"dE Ring "<<dEin.Ring.Echan[i]<<"\t"<<dEin.Ring.ReadE[i]<<"\t";
		for(j=0; j<dEin.Ring.Tmult; j++){
			//cout<<dEin.Ring.Tchan[j]<<"\t"<<dEin.Ring.ReadT[j]<<"\n";
			if(dEin.Ring.Echan[i]==dEin.Ring.Tchan[j] && dEin.Ring.ReadE[i]>0 && dEin.Ring.ReadT[j]>0){
				RandomOffset = rand()/((float)RAND_MAX+1);
				dEin.Ring.Eid[dEin.Ring.Echan[i]]=dEin.Ring.Echan[i];				
				dEin.Ring.RawE[dEin.Ring.Echan[i]]=dEin.Ring.ReadE[i];
				//dEin.Ring.Energy[dEin.Ring.Echan[i]]=dEin.Ring.ReadE[i]; //Use for calibration
				//dEin.Ring.Energy[dEin.Ring.Echan[i]]=de_cal[dEin.Ring.Echan[i]][0]+de_cal[dEin.Ring.Echan[i]][1]*(RandomOffset+dEin.Ring.ReadE[i]); //Old gains
				OldValue=(RandomOffset+dEin.Ring.ReadE[i]);
				dEin.Ring.Energy[dEin.Ring.Echan[i]]=dECalibration[dEin.Ring.Echan[i]][0]+dECalibration[dEin.Ring.Echan[i]][1]*OldValue+dECalibration[dEin.Ring.Echan[i]][2]*OldValue*OldValue;

				dEin.Ring.Tid[dEin.Ring.Echan[i]]=dEin.Ring.Tchan[j];
				dEin.Ring.Time[dEin.Ring.Echan[i]]=dEin.Ring.ReadT[j];
			}
		}
	}
	//Find dE Sector hits that have Energy and Time
	for(i=0; i<dEin.Sector.Emult; i++){
		for(j=0; j<dEin.Sector.Tmult; j++){
			if(dEin.Sector.Echan[i]==dEin.Sector.Tchan[j] && dEin.Sector.ReadE[i]>0 && dEin.Sector.ReadT[j]>0){
				RandomOffset = rand()/((float)RAND_MAX+1);
				dEin.Sector.Eid[dEin.Sector.Echan[i]]=dEin.Sector.Echan[i];				
				dEin.Sector.RawE[dEin.Sector.Echan[i]]=dEin.Sector.ReadE[i];
				//dEin.Sector.Energy[dEin.Sector.Echan[i]]=dEin.Sector.ReadE[i]; //Use for calibration
				//dEin.Sector.Energy[dEin.Sector.Echan[i]]=RandomOffset+de_cal[dEin.Sector.Echan[i]][0]+de_cal[dEin.Sector.Echan[i]+24][1]*dEin.Sector.ReadE[i]; //Old gains
				OldValue=(RandomOffset+dEin.Sector.ReadE[i]);
				//dEin.Sector.Energy[dEin.Sector.Echan[i]]=de_cal[dEin.Sector.Echan[i]][0]+de_cal[dEin.Sector.Echan[i]+24][1]*OldValue; //Old gains
				dEin.Sector.Energy[dEin.Sector.Echan[i]]=dECalibration1[dEin.Sector.Echan[i]+24][0]+dECalibration1[dEin.Sector.Echan[i]+24][1]*OldValue; //pol1
				//dEin.Sector.Energy[dEin.Sector.Echan[i]]=dECalibration[dEin.Sector.Echan[i]+24][0]+dECalibration[dEin.Sector.Echan[i]+24][1]*OldValue+dECalibration[dEin.Sector.Echan[i]+24][2]*OldValue*OldValue; //pol2

				dEin.Sector.Tid[dEin.Sector.Echan[i]]=dEin.Sector.Tchan[j];
				dEin.Sector.Time[dEin.Sector.Echan[i]]=dEin.Sector.ReadT[j];
			}
		}
	}
	//Find E1 Ring hits that have Energy and Time
	for(i=0; i<E1in.Ring.Emult; i++){
		for(j=0; j<E1in.Ring.Tmult; j++){
			if(E1in.Ring.Echan[i]==E1in.Ring.Tchan[j] && E1in.Ring.ReadE[i]>0 && E1in.Ring.ReadT[j]>0){
				RandomOffset = rand()/((float)RAND_MAX+1);
				E1in.Ring.Eid[E1in.Ring.Echan[i]]=E1in.Ring.Echan[i];				
				E1in.Ring.RawE[E1in.Ring.Echan[i]]=E1in.Ring.ReadE[i];
				//E1in.Ring.Energy[E1in.Ring.Echan[i]]=E1in.Ring.ReadE[i]; //Use for calibration
				//E1in.Ring.Energy[E1in.Ring.Echan[i]]=RandomOffset+e1_cal[E1in.Ring.Echan[i]][0]+e1_cal[E1in.Ring.Echan[i]][1]*E1in.Ring.ReadE[i];
				OldValue=(RandomOffset+E1in.Ring.ReadE[i]);
				E1in.Ring.Energy[E1in.Ring.Echan[i]]=E1Calibration[E1in.Ring.Echan[i]][0]+E1Calibration[E1in.Ring.Echan[i]][1]*OldValue+E1Calibration[E1in.Ring.Echan[i]][2]*OldValue*OldValue;

				E1in.Ring.Tid[E1in.Ring.Echan[i]]=E1in.Ring.Tchan[j];
				E1in.Ring.Time[E1in.Ring.Echan[i]]=E1in.Ring.ReadT[j];
			}
		}
	}
	//Find E1 Sector hits that have Energy and Time
	for(i=0; i<E1in.Sector.Emult; i++){
		for(j=0; j<E1in.Sector.Tmult; j++){
			if(E1in.Sector.Echan[i]==E1in.Sector.Tchan[j] && E1in.Sector.ReadE[i]>0 && E1in.Sector.ReadT[j]>0){
				RandomOffset = rand()/((float)RAND_MAX+1);
				E1in.Sector.Eid[E1in.Sector.Echan[i]]=E1in.Sector.Echan[i];				
				E1in.Sector.RawE[E1in.Sector.Echan[i]]=E1in.Sector.ReadE[i];
				E1in.Sector.Energy[E1in.Sector.Echan[i]]=E1in.Sector.ReadE[i]; //Use for calibration
				//E1in.Sector.Energy[E1in.Sector.Echan[i]]=RandomOffset+e1_cal[E1in.Sector.Echan[i]+24][0]+e1_cal[E1in.Sector.Echan[i]+24][1]*E1in.Sector.ReadE[i];
				OldValue=(RandomOffset+E1in.Sector.ReadE[i]);
				//E1in.Sector.Energy[E1in.Sector.Echan[i]]=e1_cal[E1in.Sector.Echan[i]+24][0]+e1_cal[E1in.Sector.Echan[i]+24][1]*OldValue;
				E1in.Sector.Energy[E1in.Sector.Echan[i]]=E1Calibration1[E1in.Sector.Echan[i]+24][0]+E1Calibration1[E1in.Sector.Echan[i]+24][1]*OldValue; //pol1
				//E1in.Sector.Energy[E1in.Sector.Echan[i]]=E1Calibration[E1in.Sector.Echan[i]+24][0]+E1Calibration[E1in.Sector.Echan[i]+24][1]*OldValue+E1Calibration[E1in.Sector.Echan[i]+24][2]*OldValue*OldValue; //pol2

				E1in.Sector.Tid[E1in.Sector.Echan[i]]=E1in.Sector.Tchan[j];
				E1in.Sector.Time[E1in.Sector.Echan[i]]=E1in.Sector.ReadT[j];
			}
		}
	}
	//Find Upstream Ring hits that have Energy and Time
	for(i=0; i<Upin.Ring.Emult; i++){
		for(j=0; j<Upin.Sector.Tmult; j++){
			//if(Upin.Ring.ReadE[i]>0 && Upin.Ring.ReadT[j]>0){
			//if(Upin.Ring.ReadE[i]>0 && Upin.Ring.Tmult<24){
			if(Upin.Ring.ReadE[i]>0){
				RandomOffset = rand()/((float)RAND_MAX+1);
				Upin.Ring.Eid[Upin.Ring.Echan[i]]=Upin.Ring.Echan[i];				
				Upin.Ring.RawE[Upin.Ring.Echan[i]]=Upin.Ring.ReadE[i];
				Upin.Ring.Energy[Upin.Ring.Echan[i]]=Upin.Ring.ReadE[i]; //Use for calibration
				//Upin.Ring.Energy[Upin.Ring.Echan[i]]=RandomOffset+e2_cal[Upin.Ring.Echan[i]][0]+e2_cal[Upin.Ring.Echan[i]][1]*Upin.Ring.ReadE[i];
				OldValue=(RandomOffset+Upin.Ring.ReadE[i]);
				Upin.Ring.Energy[Upin.Ring.Echan[i]]=UpRingCal[Upin.Ring.Echan[i]][1]+UpRingCal[Upin.Ring.Echan[i]][0]*OldValue;
				//Upin.Ring.Energy[Upin.Ring.Echan[i]]=UpCalibration[Upin.Ring.Echan[i]][0]+UpCalibration[Upin.Ring.Echan[i]][1]*OldValue+UpCalibration[Upin.Ring.Echan[i]][2]*OldValue*OldValue;
				//Upin.Ring.Time[Upin.Ring.Echan[i]]=Upin.Ring.ReadT[i];
			}
		}
		
	}
	//Find Upstream Sector hits that have Energy and Time
	for(i=0; i<Upin.Sector.Emult; i++){
		for(j=0; j<Upin.Sector.Tmult; j++){
			//if(Upin.Sector.ReadE[i]>0 && Upin.Sector.ReadT[j]>0){
			//if(Upin.Sector.ReadE[i]>0 && Upin.Sector.Tmult<8){
			if(Upin.Sector.ReadE[i]>0){
				RandomOffset = rand()/((float)RAND_MAX+1);
				Upin.Sector.Eid[Upin.Sector.Echan[i]]=Upin.Sector.Echan[i];				
				Upin.Sector.RawE[Upin.Sector.Echan[i]]=Upin.Sector.ReadE[i];
				Upin.Sector.Energy[Upin.Sector.Echan[i]]=Upin.Sector.ReadE[i]; //Use for calibration
				//Upin.Sector.Energy[Upin.Sector.Echan[i]]=e2_cal[Upin.Sector.Echan[i]+24][0]+e2_cal[Upin.Sector.Echan[i]+24][1]*Upin.Sector.ReadE[i];
				//OldValue=(RandomOffset+Upin.Sector.ReadE[i]);
				//Upin.Sector.Energy[Upin.Sector.Echan[i]]=UpCalibration[Upin.Sector.Echan[i]+24][0]+UpCalibration[Upin.Sector.Echan[i]+24][1]*OldValue+UpCalibration[Upin.Sector.Echan[i]+24][2]*OldValue*OldValue;
				//Upin.Sector.Time[Upin.Sector.Echan[i]]=Upin.Sector.ReadT[i];
			}
		}
	}

	//////////////////////////
	//		 Rings			//
	//////////////////////////

	double MaxE=0, MaxRawE=0;

	for(i=0;i<24;i++){

		if(dEin.Ring.RawE[i]==7680){
			dErmult=0;
			break;
		}
		if(dEin.Ring.RawE[i]>0){
			dErmult++;
		}
		if(dEin.Ring.RawE[i]>MaxRawE){
			MaxRawE=dEin.Ring.RawE[i];
			MaxE=dEin.Ring.Energy[i];
			dErid=i;
		}
	}

	dEre=MaxE;
	dErre=MaxRawE;

	MaxE=0;
	MaxRawE=0;
	for(i=0;i<24;i++){
		if(E1in.Ring.RawE[i]==7680){
			E1rmult=0;
			break;
		}
		if(E1in.Ring.RawE[i]>0){
			E1rmult++;
		}
		if(E1in.Ring.RawE[i]>MaxRawE){
			MaxRawE=E1in.Ring.RawE[i];
			MaxE=E1in.Ring.Energy[i];
			E1rid=i;
		}
	}

	E1re=MaxE;
	E1rre=MaxRawE;

	MaxE=0;
	MaxRawE=0;
	for(i=0;i<24;i++){

		if(Upin.Ring.RawE[i]==7680){
			Uprmult=0;
			break;
		}
		if(Upin.Ring.RawE[i]>0){
			Uprmult++;
		}
		if(Upin.Ring.RawE[i]>MaxRawE){
			MaxE=Upin.Ring.Energy[i];
			MaxRawE=Upin.Ring.RawE[i];
			Uprid=i;
		}
	}

	Upre=MaxE;
	Uprre=MaxRawE;

	//////////////////////////
	//	Sector Addback	//
	//////////////////////////

	//cout << "Do Sector Addback" << endl;
	//dE
*/	
/*
	for(i=0;i<8;i++){

		if(dEin.Sector.RawE[i]==7680){
			dEsmult=0;
			break;
		}
		if(dEin.Sector.RawE[i]>0){
			dEsmult++;
		}
		if(dEin.Sector.RawE[i]>MaxRawE){
			MaxRawE=dEin.Sector.RawE[i];
			MaxE=dEin.Sector.Energy[i];
			dEsid=i;
		}
	}

	dEse=MaxE;
	dErse=MaxRawE;
*/
/*
	for(i=0;i<8;i++){
		if(dEin.Sector.Energy[i]>0){//There is a value in sector i
			if(dEsmult==0){
				dEse=dEin.Sector.Energy[i];
				dEst=dEin.Sector.Time[i];
				dEsid=i;
				dEsmult++;
				break;
			}else if(dEsmult==1 && (dEsid==(i-1)||dEsid==(i-7)) ){
				if(dEse<dEin.Sector.Energy[i]){
					dEst=dEin.Sector.Time[i];
					dEsid=i;	
				}
				dEse=dEse+dEin.Sector.Energy[i];
				dEsmult++;
			}else{
				dEsmult=0;
				break;
			}
		}
	}

	//Find Max Sector Hit

	MaxE=0;
	MaxRawE=0;

	for(i=0;i<8;i++){

		if(E1in.Sector.RawE[i]==7680){
			E1smult=0;
			break;
		}
		if(E1in.Sector.RawE[i]>0){
			E1smult++;
		}
		if(E1in.Sector.RawE[i]>MaxRawE){
			MaxRawE=E1in.Sector.RawE[i];
			MaxE=E1in.Sector.Energy[i];
			E1sid=i;
		}
	}

	E1se=MaxE;
	E1rse=MaxRawE;


	MaxE=0;
	MaxRawE=0;
	for(i=0;i<8;i++){

		if(Upin.Sector.RawE[i]==7680){
			Upsmult=0;
			break;
		}
		if(Upin.Sector.RawE[i]>0){
			Upsmult++;
		}
		if(Upin.Sector.RawE[i]>MaxRawE){
			MaxE=Upin.Sector.Energy[i];
			MaxRawE=Upin.Sector.RawE[i];
			Upsid=i;
		}
	}

	Upse=MaxE;
	Uprse=MaxRawE;

	//////////////////////////////////////////////
	//		Assign Energy	            //
	//////////////////////////////////////////////

	//cout << "dE: E="<<dEe<<" t="<<dEt<<" R="<<dErid<<" S="<<dEsid<<endl;

	//if(dErmult>0&&dEsmult>0){ //for sorting dE calibration run01211
	//if(E1smult>0){ //for sorting E1 calibration run on Sector side run01215
	//if(E1rmult>0){ //for sorting E1 calibration run on Ring side run01213
	//if(Uprmult>0&&Upsmult>0){ //for sorting upstream calibration run run01195
	if(dErmult>0&&dEsmult>0&&E1rmult>0&&E1smult>0){

		//Use new pixel alpha calibrations

		E1se = AlphaCalib_E1[E1sid*24+E1rid][1] + AlphaCalib_E1[E1sid*24+E1rid][0]*E1rse;
		dEre = AlphaCalib_dE[dEsid*24+dErid][1] + AlphaCalib_dE[dEsid*24+dErid][0]*dErre;

		//Deuteron based calibs. If using this treat dE as dead layer
		//E1se = DeuteronCalib[E1sid*24+E1rid][1] + DeuteronCalib[E1sid*24+E1rid][0]*E1rse;
		//Alpha + deuteron based calib
		//E1se = CombinedCalib[E1sid*24+E1rid][1] + CombinedCalib[E1sid*24+E1rid][0]*E1rse;

		dEe=dEre;
		E1e=E1se;

		if(Uprmult>0){
			Upe=Upre;
		}else{
			Upe=0;
		}
		//Upe=Upse;
*/
/*
		if(USE_AVG_ENERGY==1){//Average the ring and sector energies
			dEe=(dEre+dEse)/2;
			E1e=(E1re+E1se)/2;
			if(Uprmult>0&&Upsmult>0)
			Upe=(Upre+Upse)/2;
		}
		if(USE_SECTOR_ENERGY==1){//Use Sector Energies
			//dEe=dEse;
			dEe=dEre;

			E1e=E1se;
			Upe=Upse;
		}
		if(USE_RING_ENERGY==1){//Use Ring Energies
			dEe=dEre;
			E1e=E1re;
			Upe=Upre;
		}
*/
/*
		if(USE_SECTOR_TIME==1){//Use sector times
			dEt=dEst;
			E1t=E1st;
			Upt=Upst;
		}else{	//Use Ring Times
			dEt=dErt;
			E1t=E1rt;
			Upt=Uprt;
		}	

	}else{
		//cout << "false\n";
		return false;
	}

	/////////////////////////////////////////////
	//                Ray Trace	           //
	/////////////////////////////////////////////
	// Remove ray trace for sorting calibration files

	if(dEsid != E1sid){ //Require particle to hit same sectors
		return false;
	}

	if(E1rid < E1Low[dErid] || E1rid > E1High[dErid]){
		return false;
	}

	/////////////////////////////////////////////
	//                Linear PID	           //
	/////////////////////////////////////////////

	//PIDlinear = (pow(dEe+E1e,1.71)-pow(E1e,1.71))*CosTheta[dErid][E1sid]/100.0;
	PIDlinear = (pow(dEe+E1e,1.68)-pow(E1e,1.68))*CosTheta[dErid][E1sid]/100.0;

	//PIDlinear = (pow(dEe+E1e,1.8)-pow(E1e,1.8))*CosTheta[dErid][E1sid]/100.0; //for uncailbrated E

	/////////////////////////////////////////////
	//               Energy Loss	           //
	/////////////////////////////////////////////

	//See SiliconGains.h for the explanation of energy loss functions and arrays
	//Upstream Energy Loss
	Upe = Upe + Up250[Upsid*24 + Uprid][0] + Up250[Upsid*24 + Uprid][1]*(1/Upe) + Up250[Upsid*24 + Uprid][2]*(1/Upe)*(1/Upe);
	//Upe += Up250[Upsid*24 + Uprid][0] + Up250[Upsid*24 + Uprid][1]*(1/Upe) + Up250[Upsid*24 + Uprid][2]*(1/Upe)*(1/Upe);
	//Telescope energy loss
	Tee = E1e; 
	Tee += MidDeuteron320[dEsid*24 + dErid][0]*pow(Tee,MidDeuteron320[dEsid*24 + dErid][1]) + MidDeuteron320[dEsid*24 + dErid][2]*(1/Tee);
	Tee += dEe; 
	Tee += FrontDeuteron320[dEsid*24 + dErid][0]+FrontDeuteron320[dEsid*24 + dErid][1]*(1/Tee)+FrontDeuteron320[dEsid*24 + dErid][2]*(1/Tee)*(1/Tee);
*/
/*
	Tee = E1e; 
	Tee += 1000*(MidDeuteron320[dEsid*24 + dErid][0]+MidDeuteron320[dEsid*24 + dErid][1]*(1000/Tee)+MidDeuteron320[dEsid*24 + dErid][2]*exp(MidDeuteron320[dEsid*24 + dErid][3]*(Tee/1000)));
	Tee += dEe; 
	Tee += 1000*(FrontDeuteron320[dEsid*24 + dErid][0]+FrontDeuteron320[dEsid*24 + dErid][1]*(1000/Tee)+FrontDeuteron320[dEsid*24 + dErid][2]*(1000/Tee)*(1000/Tee));


	Tee = E1e; 
	Tee += 1000*(MidDeuteron[dEsid*24 + dErid][0]+MidDeuteron[dEsid*24 + dErid][1]*(1000/Tee)+MidDeuteron[dEsid*24 + dErid][2]*exp(MidDeuteron[dEsid*24 + dErid][3]*(Tee/1000)));
	Tee += dEe; 
	Tee += 1000*(FrontDeuteron[dEsid*24 + dErid][0]+FrontDeuteron[dEsid*24 + dErid][1]*(1000/Tee)+FrontDeuteron[dEsid*24 + dErid][2]*(1000/Tee)*(1000/Tee));
*/
	//Get telescope energy by treating the dE as a dead layer
	//td_E = 32.05, x=-0.7, y=-1.5
/*
	Tere = 1000*(	DeuteronEnergyLoss[E1sid*24 + E1rid][0] + 
					DeuteronEnergyLoss[E1sid*24 + E1rid][1]*(E1e/1000) +
					DeuteronEnergyLoss[E1sid*24 + E1rid][2]*(E1e/1000)*(E1e/1000) + 
					DeuteronEnergyLoss[E1sid*24 + E1rid][3]*(E1e/1000)*(E1e/1000)*(E1e/1000) +
					DeuteronEnergyLoss[E1sid*24 + E1rid][4]*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000) +
					DeuteronEnergyLoss[E1sid*24 + E1rid][5]*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000) +
					DeuteronEnergyLoss[E1sid*24 + E1rid][6]*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000) +
					DeuteronEnergyLoss[E1sid*24 + E1rid][7]*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000) );

	//td_E = 32.05, x=-1.0, y=-0.9
	Tere = 1000*(	DeuteronEnergyLoss1[E1sid*24 + E1rid][0] + 
					DeuteronEnergyLoss1[E1sid*24 + E1rid][1]*(E1e/1000) +
					DeuteronEnergyLoss1[E1sid*24 + E1rid][2]*(E1e/1000)*(E1e/1000) + 
					DeuteronEnergyLoss1[E1sid*24 + E1rid][3]*(E1e/1000)*(E1e/1000)*(E1e/1000) +
					DeuteronEnergyLoss1[E1sid*24 + E1rid][4]*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000) +
					DeuteronEnergyLoss1[E1sid*24 + E1rid][5]*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000) +
					DeuteronEnergyLoss1[E1sid*24 + E1rid][6]*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000) +
					DeuteronEnergyLoss1[E1sid*24 + E1rid][7]*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000)*(E1e/1000) );
*/
/*
	/////////////////////////////////////////////
	//            Excitation Energy	           //
	/////////////////////////////////////////////
	
	//Use dE + E eneries for telescope energy
	Tb = Tee;

	//Use dE as dead layer for telescope energy
	//Tb = Tere; 

	//Tb = Tee*ExGains[dErid*8 + dEsid][1]; //Apply secondary calibrations
	Ta = BeamEnergy*1000.0;
	Exe = (Qgs*1000.0) - ( (1.0/My) * ( ((My+Mb)*Tb) - ((My-Ma)*Ta) - (2.0*sqrt(Ma*Mb*Ta*Tb)*CosTheta[dErid][E1sid]) ) );

	//Exe = Exe*ExGains[dErid*8 + dEsid][1]; //Apply secondary calibrations, pixel by pixel

	/////////////////////////////////////////////
	//            Recoil Angle		           //
	/////////////////////////////////////////////

	RecoilAngle = (180.0/PI) * atan( sqrt(2*Mb*Tb)*sqrt(1-CosTheta[dErid][E1sid]*CosTheta[dErid][E1sid]) / ( sqrt(2*Ma*Ta) - sqrt(2*Mb*Tb)*CosTheta[dErid][E1sid] ) );
*/
	/////////////////////////////////////////////
	//            	CM Angle		           //
	/////////////////////////////////////////////
/*
	float TanThetaLab = tan((PI/180.0)*Angles[dErid][dEsid][0]);
	float gamma = sqrt( (Ma*Mb)/(Mx*My)*(Ta/(Ta+Qgs*(1+Ma/Mx))) );
	float a = TanThetaLab*TanThetaLab+1;
	float b = 2*gamma*TanThetaLab*TanThetaLab;
	float c = gamma*gamma*TanThetaLab*TanThetaLab;

	float CMAngle = (180.0/PI)*acos( (-b+sqrt(b*b-4*a*c))/(2*a) );

*/
/*

	/////////////////////////////////////////////
	//  Assign final values for filling tree   //
	/////////////////////////////////////////////


	Tel.SetEnergy(Tee);
	Tel.SetRawEnergy(Tere);
	Tel.SetTime(dEt);
	Tel.SetPIDlinear(PIDlinear);
	Tel.SetAngle(Angles[dErid][dEsid][0]);
	//Tel.SetCMAngle(CMAngle);
	Tel.SetEx(Exe);
	Tel.SetRecoilAngle(RecoilAngle);

	dE.SetEnergy(dEe);
	dE.SetRawEnergy(dErre);
	dE.SetTime(dEt);
	dE.SetRing(dErid);
	dE.SetSector(dEsid);
	dE.SetRmult(dErmult);
	dE.SetSmult(dEsmult);

	E1.SetEnergy(E1e);
	E1.SetRawEnergy(E1rse);
	E1.SetTime(E1t);
	E1.SetRing(E1rid);
	E1.SetSector(E1sid);
	E1.SetRmult(E1rmult);
	E1.SetSmult(E1smult);

	Up.SetEnergy(Upe);
	Up.SetRawEnergy(Uprre);
	Up.SetTime(Upt);
	Up.SetRing(Uprid);
	Up.SetSector(Upsid);
	Up.SetRmult(Uprmult);
	Up.SetSmult(Upsmult);

*/	
	
	//return true;

}//End of MakeTelescope



