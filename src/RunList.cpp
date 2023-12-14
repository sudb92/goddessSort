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

    unpackORRUBA = config["unpackORRUBA"].asBool();
    unpackGRETINA = config["unpackGRETINA"].asBool();
    withTracked = config["withTracked"].asBool();
    mergeTrees = config["mergeTrees"].asBool();

    if(!useAllFolders) CompileListOfRuns();
    else GetAllRuns();
}

RunList::~RunList() = default;

void RunList::CompileListOfRuns() {
    listOfRuns.clear();
    for(auto run: runNumbers) {
        std::string ldfPath = pathToFolders + pathPrefix + run + '/' + ldfPrefix + run + ".ldf";
        std::string rootPathRaw = outputPath + pathPrefix + run + "_orruba_raw.root";
        std::string preCutPath = pathToFolders + pathPrefix + run + '/' + cutPrefix + run + ".root";
        std::string cutPath = outputPath + cutPrefix + run + ".root";
        std::string globalPath;
        if (withTracked) {
            globalPath = pathToFolders + pathPrefix + run + "/GlobalwTracked.dat";
        }
        else {
            globalPath = pathToFolders + pathPrefix + run + "/Global.dat";
        }
        std::string gretinaPath = outputPath + pathPrefix + run + "_gretina.root";
        std::string combinedPath = outputPath + pathPrefix + run + "_combined.root";

        fileListStruct indFile = {pathToFolders, outputPath, ldfPath, rootPathRaw, run, preCutPath, cutPath, globalPath, gretinaPath, combinedPath, copyCuts, unpackORRUBA,unpackGRETINA, withTracked, mergeTrees};
        listOfRuns.push_back(indFile);
    }
}


void RunList::GetAllRuns() {
    std::vector<std::string> allFolders_;

    DIR* dirp = opendir(pathToFolders.c_str());
    struct dirent* dp;
    while((dp = readdir(dirp)) != NULL) {
        allFolders_.push_back(dp->d_name);
    }
    closedir(dirp);

    //std::vector<std::string> runFolders_;
    std::vector<std::string> runNumbers_;

    std::vector<AllFolderPath> runFolders_;
    for(auto folder: allFolders_) {
        if(folder.rfind("Run", 0) == 0) {
            AllFolderPath run = {folder.substr(3), atoi(folder.substr(3).c_str())};
            runFolders_.push_back(run);
        }
    }

    std::sort(runFolders_.begin(), runFolders_.end(), predRunList);

    listOfRuns.clear();
    for(auto run: runFolders_) {
        std::string ldfPath = pathToFolders + pathPrefix + run.runName + '/' + ldfPrefix + run.runName + ".ldf";
        std::string rootPathRaw = outputPath + ldfPrefix + run.runName + "_raw.root";
        std::string preCutPath = pathToFolders + pathPrefix + run.runName + '/' + cutPrefix + run.runName + ".root";
        std::string cutPath = outputPath + cutPrefix + run.runName + ".root";
        std::string globalPath;
        if (withTracked) {
            globalPath = pathToFolders + pathPrefix + run.runName + "/GlobalwTracked.dat";
        }
        else {
            globalPath = pathToFolders + pathPrefix + run.runName + "/Global.dat";
        }
        std::string gretinaPath = outputPath + pathPrefix + run.runName + "_gretina.root";
        std::string combinedPath = outputPath + pathPrefix + run.runName + "_combined.root";

        fileListStruct indFile = {pathToFolders, outputPath, ldfPath, rootPathRaw, run.runName, preCutPath, cutPath, globalPath, gretinaPath, combinedPath, copyCuts, unpackGRETINA, mergeTrees};
        listOfRuns.push_back(indFile);
    }
}




