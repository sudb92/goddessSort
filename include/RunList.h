#ifndef RUNLIST_H
#define RUNLIST_H

#include <iostream>
#include <string>
#include <vector>

class RunList {
public:
    RunList();
    ~RunList();

    std::pair<std::vector<std::string>, std::vector<std::string> > GetListOfRuns() {return std::make_pair(listOfRuns, listOfOutputs);}

private:
    void CompileListOfRuns();
    void GetAllRuns();

    std::string pathToFolders;
    std::string outputPath;
    std::vector<std::string> listOfRuns;
    std::vector<std::string> listOfOutputs;
    bool useAllFolders;
    std::string pathPrefix;
    std::string ldfPrefix;
};

#endif
