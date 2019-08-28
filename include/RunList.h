#ifndef RUNLIST_H
#define RUNLIST_H

#include "TypeDef.h"

#include <iostream>
#include <string>
#include <vector>

class RunList {
public:
    RunList();
    ~RunList();

    std::vector<fileListStruct> GetListOfRuns() {return listOfRuns;}

private:
    void CompileListOfRuns();
    void GetAllRuns();

    std::vector<fileListStruct> listOfRuns;

    std::string pathToFolders;
    std::string outputPath;
    bool useAllFolders;
    std::string pathPrefix;
    std::string ldfPrefix;
};

#endif
