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
        // auto* orruba = new UnpackORRUBA(run);
        // auto* gretina = new UnpackGRETINA(run);

        // bool orrubaCompleted = orruba->GetCompleted();
        // bool gretinaCompleted = gretina->GetCompleted();

        // if(orrubaCompleted && gretinaCompleted) {
        //     Combine(run);
        // }

        // Combine(run);

        CombineReader(run);
    }

    std::cout << PrintOutput("************************************************", "yellow") << std::endl;
    std::cout << PrintOutput("Finished Unpacking ", "yellow") << fileList.size() << PrintOutput(" files!", "yellow") <<  std::endl;
}

void Unpack::Combine(fileListStruct run) {
    std::cout << PrintOutput("\tCombining ORRUBA and GRETINA trees based on timestamp", "yellow") << std::endl;

    std::cout << PrintOutput(Form("\t\tOpening ORRUBA file: %s", run.rootPath.c_str()), "green") << std::endl;
    TFile *f_ORRUBA = new TFile(Form("%s", run.rootPath.c_str()), "read");
    if(!f_ORRUBA) {
        std::cout << PrintOutput(Form("\t\tCould not open ORRUBA file: %s", run.rootPath.c_str()), "red") << std::endl;
        return;
    }
    TTree *t_ORRUBA = (TTree*)f_ORRUBA->Get("data");
    if(!t_ORRUBA) {
        std::cout << PrintOutput("\t\tCould not open TTree data in ORRBUA file", "red") << std::endl;
        return;
    }

    std::cout << PrintOutput(Form("\t\tOpening GRETINA file: %s", run.gretinaPath.c_str()), "green") << std::endl;
    TFile *f_GRETINA = new TFile(Form("%s", run.gretinaPath.c_str()), "read");
    if(!f_GRETINA) {
        std::cout << PrintOutput(Form("\t\tCould not open GRETINA file: %s", run.gretinaPath.c_str()), "red") << std::endl;
        return;
    }
    TTree *t_GRETINA = (TTree*)f_GRETINA->Get("teb");
    if(!t_GRETINA) {
        std::cout << PrintOutput("\t\tCould not open TTree teb in GRETINA file", "red") << std::endl;
        return;
    }

    CombineTrees(t_ORRUBA, t_GRETINA);
}

void Unpack::CombineTrees(TTree* orruba, TTree* gretina) {
    TTree* outTree = new TTree("data", "Combined TTree of ORRUBA and GRETINA");

    Long64_t nentriesORRUBA = orruba->GetEntries();
    Long64_t nentriesGRETINA = gretina->GetEntries();

    std::cout << PrintOutput(Form("\t\t\tORRUBA Entries: %lld GRETINA Entries: %lld", nentriesORRUBA, nentriesGRETINA), "yellow") << std::endl;

    std::string *runNumber = new std::string();
    Int_t BB10Mul, BB10Det[128], BB10Strip[128], BB10Channel[128], BB10ADC[128];
    Float_t BB10Energy[128];
    Int_t QQQ5Mul;
    Int_t SX3Mul;
    ULong64_t timeStamp;

    orruba->SetBranchAddress("RunNumber", &runNumber);
    orruba->SetBranchAddress("BB10Mul", &BB10Mul);
    orruba->SetBranchAddress("BB10Det", &BB10Det);
    orruba->SetBranchAddress("BB10Strip", &BB10Strip);
    orruba->SetBranchAddress("timeStamp", &timeStamp);

    Bank88 *b88 = 0;
    g2OUT *g2 = 0;

    gretina->SetBranchAddress("b88", &b88);
    gretina->SetBranchAddress("g2", &g2);

    // Long64_t orrubaArray[nentriesORRUBA];
    // Long64_t gretinaArray[nentriesGRETINA];

    Int_t nonMatchedEvents = 0;
    for(ULong64_t i = 0; i < nentriesORRUBA; i++) {
        orruba->GetEntry(i);
        // orrubaArray[i] = timeStamp;

        // Lets be smart and not loop over all entries in the GRETINA trees
        Float_t i_percent = static_cast<Float_t>(i)/static_cast<Float_t>(nentriesORRUBA); // Get percentage we have looped through
        Float_t j_start_percent = i_percent < 0.1 ? 0. : i_percent - 0.1;
        Float_t j_stop_percent = i_percent > 0.9 ? 1. : i_percent + 0.1;
        ULong64_t j_start = static_cast<ULong64_t>(j_start_percent*nentriesGRETINA);
        ULong64_t j_stop = static_cast<ULong64_t>(j_stop_percent*nentriesGRETINA);

        Bool_t matched = false;
        for(ULong64_t j = j_start; j < j_stop; j++) {
            gretina->GetEntry(j);
            if(fabs(timeStamp - b88->timestamp) < 1000) {
                matched = true;
                break;
            }
        }

        if(!matched) {
            nonMatchedEvents++;
        }
    }

    return;
}

void Unpack::CombineReader(fileListStruct run) {
    std::cout << PrintOutput("\tCombining ORRUBA and GRETINA trees based on timestamp:", "yellow") << std::endl;

    std::cout << PrintOutput(Form("\t\tOpening ORRUBA file: %s", run.rootPath.c_str()), "green") << std::endl;
    auto f_ORRUBA = TFile::Open(Form("%s", run.rootPath.c_str()));
    if(!f_ORRUBA) {
        std::cout << PrintOutput(Form("\t\tCould not open ORRUBA file: %s", run.rootPath.c_str()), "red") << std::endl;
        return;
    }
    TTreeReader t_ORRUBA("data", f_ORRUBA);
    Long64_t nentriesORRUBA = t_ORRUBA.GetEntries();
    if(nentriesORRUBA == 0) {
        std::cout << PrintOutput("\t\tCould not open TTree 'data' in ORRBUA file", "red") << std::endl;
        return;
    }

    std::cout << PrintOutput(Form("\t\tOpening GRETINA file: %s", run.gretinaPath.c_str()), "green") << std::endl;
    auto f_GRETINA = TFile::Open(Form("%s", run.gretinaPath.c_str()));
    if(!f_GRETINA) {
        std::cout << PrintOutput(Form("\t\tCould not open GRETINA file: %s", run.gretinaPath.c_str()), "red") << std::endl;
        return;
    }
    TTreeReader t_GRETINA("teb", f_GRETINA);
    Long64_t nentriesGRETINA = t_GRETINA.GetEntries();
    if(nentriesGRETINA == 0) {
        std::cout << PrintOutput("\t\tCould not open TTree 'teb' in GRETINA file", "red") << std::endl;
        return;
    }

    std::cout << PrintOutput(Form("\t\t\tORRUBA Entries: %lld GRETINA Entries: %lld", nentriesORRUBA, nentriesGRETINA), "yellow") << std::endl;

    TTreeReaderValue<ULong64_t> orrubaTimeStamp(t_ORRUBA, "timeStamp");
    TTreeReaderValue<Long64_t> gretinaTimeStamp(t_GRETINA, "timestamp");

    Long64_t orrubaTimeStamps[nentriesORRUBA];
    Long64_t gretinaTimeStamps[nentriesGRETINA];

    Int_t i = 0;
    while(t_ORRUBA.Next()) {
        orrubaTimeStamps[i] = *orrubaTimeStamp;
        i++;
    }

    i = 0;
    while(t_GRETINA.Next()) {
        gretinaTimeStamps[i] = *gretinaTimeStamp;
        i++;
    }
}
