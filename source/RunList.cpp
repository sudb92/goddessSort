#include "RunList.h"

RunList::RunList() {
    pathToFolders = "/Users/joshhooker/physics/utk/research/GoddessFiles/RunFolder/";
    useAllFolders = false;
    pathPrefix = "Run";
    ldfPrefix = "p30dp";

    outputPath = "/Users/joshhooker/physics/utk/research/GoddessFiles/OutputFolder/";

    if(!useAllFolders) CompileListOfRuns();
    else GetAllRuns();
}

RunList::~RunList() {}

void RunList::CompileListOfRuns() {
    std::vector<std::string> listNumbers = {"0255"};

    for(auto run: listNumbers) {
        std::string ldfPath = pathToFolders + pathPrefix + run + '/' + ldfPrefix + run + ".ldf";
        std::string rootPath = outputPath + pathPrefix + run + ".root";
        std::cout << '\t' << ldfPath << std::endl;
        listOfRuns.push_back(ldfPath);
        listOfOutputs.push_back(rootPath);
    }
}

void RunList::GetAllRuns() {}




