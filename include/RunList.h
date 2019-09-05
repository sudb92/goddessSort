#ifndef RUNLIST_H
#define RUNLIST_H

#include "json/json.h"
#include "TypeDef.h"
#include "Utilities.h"

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

    std::vector<std::string> runNumbers;
    std::vector<fileListStruct> listOfRuns;

    std::string pathToFolders;
    std::string pathPrefix;
    std::string ldfPrefix;
    std::string outputPath;
    bool copyCuts;
    std::string cutPrefix;
    bool useAllFolders;
    std::vector<std::string> listNumbers;
};

#endif
