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

RunList::~RunList() = default;

void RunList::CompileListOfRuns() {
    std::vector<std::string> listNumbers = {"0255"};

    listOfRuns.clear();
    for(auto run: listNumbers) {
        std::string ldfPath = pathToFolders + pathPrefix + run + '/' + ldfPrefix + run + ".ldf";
        std::string rootPath = outputPath + pathPrefix + run + ".root";

        fileListStruct indFile = {pathToFolders, outputPath, ldfPath, rootPath, run};
        listOfRuns.push_back(indFile);
    }
}

void RunList::GetAllRuns() {}




