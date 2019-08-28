#include "Utilities.h"
#include "Sort.h"

unsigned int ExtractBits(unsigned int Source, int Begin, int Length){
    return (Source >> Begin) & ((1 << Length) - 1);
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
