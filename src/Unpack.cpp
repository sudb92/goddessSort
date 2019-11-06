#include "Unpack.h"

int main(int argc, char *argv[]) {
    auto* unpacker = new Unpack();

    return 0;
}

Unpack::Unpack() {
    int StartClock = clock();
    std::cout << PrintOutput("Running GODDESS sort", "yellow") << std::endl;

    std::cout << PrintOutput("Reading RunList", "green") << std::endl;
    auto* runList = new RunList();
    auto fileList = runList->GetListOfRuns();

    std::cout << PrintOutput("Number of files to be sort = ", "yellow") << fileList.size() << std::endl;

    int numRuns = 0;
    for(auto run: fileList) {
        std::cout << PrintOutput(Form("Processing Run %s: \n", run.runNumber.c_str()), "green");
        auto* orruba = new UnpackORRUBA(run);
    }

    std::cout << PrintOutput("************************************************", "yellow") << std::endl;
    std::cout << PrintOutput("Finished Unpacking ", "yellow") << fileList.size() << PrintOutput(" files!", "yellow") <<  std::endl;
}
