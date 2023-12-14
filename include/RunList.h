#ifndef RunList_h
#define RunList_h

#include "json/json.h"
#include "TypeDef.h"
#include "Utilities.h"

#include <algorithm>
#include <dirent.h>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <vector>

static auto predRunList = [] (const AllFolderPath& lhs, const AllFolderPath& rhs) {return lhs.run < rhs.run;};

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
    bool unpackORRUBA;
    bool unpackGRETINA;
    bool withTracked;
    bool mergeTrees;
};

#endif // RunList_h
