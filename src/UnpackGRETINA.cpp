#include "UnpackGRETINA.h"

UnpackGRETINA::UnpackGRETINA(fileListStruct run) {
    int startClock = clock();
    std::cout << PrintOutput("\tRunning GRETINA sort:", "yellow") << std::endl;

    std::string globalPath = run.globalPath;
    std::string commandString = "./unpackGRETINA -f " + globalPath + " -dopplerSimple -track -rootName " + run.gretinaPath;

    const char *command = commandString.c_str();
    int systemSuccess = system(command);

    if(systemSuccess != -1) completed = true;
}

