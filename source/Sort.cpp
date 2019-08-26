#include "Sort.h"

#define BUFFER_LENGTH 8194
#define BUFFER_LENGTHB 32776

#define MAXCHANNEL 1024
#define MAXVALUE 4096

int NumberEventsPerPrint = 1000;


std::vector<std::string> RunList = {
												   /*  "0023","0024","0025","0026","0027","0028","0029",
								"0030","0031","0032","0033","0034","0035","0036","0037","0038","0039",
								"0040","0041","0042","0043","0044","0045","0046","0047","0048","0049",
								"0050","0051","0052","0053","0054","0055","0056","0057","0058","0059",
								"0060","0061","0062","0063","0064","0065","0066","0067","0068","0069",
								"0070","0071","0072",*/
													 "0073","0074","0075","0076","0077","0078","0079",
								"0080","0081","0082","0083","0084","0085","0086","0087","0088","0089",
								"0090","0091","0092","0093","0094","0095","0096","0097","0098","0099",
								"0100","0101","0102","0103","0104","0105","0106","0107","0108","0109",
								"0110","0111","0112","0113","0114","0115","0116","0117","0118","0119",
								"0120","0121","0122","0123","0124","0125","0126","0127","0128","0129",
								"0130","0131","0132","0133","0134","0135","0136","0137","0138","0139",
								"0140","0141","0142","0143","0144","0145","0146","0147","0148","0149",
								"0150","0151","0152","0153","0154","0155","0156","0157","0158","0159",
								"0160","0161","0162","0163","0164","0165","0166","0167","0168","0169",
								"0170","0171","0172","0173","0174","0175","0176","0177","0178","0179",
								"0180","0181","0182","0183","0184","0185","0186","0187","0188","0189",
								"0190","0191","0192","0193","0194","0195","0196","0197","0198","0199",
								"0200","0201","0202","0203","0204","0205","0206","0207","0208","0209",
								"0210","0211","0212","0213","0214","0215","0216","0217","0218","0219",
								"0220","0221","0222","0223","0224","0225","0226","0227","0228","0229",
								"0230","0231","0232","0233","0234","0235","0236","0237","0238","0239",
								"0240","0241","0242","0243","0244","0245","0246","0247","0248","0249",
								"0250","0251","0252","0253","0254","0255","0256","0257","0258","0259",
								"0260","0261","0262","0263","0264","0265","0266","0267","0268","0269",
								"0270","0271","0272","0273","0274","0275","0276","0277","0278","0279",
								"0280","0281","0282","0283","0284","0285","0286","0287","0288","0289",
								"0290","0291","0292","0293","0294","0295","0296","0297","0298","0299",
								"0300","0301","0302","0303","0304","0205","0306","0307","0308","0309",
								"0310","0311","0312","0313","0314","0315","0326","0317","0318","0319",
								"0320","0321","0322","0323","0324","0325","0326","0327","0328","0329",
								"0330","0331","0332","0333","0334","0335","0336","0337","0338","0339",
								"0340","0341","0342","0343","0344","0345","0346","0347","0348","0349",
								"0350","0351","0352","0353","0354","0355","0356","0357","0358","0359",
								"0360","0361","0362","0363","0364","0365","0366","0367","0368","0369",
								"0370","0371","0372","0373","0374","0375","0376","0377","0378","0379",
								"0380","0381","0382","0383","0384","0385","0386","0387","0388","0389",
								"0390","0391","0392","0393","0394","0395","0396","0397","0398","0399",
								"0400","0401","0402","0403","0404","0405","0406","0407","0408","0409",
								"0410","0411","0412","0413","0414","0415","0416","0417","0418","0419",
								"0420","0421","0422","0423","0424","0425","0426","0427","0428","0429",
								"0430","0431","0432","0433","0434","0435","0436","0437","0438","0439"

							   };


//////////////////////////////////////
//		Define Kinematic Values		//
//////////////////////////////////////

//Reaction : X(a,b)Y

float BeamEnergy = 227.0;

//30P(d,p)31P inverse kin
float Ma = 29.97831; //Beam mass
float Mx = 2.01410; //Target Mass

float Mb = 1.00782; //Ejectile mass
float My = 30.97376; // Recoil mass

float Qgs = 10.087; //Ground State Q-Value (MeV)

//Declare read in structs
//Upstream QQQ5
QQQ5ParticleIn Qu1in;
QQQ5ParticleIn Qu2in;
QQQ5ParticleIn Qu3in;
QQQ5ParticleIn Qu4in;

//Downstream QQQ5
QQQ5ParticleIn Qd1in;
QQQ5ParticleIn Qd2in;
QQQ5ParticleIn Qd3in;

QQQ5ParticleIn QuIn[4]; //Upstream
QQQ5ParticleIn QdIn[3]; //Downstream

int ICdEin, ICEin, TDCin;
int RunClock;

bool Success, ICyeah, SX3yeah, SX3gainYeah, SX3check;

//Set thresholds in channel number
int SX3backThreshold = 500;
int QQQThreshold = 400;
int BB10Threshold = 500;

std::vector<int> ReadChannel;
std::vector<int> ReadValue;

