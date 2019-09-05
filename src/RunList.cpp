#include "RunList.h"

RunList::RunList() {
    // Read and parse config.json
    Json::Value config;
    std::ifstream config_stream("config.json");
    ASSERT_WITH_MESSAGE(config_stream.is_open(),
                        "Could not find 'config.json'\n");
    config_stream >> config;
    config_stream.close();

    pathToFolders = config["pathToFolders"].asString();
    pathPrefix = config["pathPrefix"].asString();
    ldfPrefix = config["ldfPrefix"].asString();
    outputPath = config["outputPath"].asString();
    copyCuts = config["copyCuts"].asBool();
    cutPrefix = config["cutPrefix"].asString();
    useAllFolders = config["useAllFolders"].asBool();

    runNumbers.clear();
    for(int i = 0; i < config["runs"].size(); i++) {
        runNumbers.push_back(config["runs"][i].asString());
    }

    if(!useAllFolders) CompileListOfRuns();
    else GetAllRuns();
}

RunList::~RunList() = default;

void RunList::CompileListOfRuns() {
    listOfRuns.clear();
    for(auto run: runNumbers) {
        std::string ldfPath = pathToFolders + pathPrefix + run + '/' + ldfPrefix + run + ".ldf";
        std::string rootPath = outputPath + pathPrefix + run + ".root";
        std::string preCutPath = pathToFolders + pathPrefix + run + '/' + cutPrefix + run + ".root";
        std::string cutPath = outputPath + cutPrefix + run + ".root";

        fileListStruct indFile = {pathToFolders, outputPath, ldfPath, rootPath, run, preCutPath, cutPath, copyCuts};
        listOfRuns.push_back(indFile);
    }
}

void RunList::GetAllRuns() {}




