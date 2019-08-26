#include "Utilities.h"
#include "Sort.h"

unsigned int ExtractBits(unsigned int Source, int Begin, int Length){
    return (Source >> Begin) & ((1 << Length) - 1);
}

void ResetInStructs(){
	//Upstream QQQ5
	for(int k=0; k<4; k++){
	 	for(int i=0; i<32; i++){
	 		QuIn[k].Ring.ReadE[i]=0;
	 		QuIn[k].Ring.Echan[i]=-1;
	 		QuIn[k].Ring.RawE[i]=0;
	 		QuIn[k].Ring.Eid[i]=-1;

	 		Qu1in.Ring.ReadE[i]=0;
	 		Qu1in.Ring.Echan[i]=-1;
	 		Qu1in.Ring.RawE[i]=0;
	 		Qu1in.Ring.Eid[i]=-1;
	 	}

	 	for(int i=0; i<8; i++){
	 		QuIn[k].Sector.ReadE[i]=0;
	 		QuIn[k].Sector.Echan[i]=-1;
	 		QuIn[k].Sector.RawE[i]=0;
	 		QuIn[k].Sector.Eid[i]=-1;

	 		Qu1in.Sector.ReadE[i]=0;
	 		Qu1in.Sector.Echan[i]=-1;
	 		Qu1in.Sector.RawE[i]=0;
	 		Qu1in.Sector.Eid[i]=-1;
	 	}

	 	QuIn[k].Ring.Emult=0;
	 	QuIn[k].Sector.Emult=0;

	 	Qu1in.Ring.Emult=0;
	 	Qu1in.Sector.Emult=0;
	 }

	//Downstream QQQ5
	for(int k=0; k<3; k++){
	 	for(int i=0; i<32; i++){
	 		QdIn[k].Ring.ReadE[i]=0;
	 		QdIn[k].Ring.Echan[i]=-1;
	 		QdIn[k].Ring.RawE[i]=0;
	 		QdIn[k].Ring.Eid[i]=-1;

	 		Qd1in.Ring.ReadE[i]=0;
	 		Qd1in.Ring.Echan[i]=-1;
	 		Qd1in.Ring.RawE[i]=0;
	 		Qd1in.Ring.Eid[i]=-1;
	 	}

	 	for(int i=0; i<8; i++){
	 		QdIn[k].Sector.ReadE[i]=0;
	 		QdIn[k].Sector.Echan[i]=-1;
	 		QdIn[k].Sector.RawE[i]=0;
	 		QdIn[k].Sector.Eid[i]=-1;

	 		Qd1in.Sector.ReadE[i]=0;
	 		Qd1in.Sector.Echan[i]=-1;
	 		Qd1in.Sector.RawE[i]=0;
	 		Qd1in.Sector.Eid[i]=-1;
	 	}

	 	QdIn[k].Ring.Emult=0;
	 	QdIn[k].Sector.Emult=0;

	 	Qd1in.Ring.Emult=0;
	 	Qd1in.Sector.Emult=0;
	 }

	 ICdEin=0;
	 ICEin=0;

	 TDCin=0;


 }

 std::string PrintOutput(std::string Output, std::string Color){

	int ColorCode = 0;

	if(Color.compare("red") == 0){
		ColorCode = 31;
	} else if(Color.compare("green") == 0){
		ColorCode = 32;
	} else if(Color.compare("yellow") == 0){
		ColorCode = 33;
	} else if(Color.compare("blue") == 0){
		ColorCode = 34;
	} else {
		std::cout << Form("Output Color not recognized : %s", Color.c_str()) << std::endl;
		return Form("%s", Output.c_str());
	}

	return Form("\033[1;%dm%s\033[0m", ColorCode, Output.c_str());

}