int main(int argc, char *argv[]){

	int StartClock = clock();
	std::cout << PrintOutput("Running GODDESS sort", "yellow") << std::endl;
	std::cout << PrintOutput("Creating shared root libraries...", "yellow") << std::endl;

	std::string DataFileName, RootFileName;

	std::cout << PrintOutput("Number of files to be sort = ", "yellow") << RunList.size() << std::endl;
	std::cout << PrintOutput("Begin data processing loop", "yellow") << std::endl;

	int rn;

	//*****************************************************//
	//for(rn=0; rn<RunList.size(); rn++){ //Use this to sort all data files listed in RunList (above)
	//for(rn=0; rn<1; rn++){ //Use this to sort a single calibration file
	//*****************************************************//

		DataFileName.clear();
		RootFileName.clear();

		//*****************************************************//
		//Use these 2 lines to sort from RunList
		//DataFileName = "ldfs/p30dp"+RunList[rn]+".ldf";
		//RootFileName = "RootFiles/p30dp"+RunList[rn]+".root";
		//*****************************************************//

		//*****************************************************//
		//Use these 2 lines to specify a calibration file to be sorted
		DataFileName = "ldfs/Ecal02.ldf";
		RootFileName = "RootFiles/Ecal02.root";
		//*****************************************************//

		// Open the file. Check whether file opened successfully.
		std::ifstream file(DataFileName.c_str(), std::ios::binary);
		ASSERT_WITH_MESSAGE(file.is_open(), Form("File not found: %s", DataFileName.c_str()));

		//Create and Open Root file to store data in. Check for success.
		TFile *RootFile = new TFile(RootFileName.c_str(),"RECREATE");
		ASSERT_WITH_MESSAGE(RootFile->IsOpen(), Form("Root File did not open: %s", RootFileName.c_str()));

		std::cout << PrintOutput("************************************************","yellow")<<std::endl;
		std::cout << PrintOutput("Sorting data file : ","green")<< DataFileName<<"\t["<<rn+1<<"/"<<RunList.size()<<"]"<< std::endl;

		//Declare some variables
		int NumberBuffer = 0;
		unsigned long int NumberEvents = 0;
		int Counter = 0 ;
		unsigned int Buffer[BUFFER_LENGTH];
		unsigned int Word;
		int Channel,Value;
		unsigned short halfWord[2];

		//Declare some ROOT structures
		TH2F *Map = new TH2F("Map","Map",MAXCHANNEL,0,MAXCHANNEL,MAXVALUE,0,MAXVALUE);
		TH1F *EventMult = new TH1F("EventMult","EventMult",1024,0,1024);

		//Declare detectors

		//Upstream QQQQ5
		ParticleHit *Qu[4];
		for(int i = 0; i < 4; i++) {
		    Qu[i] = new ParticleHit();
		}

		//Downstream QQQ5
		ParticleHit *Qd[3];
		for(int i = 0; i < 3; i++) {
		    Qd[i] = new ParticleHit();
		}

		//IC
		IChit *IC = new IChit();

		//TDC
		TDChit *TDC = new TDChit();

		// Upstream and Downstream SX3
        SX3det *SX3d[12];
		SX3det *SX3u[12];
        for(int i = 0; i < 12; i++) {
            SX3d[i] = new SX3det();
            SX3u[i] = new SX3det();
        }

		//Upstream SX3
		SX3det *SX3u1 = new SX3det();
		SX3det *SX3u2 = new SX3det();
		SX3det *SX3u3 = new SX3det();
		SX3det *SX3u4 = new SX3det();
		SX3det *SX3u5 = new SX3det();
		SX3det *SX3u6 = new SX3det();
		SX3det *SX3u7 = new SX3det();
		SX3det *SX3u8 = new SX3det();
		SX3det *SX3u9 = new SX3det();
		SX3det *SX3u10 = new SX3det();
		SX3det *SX3u11 = new SX3det();
		SX3det *SX3u12 = new SX3det();

		//Downstream SX3
		SX3det *SX3d1 = new SX3det();
		SX3det *SX3d2 = new SX3det();
		SX3det *SX3d3 = new SX3det();
		SX3det *SX3d4 = new SX3det();
		SX3det *SX3d5 = new SX3det();
		SX3det *SX3d6 = new SX3det();
		SX3det *SX3d7 = new SX3det();
		SX3det *SX3d8 = new SX3det();
		SX3det *SX3d9 = new SX3det();
		SX3det *SX3d10 = new SX3det();
		SX3det *SX3d11 = new SX3det();
		SX3det *SX3d12 = new SX3det();

		//BB10
		BB10det *BB10[8];
		for(int i = 0; i < 8; i++) {
		    BB10[i] = new BB10det();
		}
		BB10det *BB10_1 = new BB10det();
		BB10det *BB10_2 = new BB10det();
		BB10det *BB10_3 = new BB10det();
		BB10det *BB10_4 = new BB10det();
		BB10det *BB10_5 = new BB10det();
		BB10det *BB10_6 = new BB10det();
		BB10det *BB10_7 = new BB10det();
		BB10det *BB10_8 = new BB10det();

		//Setup Tree
		TTree *Tree = new TTree("Tree","Data Tree");

		//Declaring Branches for different detectors
		//Upstream QQQ5
		for(int i = 0; i < 4; i++) {
		    Tree->Branch(Form("Qu%d", i), &Qu[i]);
		}

		//IC
		Tree->Branch("IC", &IC);

		//TDC
		Tree->Branch("TDC", &TDC);

		//Upstream SX3
		Tree->Branch("SX3u1", &SX3u1);
		Tree->Branch("SX3u2", &SX3u2);
		Tree->Branch("SX3u3", &SX3u3);
		Tree->Branch("SX3u4", &SX3u4);
		Tree->Branch("SX3u5", &SX3u5);
		Tree->Branch("SX3u6", &SX3u6);
		Tree->Branch("SX3u7", &SX3u7);
		Tree->Branch("SX3u8", &SX3u8);
		Tree->Branch("SX3u9",  &SX3u9);
		Tree->Branch("SX3u10", &SX3u10);
		Tree->Branch("SX3u11", &SX3u11);
		Tree->Branch("SX3u12", &SX3u12);

		//Downstream SX3
		Tree->Branch("SX3d1", &SX3d1);
		Tree->Branch("SX3d2", &SX3d2);
		Tree->Branch("SX3d3", &SX3d3);
		Tree->Branch("SX3d4", &SX3d4);
		Tree->Branch("SX3d5", &SX3d5);
		Tree->Branch("SX3d6", &SX3d6);
		Tree->Branch("SX3d7", &SX3d7);
		Tree->Branch("SX3d8", &SX3d8);
		Tree->Branch("SX3d9", &SX3d9);
		Tree->Branch("SX3d10", &SX3d10);
		Tree->Branch("SX3d11", &SX3d11);
		Tree->Branch("SX3d12", &SX3d12);

		//BB10
		Tree->Branch("BB10_1",&BB10_1);
		Tree->Branch("BB10_2",&BB10_2);
		Tree->Branch("BB10_3",&BB10_3);
		Tree->Branch("BB10_4",&BB10_4);
		Tree->Branch("BB10_5",&BB10_5);
		Tree->Branch("BB10_6",&BB10_6);
		Tree->Branch("BB10_7",&BB10_7);
		Tree->Branch("BB10_8",&BB10_8);

		//Downstream QQQ5
        for(int i = 0; i < 3; i++) {
            Tree->Branch(Form("Qd%d", i), &Qd[i]);
        }

		//This is the main loop over the file
		while(!file.eof()){

			//Get Buffer
			file.read((char*)Buffer, BUFFER_LENGTHB);

			//std::cout << "**** Reading Buffer : " << std::dec << NumberBuffer << " ****" << std::endl;
			if(Buffer[0] == 0x41544144){ //This buffer is physics data type
				for(int i=0; i<BUFFER_LENGTH; i++){

					Word = Buffer[i];
					// Reverse the byte order. Switching between big and little endian
					halfWord[0] = 0x0000ffff & Word;
					halfWord[1] = Word >> 16;
					Word = (halfWord[0] << 16) | (halfWord[1]);

					//Check for the end of the event
					if(Word != 0xffffffff){

						Channel = ExtractBits(Word,16,12);
						Value = ExtractBits(Word,0,12);
						Map->Fill(Channel,Value);

						//Add values to Read Arrays
						ReadChannel.push_back(Channel);
						ReadValue.push_back(Value);

						Counter++;

					}else{ //End of the Event

						ResetInStructs();

						//Loop over Sub-events
						//for(int k=0; k<Counter; k++){

						//Upstream QQQ5 Front and Back
						for(int k=0; k<ReadChannel.size(); k++){
							if(ReadChannel[k]>=1 && ReadChannel[k]<=32 && ReadValue[k]>QQQThreshold){ //QQQ5 upstream 1 front
								QuIn[0].Ring.ReadE[QuIn[0].Ring.Emult]=ReadValue[k];
								QuIn[0].Ring.Echan[QuIn[0].Ring.Emult]=ReadChannel[k];
								QuIn[0].Ring.Emult++;
							}else if(ReadChannel[k]>=33 && ReadChannel[k]<=64 && ReadValue[k]>QQQThreshold){ //QQQ5 upstream 2 front
								QuIn[1].Ring.ReadE[QuIn[1].Ring.Emult]=ReadValue[k];
								QuIn[1].Ring.Echan[QuIn[1].Ring.Emult]=ReadChannel[k]-32;
								QuIn[1].Ring.Emult++;
							}else if(ReadChannel[k]>=65 && ReadChannel[k]<=96 && ReadValue[k]>QQQThreshold){ //QQQ5 upstream 3 front
								QuIn[2].Ring.ReadE[QuIn[2].Ring.Emult]=ReadValue[k];
								QuIn[2].Ring.Echan[QuIn[2].Ring.Emult]=ReadChannel[k]-64;
								QuIn[2].Ring.Emult++;
							}else if(ReadChannel[k]>=97 && ReadChannel[k]<=128 && ReadValue[k]>QQQThreshold){ //QQQ5 upstream 4 front
								QuIn[3].Ring.ReadE[QuIn[3].Ring.Emult]=ReadValue[k];
								QuIn[3].Ring.Echan[QuIn[3].Ring.Emult]=ReadChannel[k]-96;
								QuIn[3].Ring.Emult++;
							}else if(ReadChannel[k]>=129 && ReadChannel[k]<=132 && ReadValue[k]>QQQThreshold){ //QQQ5 upstream 1 back
								QuIn[0].Sector.ReadE[QuIn[0].Sector.Emult]=ReadValue[k];
								QuIn[0].Sector.Echan[QuIn[0].Sector.Emult]=ReadChannel[k]-128;
								QuIn[0].Sector.Emult++;
							}else if(ReadChannel[k]>=133 && ReadChannel[k]<=136 && ReadValue[k]>QQQThreshold){ //QQQ5 upstream 1 back
								QuIn[1].Sector.ReadE[QuIn[1].Sector.Emult]=ReadValue[k];
								QuIn[1].Sector.Echan[QuIn[1].Sector.Emult]=ReadChannel[k]-132;
								QuIn[1].Sector.Emult++;
							}else if(ReadChannel[k]>=137 && ReadChannel[k]<=140 && ReadValue[k]>QQQThreshold){ //QQQ5 upstream 1 back
								QuIn[2].Sector.ReadE[QuIn[2].Sector.Emult]=ReadValue[k];
								QuIn[2].Sector.Echan[QuIn[2].Sector.Emult]=ReadChannel[k]-136;
								QuIn[2].Sector.Emult++;
							}else if(ReadChannel[k]>=141 && ReadChannel[k]<=144 && ReadValue[k]>QQQThreshold){ //QQQ5 upstream 1 back
								QuIn[3].Sector.ReadE[QuIn[3].Sector.Emult]=ReadValue[k];
								QuIn[3].Sector.Echan[QuIn[3].Sector.Emult]=ReadChannel[k]-140;
								QuIn[3].Sector.Emult++;

							//Upstream SX3 Back
							}else if(ReadChannel[k]>=145 && ReadChannel[k]<=148 && ReadValue[k]>SX3backThreshold){//SX3u1 Back
								SX3u1->SetBackHits(ReadChannel[k]-145);
								SX3u1->SetRawBackEnergy(ReadValue[k]);
								SX3u1->IncrementBmult();
							}else if(ReadChannel[k]>=149 && ReadChannel[k]<=152 && ReadValue[k]>SX3backThreshold){//SX3u2 Back
								SX3u2->SetBackHits(ReadChannel[k]-149);
								SX3u2->SetRawBackEnergy(ReadValue[k]);
								SX3u2->IncrementBmult();
							}else if(ReadChannel[k]>=153 && ReadChannel[k]<=156 && ReadValue[k]>SX3backThreshold){//SX3u3 Back
								SX3u3->SetBackHits(ReadChannel[k]-153);
								SX3u3->SetRawBackEnergy(ReadValue[k]);
								SX3u3->IncrementBmult();
							}else if(ReadChannel[k]>=157 && ReadChannel[k]<=160 && ReadValue[k]>SX3backThreshold){//SX3u4 Back
								SX3u4->SetBackHits(ReadChannel[k]-157);
								SX3u4->SetRawBackEnergy(ReadValue[k]);
								SX3u4->IncrementBmult();
							}else if(ReadChannel[k]>=177 && ReadChannel[k]<=180 && ReadValue[k]>SX3backThreshold){//SX3u5 Back
								SX3u5->SetBackHits(ReadChannel[k]-177);
								SX3u5->SetRawBackEnergy(ReadValue[k]);
								SX3u5->IncrementBmult();
							}else if(ReadChannel[k]>=181 && ReadChannel[k]<=184 && ReadValue[k]>SX3backThreshold){//SX3u6 Back
								SX3u6->SetBackHits(ReadChannel[k]-181);
								SX3u6->SetRawBackEnergy(ReadValue[k]);
								SX3u6->IncrementBmult();
							}else if(ReadChannel[k]>=161 && ReadChannel[k]<=164 && ReadValue[k]>SX3backThreshold){//SX3u7 Back
								SX3u7->SetBackHits(ReadChannel[k]-161);
								SX3u7->SetRawBackEnergy(ReadValue[k]);
								SX3u7->IncrementBmult();
							}else if(ReadChannel[k]>=165 && ReadChannel[k]<=168 && ReadValue[k]>SX3backThreshold){//SX3u8 Back
								SX3u8->SetBackHits(ReadChannel[k]-165);
								SX3u8->SetRawBackEnergy(ReadValue[k]);
								SX3u8->IncrementBmult();
							}else if(ReadChannel[k]>=169 && ReadChannel[k]<=172 && ReadValue[k]>SX3backThreshold){//SX3u9 Back
								SX3u9->SetBackHits(ReadChannel[k]-169);
								SX3u9->SetRawBackEnergy(ReadValue[k]);
								SX3u9->IncrementBmult();
							}else if(ReadChannel[k]>=173 && ReadChannel[k]<=176 && ReadValue[k]>SX3backThreshold){//SX3u10 Back
								SX3u10->SetBackHits(ReadChannel[k]-173);
								SX3u10->SetRawBackEnergy(ReadValue[k]);
								SX3u10->IncrementBmult();
							}else if(ReadChannel[k]>=185 && ReadChannel[k]<=188 && ReadValue[k]>SX3backThreshold){//SX3u11 Back
								SX3u11->SetBackHits(ReadChannel[k]-185);
								SX3u11->SetRawBackEnergy(ReadValue[k]);
								SX3u11->IncrementBmult();
							}else if(ReadChannel[k]>=189 && ReadChannel[k]<=192 && ReadValue[k]>SX3backThreshold){//SX3u12 Back
								SX3u12->SetBackHits(ReadChannel[k]-189);
								SX3u12->SetRawBackEnergy(ReadValue[k]);
								SX3u12->IncrementBmult();

							//Upstream SX3 Front
							}else if(ReadChannel[k]>=193 && ReadChannel[k]<=200){ //SX3u1 front
								if( (ReadChannel[k]-193)%2 == 0 ){ //Left side
									SX3u1->SetLeftHits((int)(ReadChannel[k]-193)/2);
									SX3u1->SetRawLeft(ReadValue[k]);
									SX3u1->IncrementLmult();
								}else{ //Right side
									SX3u1->SetRightHits((int)(ReadChannel[k]-193-1)/2);
									SX3u1->SetRawRight(ReadValue[k]);
									SX3u1->IncrementRmult();
								}
							}else if(ReadChannel[k]>=201 && ReadChannel[k]<=208){ //SX3u2 front
								if( (ReadChannel[k]-201)%2 == 0 ){ //Left side
									SX3u2->SetLeftHits((int)(ReadChannel[k]-201)/2);
									SX3u2->SetRawLeft(ReadValue[k]);
									SX3u2->IncrementLmult();
								}else{ //Right side
									SX3u2->SetRightHits((int)(ReadChannel[k]-201-1)/2);
									SX3u2->SetRawRight(ReadValue[k]);
									SX3u2->IncrementRmult();
								}
							}else if(ReadChannel[k]>=209 && ReadChannel[k]<=216){ //SX3u3 front
								if( (ReadChannel[k]-209)%2 == 0 ){ //Left side
									SX3u3->SetLeftHits((int)(ReadChannel[k]-209)/2);
									SX3u3->SetRawLeft(ReadValue[k]);
									SX3u3->IncrementLmult();
								}else{ //Right side
									SX3u3->SetRightHits((int)(ReadChannel[k]-209-1)/2);
									SX3u3->SetRawRight(ReadValue[k]);
									SX3u3->IncrementRmult();
								}
							}else if(ReadChannel[k]>=217 && ReadChannel[k]<=224){ //SX3u4 front
								if( (ReadChannel[k]-217)%2 == 0 ){ //Left side
									SX3u4->SetLeftHits((int)(ReadChannel[k]-217)/2);
									SX3u4->SetRawLeft(ReadValue[k]);
									SX3u4->IncrementLmult();
								}else{ //Right side
									SX3u4->SetRightHits((int)(ReadChannel[k]-217-1)/2);
									SX3u4->SetRawRight(ReadValue[k]);
									SX3u4->IncrementRmult();
								}
							}else if(ReadChannel[k]>=225 && ReadChannel[k]<=232){ //SX3u5 front
								if( (ReadChannel[k]-225)%2 == 0 ){ //Left side
									SX3u5->SetLeftHits((int)(ReadChannel[k]-225)/2);
									SX3u5->SetRawLeft(ReadValue[k]);
									SX3u5->IncrementLmult();
								}else{ //Right side
									SX3u5->SetRightHits((int)(ReadChannel[k]-225-1)/2);
									SX3u5->SetRawRight(ReadValue[k]);
									SX3u5->IncrementRmult();
								}
							}else if(ReadChannel[k]>=233 && ReadChannel[k]<=240){ //SX3u6 front
								if( (ReadChannel[k]-233)%2 == 0 ){ //Left side
									SX3u6->SetLeftHits((int)(ReadChannel[k]-233)/2);
									SX3u6->SetRawLeft(ReadValue[k]);
									SX3u6->IncrementLmult();
								}else{ //Right side
									SX3u6->SetRightHits((int)(ReadChannel[k]-233-1)/2);
									SX3u6->SetRawRight(ReadValue[k]);
									SX3u6->IncrementRmult();
								}
							}else if(ReadChannel[k]>=241 && ReadChannel[k]<=248){ //SX3u7 front
								if( (ReadChannel[k]-241)%2 == 0 ){ //Left side
									SX3u7->SetLeftHits((int)(ReadChannel[k]-241)/2);
									SX3u7->SetRawLeft(ReadValue[k]);
									SX3u7->IncrementLmult();
								}else{ //Right side
									SX3u7->SetRightHits((int)(ReadChannel[k]-241-1)/2);
									SX3u7->SetRawRight(ReadValue[k]);
									SX3u7->IncrementRmult();
								}
							}else if(ReadChannel[k]>=249 && ReadChannel[k]<=256){ //SX3u8 front
								if( (ReadChannel[k]-249)%2 == 0 ){ //Left side
									SX3u8->SetLeftHits((int)(ReadChannel[k]-249)/2);
									SX3u8->SetRawLeft(ReadValue[k]);
									SX3u8->IncrementLmult();
								}else{ //Right side
									SX3u8->SetRightHits((int)(ReadChannel[k]-249-1)/2);
									SX3u8->SetRawRight(ReadValue[k]);
									SX3u8->IncrementRmult();
								}
							}else if(ReadChannel[k]>=257 && ReadChannel[k]<=264){ //SX3u9 front
								if( (ReadChannel[k]-257)%2 == 0 ){ //Left side
									SX3u9->SetLeftHits((int)(ReadChannel[k]-257)/2);
									SX3u9->SetRawLeft(ReadValue[k]);
									SX3u9->IncrementLmult();
								}else{ //Right side
									SX3u9->SetRightHits((int)(ReadChannel[k]-257-1)/2);
									SX3u9->SetRawRight(ReadValue[k]);
									SX3u9->IncrementRmult();
								}
							}else if(ReadChannel[k]>=265 && ReadChannel[k]<=272){ //SX3u10 front
								if( (ReadChannel[k]-265)%2 == 0 ){ //Left side
									SX3u10->SetLeftHits((int)(ReadChannel[k]-265)/2);
									SX3u10->SetRawLeft(ReadValue[k]);
									SX3u10->IncrementLmult();
								}else{ //Right side
									SX3u10->SetRightHits((int)(ReadChannel[k]-265-1)/2);
									SX3u10->SetRawRight(ReadValue[k]);
									SX3u10->IncrementRmult();
								}
							}else if(ReadChannel[k]>=273 && ReadChannel[k]<=280){ //SX3u11 front
								if( (ReadChannel[k]-273)%2 == 0 ){ //Left side
									SX3u11->SetLeftHits((int)(ReadChannel[k]-273)/2);
									SX3u11->SetRawLeft(ReadValue[k]);
									SX3u11->IncrementLmult();
								}else{ //Right side
									SX3u11->SetRightHits((int)(ReadChannel[k]-273-1)/2);
									SX3u11->SetRawRight(ReadValue[k]);
									SX3u11->IncrementRmult();
								}
							}else if(ReadChannel[k]>=281 && ReadChannel[k]<=288){ //SX3u12 front
								if( (ReadChannel[k]-281)%2 == 0 ){ //Left side
									SX3u12->SetLeftHits((int)(ReadChannel[k]-281)/2);
									SX3u12->SetRawLeft(ReadValue[k]);
									SX3u12->IncrementLmult();
								}else{ //Right side
									SX3u12->SetRightHits((int)(ReadChannel[k]-281-1)/2);
									SX3u12->SetRawRight(ReadValue[k]);
									SX3u12->IncrementRmult();
								}

							//Downstream SX3 Front
							}else if(ReadChannel[k]>=289 && ReadChannel[k]<=296){ //SX3d1 front
								if( (ReadChannel[k]-289)%2 == 0 ){ //Left side
									SX3d1->SetLeftHits((int)(ReadChannel[k]-289)/2);
									SX3d1->SetRawLeft(ReadValue[k]);
									SX3d1->IncrementLmult();
								}else{ //Right side
									SX3d1->SetRightHits((int)(ReadChannel[k]-289-1)/2);
									SX3d1->SetRawRight(ReadValue[k]);
									SX3d1->IncrementRmult();
								}
							}else if(ReadChannel[k]>=297 && ReadChannel[k]<=304){ //SX3d2 front
								if( (ReadChannel[k]-297)%2 == 0 ){ //Left side
									SX3d2->SetLeftHits((int)(ReadChannel[k]-297)/2);
									SX3d2->SetRawLeft(ReadValue[k]);
									SX3d2->IncrementLmult();
								}else{ //Right side
									SX3d2->SetRightHits((int)(ReadChannel[k]-297-1)/2);
									SX3d2->SetRawRight(ReadValue[k]);
									SX3d2->IncrementRmult();
								}
							}else if(ReadChannel[k]>=305 && ReadChannel[k]<=312){ //SX3d3 front
								if( (ReadChannel[k]-305)%2 == 0 ){ //Left side
									SX3d3->SetLeftHits((int)(ReadChannel[k]-305)/2);
									SX3d3->SetRawLeft(ReadValue[k]);
									SX3d3->IncrementLmult();
								}else{ //Right side
									SX3d3->SetRightHits((int)(ReadChannel[k]-305-1)/2);
									SX3d3->SetRawRight(ReadValue[k]);
									SX3d3->IncrementRmult();
								}
							}else if(ReadChannel[k]>=313 && ReadChannel[k]<=320){ //SX3d4 front
								if( (ReadChannel[k]-313)%2 == 0 ){ //Left side
									SX3d4->SetLeftHits((int)(ReadChannel[k]-313)/2);
									SX3d4->SetRawLeft(ReadValue[k]);
									SX3d4->IncrementLmult();
								}else{ //Right side
									SX3d4->SetRightHits((int)(ReadChannel[k]-313-1)/2);
									SX3d4->SetRawRight(ReadValue[k]);
									SX3d4->IncrementRmult();
								}
							}else if(ReadChannel[k]>=321 && ReadChannel[k]<=328){ //SX3d5 front
								if( (ReadChannel[k]-321)%2 == 0 ){ //Left side
									SX3d5->SetLeftHits((int)(ReadChannel[k]-321)/2);
									SX3d5->SetRawLeft(ReadValue[k]);
									SX3d5->IncrementLmult();
								}else{ //Right side
									SX3d5->SetRightHits((int)(ReadChannel[k]-321-1)/2);
									SX3d5->SetRawRight(ReadValue[k]);
									SX3d5->IncrementRmult();
								}
							}else if(ReadChannel[k]>=329 && ReadChannel[k]<=336){ //SX3d6 front
								if( (ReadChannel[k]-329)%2 == 0 ){ //Left side
									SX3d6->SetLeftHits((int)(ReadChannel[k]-329)/2);
									SX3d6->SetRawLeft(ReadValue[k]);
									SX3d6->IncrementLmult();
								}else{ //Right side
									SX3d6->SetRightHits((int)(ReadChannel[k]-329-1)/2);
									SX3d6->SetRawRight(ReadValue[k]);
									SX3d6->IncrementRmult();
								}
							}else if(ReadChannel[k]>=337 && ReadChannel[k]<=344){ //SX3d7 front
								if( (ReadChannel[k]-337)%2 == 0 ){ //Left side
									SX3d7->SetLeftHits((int)(ReadChannel[k]-337)/2);
									SX3d7->SetRawLeft(ReadValue[k]);
									SX3d7->IncrementLmult();
								}else{ //Right side
									SX3d7->SetRightHits((int)(ReadChannel[k]-337-1)/2);
									SX3d7->SetRawRight(ReadValue[k]);
									SX3d7->IncrementRmult();
								}
							}else if(ReadChannel[k]>=345 && ReadChannel[k]<=352){ //SX3d8 front
								if( (ReadChannel[k]-345)%2 == 0 ){ //Left side
									SX3d8->SetLeftHits((int)(ReadChannel[k]-345)/2);
									SX3d8->SetRawLeft(ReadValue[k]);
									SX3d8->IncrementLmult();
								}else{ //Right side
									SX3d8->SetRightHits((int)(ReadChannel[k]-345-1)/2);
									SX3d8->SetRawRight(ReadValue[k]);
									SX3d8->IncrementRmult();
								}
							}else if(ReadChannel[k]>=353 && ReadChannel[k]<=360){ //SX3d9 front
								if( (ReadChannel[k]-353)%2 == 0 ){ //Left side
									SX3d9->SetLeftHits((int)(ReadChannel[k]-353)/2);
									SX3d9->SetRawLeft(ReadValue[k]);
									SX3d9->IncrementLmult();
								}else{ //Right side
									SX3d9->SetRightHits((int)(ReadChannel[k]-353-1)/2);
									SX3d9->SetRawRight(ReadValue[k]);
									SX3d9->IncrementRmult();
								}
							}else if(ReadChannel[k]>=361 && ReadChannel[k]<=368){ //SX3d10 front
								if( (ReadChannel[k]-361)%2 == 0 ){ //Left side
									SX3d10->SetLeftHits((int)(ReadChannel[k]-361)/2);
									SX3d10->SetRawLeft(ReadValue[k]);
									SX3d10->IncrementLmult();
								}else{ //Right side
									SX3d10->SetRightHits((int)(ReadChannel[k]-361-1)/2);
									SX3d10->SetRawRight(ReadValue[k]);
									SX3d10->IncrementRmult();
								}
							}else if(ReadChannel[k]>=369 && ReadChannel[k]<=376){ //SX3d11 front
								if( (ReadChannel[k]-369)%2 == 0 ){ //Left side
									SX3d11->SetLeftHits((int)(ReadChannel[k]-369)/2);
									SX3d11->SetRawLeft(ReadValue[k]);
									SX3d11->IncrementLmult();
								}else{ //Right side
									SX3d11->SetRightHits((int)(ReadChannel[k]-369-1)/2);
									SX3d11->SetRawRight(ReadValue[k]);
									SX3d11->IncrementRmult();
								}
							}else if(ReadChannel[k]>=377 && ReadChannel[k]<=384){ //SX3d12 front
								if( (ReadChannel[k]-377)%2 == 0 ){ //Left side
									SX3d12->SetLeftHits((int)(ReadChannel[k]-377)/2);
									SX3d12->SetRawLeft(ReadValue[k]);
									SX3d12->IncrementLmult();
								}else{ //Right side
									SX3d12->SetRightHits((int)(ReadChannel[k]-377-1)/2);
									SX3d12->SetRawRight(ReadValue[k]);
									SX3d12->IncrementRmult();
								}

							//Downstream SX3 Backs
							}else if(ReadChannel[k]>=385 && ReadChannel[k]<=388 && ReadValue[k]>SX3backThreshold){//SX3d1 Back
								SX3d1->SetBackHits(ReadChannel[k]-385);
								SX3d1->SetRawBackEnergy(ReadValue[k]);
								SX3d1->IncrementBmult();
							}else if(ReadChannel[k]>=389 && ReadChannel[k]<=392 && ReadValue[k]>SX3backThreshold){//SX3d2 Back
								SX3d2->SetBackHits(ReadChannel[k]-389);
								SX3d2->SetRawBackEnergy(ReadValue[k]);
								SX3d2->IncrementBmult();
							}else if(ReadChannel[k]>=393 && ReadChannel[k]<=396 && ReadValue[k]>SX3backThreshold){//SX3d3 Back
								SX3d3->SetBackHits(ReadChannel[k]-393);
								SX3d3->SetRawBackEnergy(ReadValue[k]);
								SX3d3->IncrementBmult();
							}else if(ReadChannel[k]>=397 && ReadChannel[k]<=400 && ReadValue[k]>SX3backThreshold){//SX3d4 Back
								SX3d4->SetBackHits(ReadChannel[k]-397);
								SX3d4->SetRawBackEnergy(ReadValue[k]);
								SX3d4->IncrementBmult();
							}else if(ReadChannel[k]>=401 && ReadChannel[k]<=404 && ReadValue[k]>SX3backThreshold){//SX3d5 Back
								SX3d5->SetBackHits(ReadChannel[k]-401);
								SX3d5->SetRawBackEnergy(ReadValue[k]);
								SX3d5->IncrementBmult();
							}else if(ReadChannel[k]>=405 && ReadChannel[k]<=408 && ReadValue[k]>SX3backThreshold){//SX3d6 Back
								SX3d6->SetBackHits(ReadChannel[k]-405);
								SX3d6->SetRawBackEnergy(ReadValue[k]);
								SX3d6->IncrementBmult();
							}else if(ReadChannel[k]>=409 && ReadChannel[k]<=412 && ReadValue[k]>SX3backThreshold){//SX3d7 Back
								SX3d7->SetBackHits(ReadChannel[k]-409);
								SX3d7->SetRawBackEnergy(ReadValue[k]);
								SX3d7->IncrementBmult();
							}else if(ReadChannel[k]>=413 && ReadChannel[k]<=416 && ReadValue[k]>SX3backThreshold){//SX3d8 Back
								SX3d8->SetBackHits(ReadChannel[k]-413);
								SX3d8->SetRawBackEnergy(ReadValue[k]);
								SX3d8->IncrementBmult();
							}else if(ReadChannel[k]>=417 && ReadChannel[k]<=420 && ReadValue[k]>SX3backThreshold){//SX3d9 Back
								SX3d9->SetBackHits(ReadChannel[k]-417);
								SX3d9->SetRawBackEnergy(ReadValue[k]);
								SX3d9->IncrementBmult();
							}else if(ReadChannel[k]>=421 && ReadChannel[k]<=424 && ReadValue[k]>SX3backThreshold){//SX3d10 Back
								SX3d10->SetBackHits(ReadChannel[k]-421);
								SX3d10->SetRawBackEnergy(ReadValue[k]);
								SX3d10->IncrementBmult();
							}else if(ReadChannel[k]>=425 && ReadChannel[k]<=428 && ReadValue[k]>SX3backThreshold){//SX3d11 Back
								SX3d11->SetBackHits(ReadChannel[k]-425);
								SX3d11->SetRawBackEnergy(ReadValue[k]);
								SX3d11->IncrementBmult();
							}else if(ReadChannel[k]>=429 && ReadChannel[k]<=432 && ReadValue[k]>SX3backThreshold){//SX3d12 Back
								SX3d12->SetBackHits(ReadChannel[k]-429);
								SX3d12->SetRawBackEnergy(ReadValue[k]);
								SX3d12->IncrementBmult();

							//BB10
							}else if(ReadChannel[k]>=433 && ReadChannel[k]<=440 && ReadValue[k]>BB10Threshold){//BB10_1
								BB10_1->SetFrontHits(ReadChannel[k]-433);
								BB10_1->SetRawEnergy(ReadValue[k]);
								BB10_1->IncrementMult();
							}else if(ReadChannel[k]>=441 && ReadChannel[k]<=448 && ReadValue[k]>BB10Threshold){//BB10_2
								BB10_2->SetFrontHits(ReadChannel[k]-441);
								BB10_2->SetRawEnergy(ReadValue[k]);
								BB10_2->IncrementMult();
							}else if(ReadChannel[k]>=449 && ReadChannel[k]<=456 && ReadValue[k]>BB10Threshold){//BB10_3
								BB10_3->SetFrontHits(ReadChannel[k]-449);
								BB10_3->SetRawEnergy(ReadValue[k]);
								BB10_3->IncrementMult();
							}else if(ReadChannel[k]>=457 && ReadChannel[k]<=464 && ReadValue[k]>BB10Threshold){//BB10_4
								BB10_4->SetFrontHits(ReadChannel[k]-457);
								BB10_4->SetRawEnergy(ReadValue[k]);
								BB10_4->IncrementMult();
							}else if(ReadChannel[k]>=465 && ReadChannel[k]<=472 && ReadValue[k]>BB10Threshold){//BB10_5
								BB10_5->SetFrontHits(ReadChannel[k]-465);
								BB10_5->SetRawEnergy(ReadValue[k]);
								BB10_5->IncrementMult();
							}else if(ReadChannel[k]>=473 && ReadChannel[k]<=480 && ReadValue[k]>BB10Threshold){//BB10_6
								BB10_6->SetFrontHits(ReadChannel[k]-473);
								BB10_6->SetRawEnergy(ReadValue[k]);
								BB10_6->IncrementMult();
							}else if(ReadChannel[k]>=481 && ReadChannel[k]<=488 && ReadValue[k]>BB10Threshold){//BB10_7
								BB10_7->SetFrontHits(ReadChannel[k]-481);
								BB10_7->SetRawEnergy(ReadValue[k]);
								BB10_7->IncrementMult();
							}else if(ReadChannel[k]>=489 && ReadChannel[k]<=496 && ReadValue[k]>BB10Threshold){//BB10_8
								BB10_8->SetFrontHits(ReadChannel[k]-489);
								BB10_8->SetRawEnergy(ReadValue[k]);
								BB10_8->IncrementMult();





							//Downstream QQQ5 Front and back
							}else if(ReadChannel[k]>=513 && ReadChannel[k]<=544 && ReadValue[k]>QQQThreshold){ //QQQ5 downstream 1 front
								QdIn[0].Ring.ReadE[QdIn[0].Ring.Emult]=ReadValue[k];
								QdIn[0].Ring.Echan[QdIn[0].Ring.Emult]=ReadChannel[k]-512;
								QdIn[0].Ring.Emult++;
							}else if(ReadChannel[k]>=545 && ReadChannel[k]<=576 && ReadValue[k]>QQQThreshold){ //QQQ5 downstream 2 front
								QdIn[1].Ring.ReadE[QdIn[1].Ring.Emult]=ReadValue[k];
								QdIn[1].Ring.Echan[QdIn[1].Ring.Emult]=ReadChannel[k]-544;
								QdIn[1].Ring.Emult++;
							}else if(ReadChannel[k]>=577 && ReadChannel[k]<=608 && ReadValue[k]>QQQThreshold){ //QQQ5 downstream 3 front
								QdIn[2].Ring.ReadE[QdIn[2].Ring.Emult]=ReadValue[k];
								QdIn[2].Ring.Echan[QdIn[2].Ring.Emult]=ReadChannel[k]-576;
								QdIn[2].Ring.Emult++;
							}else if(ReadChannel[k]>=497 && ReadChannel[k]<=500 && ReadValue[k]>QQQThreshold){ //QQQ5 downstream 1 Back
								QdIn[0].Ring.ReadE[QdIn[0].Ring.Emult]=ReadValue[k];
								QdIn[0].Ring.Echan[QdIn[0].Ring.Emult]=ReadChannel[k]-496;
								QdIn[0].Ring.Emult++;
							}else if(ReadChannel[k]>=501 && ReadChannel[k]<=504 && ReadValue[k]>QQQThreshold){ //QQQ5 downstream 2 Back
								QdIn[1].Ring.ReadE[QdIn[1].Ring.Emult]=ReadValue[k];
								QdIn[1].Ring.Echan[QdIn[1].Ring.Emult]=ReadChannel[k]-500;
								QdIn[1].Ring.Emult++;
							}else if(ReadChannel[k]>=505 && ReadChannel[k]<=508 && ReadValue[k]>QQQThreshold){ //QQQ5 downstream 3 Back
								QdIn[2].Ring.ReadE[QdIn[2].Ring.Emult]=ReadValue[k];
								QdIn[2].Ring.Echan[QdIn[2].Ring.Emult]=ReadChannel[k]-504;
								QdIn[2].Ring.Emult++;

							//IC
							}else if(ReadChannel[k]==739){//IC dE
								ICdEin = ReadValue[k];
							}else if(ReadChannel[k]==740){//IC E
								ICEin = ReadValue[k];

							//TDC
							}else if(ReadChannel[k]==818){
								TDCin=ReadValue[k];
							}
						}//End of Sub-event loop

						//Reset Detector values
						for(int i = 0; i < 4; i++) {
						    Qu[i]->ResetAll();
						}
						for(int i = 0; i < 3; i++) {
						    Qd[i]->ResetAll();
						}

						IC->ResetAll();
						TDC->ResetAll();

						Success=false;
						ICyeah=false;
						SX3yeah=false;
						SX3check=false;

						//Call Detector Processors
						Success = ProcessQQQ5(Qu, Qd, QuIn, QdIn);//Added the downstream
						ICyeah = ProcessIC(*IC, ICdEin, ICEin);


						SX3check = ProcessSX3(1,*SX3u1);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(2,*SX3u2);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(3,*SX3u3);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(4,*SX3u4);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(5,*SX3u5);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(6,*SX3u6);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(7,*SX3u7);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(8,*SX3u8);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(9,*SX3u9);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(10,*SX3u10);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(11,*SX3u11);
						if(SX3check) SX3yeah=true;
						SX3check = ProcessSX3(12,*SX3u12);
						if(SX3check) SX3yeah=true;

					//	SX3gainYeah = ApplyGainMatch(5,*SX3u5);

						TDC->SetValue(TDCin);

						//If anything fires fill tree
						if(Success || ICyeah || SX3yeah){
							Tree->Fill();
						}

						SX3u1->ResetAll();
						SX3u2->ResetAll();
						SX3u3->ResetAll();
						SX3u4->ResetAll();
						SX3u5->ResetAll();
						SX3u6->ResetAll();
						SX3u7->ResetAll();
						SX3u8->ResetAll();
						SX3u9->ResetAll();
						SX3u10->ResetAll();
						SX3u11->ResetAll();
						SX3u12->ResetAll();

						SX3d1->ResetAll();
						SX3d2->ResetAll();
						SX3d3->ResetAll();
						SX3d4->ResetAll();
						SX3d5->ResetAll();
						SX3d6->ResetAll();
						SX3d7->ResetAll();
						SX3d8->ResetAll();
						SX3d9->ResetAll();
						SX3d10->ResetAll();
						SX3d11->ResetAll();
						SX3d12->ResetAll();

						BB10_1->ResetAll();
						BB10_2->ResetAll();
						BB10_3->ResetAll();
						BB10_4->ResetAll();
						BB10_5->ResetAll();
						BB10_6->ResetAll();
						BB10_7->ResetAll();
						BB10_8->ResetAll();

						//Reset Read Arrays
						ResetInStructs();

						ReadChannel.clear();
						ReadValue.clear();

						EventMult->Fill(Counter);
						Counter = 0;
						NumberEvents++;

						RunClock = clock();
						if(NumberEvents%NumberEventsPerPrint==0){
							std::cout<<"\r"<<std::flush;
							std::cout<<PrintOutput("Events Processed","green")<<" = "<<NumberEvents<<"\t";
							std::cout<<PrintOutput("Time","green")<<" = "<<Form("%.02f",(RunClock-StartClock)/double(CLOCKS_PER_SEC))<<" seconds"<<std::flush;
						}
					}
				}
			}
			NumberBuffer++;
		} //End of main loop over file
		//std::cout<<std::endl;
		RootFile->Write();
		RootFile->Close();

		file.close();
		RunClock = clock();
		std::cout<<"\r"<<std::flush;
		std::cout<<PrintOutput("Events Processed","green")<<" = "<<NumberEvents<<"\t";
		std::cout<<PrintOutput("Time","green")<<" = "<<Form("%.02f",(RunClock-StartClock)/double(CLOCKS_PER_SEC))<<" seconds"<<std::flush;
		std::cout<<std::endl;
		//std::cout << "Number of events processed = " << NumberEvents << std::endl;
		std::cout << PrintOutput("Finished Sorting:  ","green") << DataFileName << std::endl;
		std::cout << PrintOutput("Created root file : ","green")<< RootFile->GetName()<< std::endl;

	//}//end of RunList Loop

	std::cout << PrintOutput("************************************************","yellow")<<std::endl;
	std::cout << PrintOutput("Finished Sorting ","yellow") << rn << PrintOutput(" files!","yellow") <<  std::endl;
	return 0;
}






