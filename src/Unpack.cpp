// Combines GRETINA and ORRUBA events based on timestamps
#include <iostream>
#include <chrono>
//#include <filesystem.h>
#include "Unpack.h"

int main(int argc, char *argv[]) {
    auto* unpacker = new Unpack();
    return 0;
}

Unpack::Unpack() {
    int StartClock = clock();
    std::cout << PrintOutput("Running GODDESS sort", "yellow") << std::endl;
    std::cout << PrintOutput("Reading RunList", "yellow") << std::endl;
    auto* runList = new RunList();
    auto fileList = runList->GetListOfRuns();

    std::cout << PrintOutput("Number of files to be sort = ", "yellow") << fileList.size() << std::endl;

    int numRuns = 0;
    for(auto run: fileList) {
        std::cout << PrintOutput(Form("Processing Run %s: \n", run.runNumber.c_str()), "green");

        bool orrubaCompleted = false;
        if (run.unpackORRUBA) {
            auto* orruba = new UnpackORRUBA(run);
            orrubaCompleted = orruba->GetCompleted();
        }
        else if (run.mergeTrees) { // Check if file exists for merging
            orrubaCompleted = !(gSystem->AccessPathName(run.rootPathRaw.c_str()));
        }

        bool gretinaCompleted = false;
        if(run.unpackGRETINA) {
            auto* gretina = new UnpackGRETINA(run);
            gretinaCompleted = gretina->GetCompleted();
        }
        else if (run.mergeTrees) {
            gretinaCompleted = !(gSystem->AccessPathName(run.gretinaPath.c_str()));
        }

        if (orrubaCompleted && gretinaCompleted && run.mergeTrees) {
//            CombineReader(run); //original
              CombineReader2(run); // SB, Sept 2023
//              CombineReaderCompare(run); // Compares the results from the two methods above, writes to disk using the original approach
        }
    }

    std::cout << PrintOutput("************************************************", "yellow") << std::endl;
    std::cout << PrintOutput("Finished Unpacking ", "yellow") << fileList.size() << PrintOutput(" files!", "yellow") <<  std::endl;
}

void Unpack::CombineReader(fileListStruct run) {

    // SC: Declare timing variables that are used in event building
    Long64_t timeThreshold, timeFoundBreak, timeNotFoundBreak;

    std::cout << PrintOutput("\tCombining ORRUBA and GRETINA trees based on timestamp:", "yellow") << std::endl;

    std::cout << PrintOutput("\t\tOpening ORRUBA file: ", "blue") << run.rootPathRaw.c_str() << std::endl;
    auto f_ORRUBA = TFile::Open(Form("%s", run.rootPathRaw.c_str()));
    if(!f_ORRUBA) {
        std::cout << PrintOutput("\t\tCould not open Combined file: ", "red") << run.rootPathRaw.c_str() << std::endl;
        return;
    }
    TTreeReader t_ORRUBA("dataRaw", f_ORRUBA);
    Long64_t nentriesORRUBA = t_ORRUBA.GetEntries(true);
    if(nentriesORRUBA == 0) {
        std::cout << PrintOutput("\t\tCould not open TTree 'data' in ORRBUA file", "red") << std::endl;
        return;
    }
    TTree *tree_ORRUBA = (TTree*)f_ORRUBA->Get("dataRaw");

    std::cout << PrintOutput("\t\tOpening GRETINA file: ", "blue") << run.gretinaPath.c_str() << std::endl;
    auto f_GRETINA = TFile::Open(Form("%s", run.gretinaPath.c_str()));
    if(!f_GRETINA) {
        std::cout << PrintOutput("\t\tCould not open GRETINA file: ", "red") << run.gretinaPath.c_str() << std::endl;
        return;
    }

    TTree *tree_GRETINA = (TTree*)f_GRETINA->Get("teb");
    Long64_t nentriesGRETINA = tree_GRETINA->GetEntries();
    g1OUT *g1 = 0;
    g2OUT *g2 = 0;

    // g2 branch in GRETINA tree holds mode 2 data
    tree_GRETINA->SetBranchAddress("g2", &g2);

    std::cout << PrintOutput("\t\t\tTotal ORRUBA Entries: ", "yellow") << nentriesORRUBA << PrintOutput("; Total GRETINA Entries: ", "yellow") << nentriesGRETINA << std::endl;

    TTreeReaderValue<ULong64_t> orrubaTimeStamp(t_ORRUBA, "timeStamp");

    std::vector<std::pair<Int_t, Long64_t> > orrubaTimeStamps_;
    std::vector<std::pair<Int_t, Long64_t> > gretinaTimeStamps_;

    // Loop through ORRUBA events and get the timestamps
    auto start = std::chrono::high_resolution_clock::now();
    Int_t i = 0;
    while(t_ORRUBA.Next()) {
        orrubaTimeStamps_.push_back(std::make_pair(i, *orrubaTimeStamp));
        i++;
    }
    std::cout << "Generated timestamp array for ORRUBA.." << std::endl;
    for (int i = 0; i < nentriesGRETINA; i++) {
        tree_GRETINA->GetEntry(i);
        for (auto g2Event: g2->xtals) {
            gretinaTimeStamps_.push_back(std::make_pair(i, g2Event.timestamp));
            break;
        }
    }

    std::cout << "Generated timestamp array for GRETINA.." << std::endl;
    // Loop through ORRUBA events and for each event, match to the corresponding GRETINA event based on the timestamp
    // The difference of timestamps is to be < 1000 which is a lot considering the timestamps between two ORRUBA events
    // are generally on the order of 100,000.
    Long64_t nentriesMatched = 0;

    timeThreshold = 1000;
    timeFoundBreak = 0;
    timeNotFoundBreak = 1000;
    std::cout << "Matching indices.. " << std::endl;
    std::vector<matchedEvents> matchedEvents_, matchedEvents2_;

    for(size_t i = 0; i < orrubaTimeStamps_.size(); i++) { // SC: Loop through ORRUBA timestamps
        size_t found_j = 0;
        int found_index = 0;
        Long64_t orrubaTime = orrubaTimeStamps_[i].second;
        Bool_t found = false;

        size_t best_j;
        Long64_t closestTime = 100000;
        Long64_t gretinaTime;
        for(size_t j = 0; j < gretinaTimeStamps_.size(); j++) { // SC: Loop through GRETINA timestamps
            size_t timeDiff = fabs(orrubaTime - gretinaTimeStamps_[j].second); // SC: Find timing difference

            if((timeDiff < timeThreshold) && (timeDiff < closestTime)) { // If this is closest time difference, take it
                closestTime = fabs(orrubaTime - gretinaTimeStamps_[j].second);
                gretinaTime = gretinaTimeStamps_[j].second;
                best_j = gretinaTimeStamps_[j].first;
                found_index = j;
                found = true;
            }
            else if(timeDiff > closestTime && found){
                break;
            }
            if(timeDiff > timeNotFoundBreak && (gretinaTimeStamps_[j].second > orrubaTime)){
                break; // SC: Looks like this breaks the statement if it seems a match isn't found
            }
        }

        // Record ORRUBA + GRETINA timestamps
        if(found) {
            matchedEvents hit = {i, best_j, orrubaTime, gretinaTime};
            matchedEvents_.push_back(hit);
            nentriesMatched++;
        }
        // Record ORRUBA hits that do not have a GRETINA timestamp
        else {
            matchedEvents hit = {i, 0, orrubaTime, 0};
            matchedEvents_.push_back(hit);
        }

        // Remove the first found_index elements and shift everything else down by found_index indices
        // This is so that we don't have to loop through GRETINA events that have already been matched
        // Don't do it for every event as it will slow it down too much. Every 500 seems to work well
        if((i % 500 == 0) && found) gretinaTimeStamps_.erase(gretinaTimeStamps_.begin(), gretinaTimeStamps_.begin() + found_index);
        if(i % 10000==0) std::cout << "Progress :" << static_cast<int>(i*100./orrubaTimeStamps_.size()) << " %\r";
    }


    std::cout << PrintOutput("\t\tMatched ORRUBA and GRETINA time stamps", "blue") << std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

    // Reset ORRUBA TTreeReaders
    t_ORRUBA.Restart();

    // Create Combined TTree
    TFile* f_Combined = new TFile(run.combinedPath.c_str(), "recreate");
    TTree* tree_Combined = new TTree("mergtree", "Combined ORRUBA and GRETINA data");

    // Set branch address if file contains tracked data
    if (run.withTracked){
        tree_GRETINA->SetBranchAddress("g1", &g1);
    }

    // Get ORRUBA branches from ORRUBA tree
    int RunNumber;

    tree_ORRUBA->SetBranchAddress("RunNumber", &RunNumber);

    // QQQ5 dE Detectors
    // ----------------------------------------------------------------------------------------
	tree_ORRUBA->SetBranchAddress("dQQQ5RingMul_dE",        &dQQQ5RingMul_dE);
	tree_ORRUBA->SetBranchAddress("dQQQ5DetRingMul_dE",     &dQQQ5DetRingMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRing_dE",        &dQQQ5DetRing_dE);
	tree_ORRUBA->SetBranchAddress("dQQQ5Ring_dE",           &dQQQ5Ring_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingChannel_dE",    &dQQQ5RingChannel_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingADC_dE",        &dQQQ5RingADC_dE);

    tree_ORRUBA->SetBranchAddress("dQQQ5SectorMul_dE",     &dQQQ5SectorMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSectorMul_dE",   &dQQQ5DetSectorMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSector_dE",      &dQQQ5DetSector_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5Sector_dE",         &dQQQ5Sector_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorChannel_dE",  &dQQQ5SectorChannel_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorADC_dE",      &dQQQ5SectorADC_dE);
    // ----------------------------------------------------------------------------------------

    // QQQ5 E Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("dQQQ5RingMul_E",        &dQQQ5RingMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRingMul_E",     &dQQQ5DetRingMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRing_E",        &dQQQ5DetRing_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5Ring_E",           &dQQQ5Ring_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingChannel_E",    &dQQQ5RingChannel_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingADC_E",        &dQQQ5RingADC_E);

    tree_ORRUBA->SetBranchAddress("dQQQ5SectorMul_E",     &dQQQ5SectorMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSectorMul_E",   &dQQQ5DetSectorMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSector_E",      &dQQQ5DetSector_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5Sector_E",         &dQQQ5Sector_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorChannel_E",  &dQQQ5SectorChannel_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorADC_E",      &dQQQ5SectorADC_E);
    // ----------------------------------------------------------------------------------------

    // Upstream QQQ5 Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("uQQQ5RingMul",        &uQQQ5RingMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetRingMul",     &uQQQ5DetRingMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetRing",        &uQQQ5DetRing);
    tree_ORRUBA->SetBranchAddress("uQQQ5Ring",           &uQQQ5Ring);
    tree_ORRUBA->SetBranchAddress("uQQQ5RingChannel",    &uQQQ5RingChannel);
    tree_ORRUBA->SetBranchAddress("uQQQ5RingADC",        &uQQQ5RingADC);

    tree_ORRUBA->SetBranchAddress("uQQQ5SectorMul",     &uQQQ5SectorMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetSectorMul",   &uQQQ5DetSectorMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetSector",      &uQQQ5DetSector);
    tree_ORRUBA->SetBranchAddress("uQQQ5Sector",         &uQQQ5Sector);
    tree_ORRUBA->SetBranchAddress("uQQQ5SectorChannel",  &uQQQ5SectorChannel);
    tree_ORRUBA->SetBranchAddress("uQQQ5SectorADC",      &uQQQ5SectorADC);
    // ----------------------------------------------------------------------------------------

    // BB10 Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("BB10Mul",                &BB10Mul);
    tree_ORRUBA->SetBranchAddress("BB10DetMul",             &BB10DetMul);
    tree_ORRUBA->SetBranchAddress("BB10Det",                &BB10Det);
    tree_ORRUBA->SetBranchAddress("BB10Strip",              &BB10Strip);
    tree_ORRUBA->SetBranchAddress("BB10Channel",            &BB10Channel);
    tree_ORRUBA->SetBranchAddress("BB10ADC",                &BB10ADC);
    // ----------------------------------------------------------------------------------------

    // Super X3 Downstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("dSX3LeftMul",            &dSX3LeftMul);
    tree_ORRUBA->SetBranchAddress("dSX3RightMul",           &dSX3RightMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetLeftMul",         &dSX3DetLeftMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetRightMul",        &dSX3DetRightMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetLeft",            &dSX3DetLeft);
    tree_ORRUBA->SetBranchAddress("dSX3DetRight",           &dSX3DetRight);
    tree_ORRUBA->SetBranchAddress("dSX3LeftStrip",          &dSX3LeftStrip);
    tree_ORRUBA->SetBranchAddress("dSX3RightStrip",         &dSX3RightStrip);
    tree_ORRUBA->SetBranchAddress("dSX3LeftChannel",        &dSX3LeftChannel);
    tree_ORRUBA->SetBranchAddress("dSX3RightChannel",       &dSX3RightChannel);
    tree_ORRUBA->SetBranchAddress("dSX3LeftADC",            &dSX3LeftADC);
    tree_ORRUBA->SetBranchAddress("dSX3RightADC",           &dSX3RightADC);

    tree_ORRUBA->SetBranchAddress("dSX3BackMul",            &dSX3BackMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetBackMul",         &dSX3DetBackMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetBack",            &dSX3DetBack);
    tree_ORRUBA->SetBranchAddress("dSX3BackSector",         &dSX3BackSector);
    tree_ORRUBA->SetBranchAddress("dSX3BackChannel",        &dSX3BackChannel);
    tree_ORRUBA->SetBranchAddress("dSX3BackADC",            &dSX3BackADC);
    // ----------------------------------------------------------------------------------------

    // Super X3 Upstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("uSX3LeftMul",            &uSX3LeftMul);
	tree_ORRUBA->SetBranchAddress("uSX3RightMul",           &uSX3RightMul);
	tree_ORRUBA->SetBranchAddress("uSX3DetLeftMul",         &uSX3DetLeftMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetRightMul",        &uSX3DetRightMul);
	tree_ORRUBA->SetBranchAddress("uSX3DetLeft",            &uSX3DetLeft);
	tree_ORRUBA->SetBranchAddress("uSX3DetRight",           &uSX3DetRight);
    tree_ORRUBA->SetBranchAddress("uSX3LeftStrip",          &uSX3LeftStrip);
    tree_ORRUBA->SetBranchAddress("uSX3RightStrip",         &uSX3RightStrip);
    tree_ORRUBA->SetBranchAddress("uSX3LeftChannel",        &uSX3LeftChannel);
    tree_ORRUBA->SetBranchAddress("uSX3RightChannel",       &uSX3RightChannel);
    tree_ORRUBA->SetBranchAddress("uSX3LeftADC",            &uSX3LeftADC);
    tree_ORRUBA->SetBranchAddress("uSX3RightADC",           &uSX3RightADC);

    tree_ORRUBA->SetBranchAddress("uSX3BackMul",            &uSX3BackMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetBackMul",         &uSX3DetBackMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetBack",            &uSX3DetBack);
    tree_ORRUBA->SetBranchAddress("uSX3BackSector",         &uSX3BackSector);
    tree_ORRUBA->SetBranchAddress("uSX3BackChannel",        &uSX3BackChannel);
    tree_ORRUBA->SetBranchAddress("uSX3BackADC",            &uSX3BackADC);
    // ----------------------------------------------------------------------------------------

    // Timing
    // ----------------------------------------------------------------------------------------

    tree_ORRUBA->SetBranchAddress("tdcSilicon",             &TDCSilicon);
    tree_ORRUBA->SetBranchAddress("tdcSiliconDivTrig",      &TDCSiliconDivTrig);
    tree_ORRUBA->SetBranchAddress("tdcSiliconGRETINATrig",  &TDCSiliconGRETINATrig);
    tree_ORRUBA->SetBranchAddress("tdcRF",                  &TDCRF);
    tree_ORRUBA->SetBranchAddress("tdcGRETINA",             &TDCGRETINA);
    tree_ORRUBA->SetBranchAddress("tdcSiliconAlt",          &TDCSiliconAlt);
    tree_ORRUBA->SetBranchAddress("tdcSiliconUpstream",     &TDCSiliconUpstream);

    tree_ORRUBA->SetBranchAddress("timeStamp", &TimeStamp);
    // ----------------------------------------------------------------------------------------

    // Set ORRUBA branches in Combined tree
    int fRunNumber;

    tree_Combined->Branch("RunNumber", &fRunNumber, "RunNumber/I");

    // QQQ5 dE Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dQQQ5RingMul_dE",        &fdQQQ5RingMul_dE,      "dQQQ5RingMul_dE/I");
    tree_Combined->Branch("dQQQ5DetRingMul_dE",     &fdQQQ5DetRingMul_dE,       "dQQQ5DetRingMul_dE[2]/I");
    tree_Combined->Branch("dQQQ5DetRing_dE",        &fdQQQ5DetRing_dE,      "dQQQ5DetRing_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5Ring_dE",           &fdQQQ5Ring_dE,         "dQQQ5Ring_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5RingChannel_dE",    &fdQQQ5RingChannel_dE,      "dQQQ5RingChannel_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5RingADC_dE",        &fdQQQ5RingADC_dE,          "dQQQ5RingADC_dE[dQQQ5RingMul_dE]/I");

    tree_Combined->Branch("dQQQ5SectorMul_dE",      &fdQQQ5SectorMul_dE,        "dQQQ5SectorMul_dE/I");
    tree_Combined->Branch("dQQQ5DetSectorMul_dE",   &fdQQQ5DetSectorMul_dE,     "dQQQ5DetSectorMul_dE[2]/I");
    tree_Combined->Branch("dQQQ5DetSector_dE",      &fdQQQ5DetSector_dE,        "dQQQ5DetSector_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5Sector_dE",         &fdQQQ5Sector_dE,           "dQQQ5Sector_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5SectorChannel_dE",  &fdQQQ5SectorChannel_dE,        "dQQQ5SectorChannel_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5SectorADC_dE",      &fdQQQ5SectorADC_dE,        "dQQQ5SectorADC_dE[dQQQ5SectorMul_dE]/I");
    // ----------------------------------------------------------------------------------------

    // QQQ5 E Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dQQQ5RingMul_E",        &fdQQQ5RingMul_E,      "dQQQ5RingMul_E/I");
    tree_Combined->Branch("dQQQ5DetRingMul_E",     &fdQQQ5DetRingMul_E,       "dQQQ5DetRingMul_E[2]/I");
    tree_Combined->Branch("dQQQ5DetRing_E",        &fdQQQ5DetRing_E,      "dQQQ5DetRing_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5Ring_E",           &fdQQQ5Ring_E,         "dQQQ5Ring_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5RingChannel_E",    &fdQQQ5RingChannel_E,      "dQQQ5RingChannel_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5RingADC_E",        &fdQQQ5RingADC_E,          "dQQQ5RingADC_E[dQQQ5RingMul_E]/I");

    tree_Combined->Branch("dQQQ5SectorMul_E",      &fdQQQ5SectorMul_E,        "dQQQ5SectorMul_E/I");
    tree_Combined->Branch("dQQQ5DetSectorMul_E",   &fdQQQ5DetSectorMul_E,     "dQQQ5DetSectorMul_E[2]/I");
    tree_Combined->Branch("dQQQ5DetSector_E",      &fdQQQ5DetSector_E,        "dQQQ5DetSector_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5Sector_E",         &fdQQQ5Sector_E,           "dQQQ5Sector_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5SectorChannel_E",  &fdQQQ5SectorChannel_E,        "dQQQ5SectorChannel_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5SectorADC_E",      &fdQQQ5SectorADC_E,        "dQQQ5SectorADC_E[dQQQ5SectorMul_E]/I");
    // ----------------------------------------------------------------------------------------

    // Upstream QQQ5 Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("uQQQ5RingMul",        &fuQQQ5RingMul,      "uQQQ5RingMul/I");
    tree_Combined->Branch("uQQQ5DetRingMul",     &fuQQQ5DetRingMul,       "uQQQ5DetRingMul[2]/I");
    tree_Combined->Branch("uQQQ5DetRing",        &fuQQQ5DetRing,      "uQQQ5DetRing[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5Ring",           &fuQQQ5Ring,         "uQQQ5Ring[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5RingChannel",    &fuQQQ5RingChannel,      "uQQQ5RingChannel[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5RingADC",        &fuQQQ5RingADC,          "uQQQ5RingADC[uQQQ5RingMul]/I");

    tree_Combined->Branch("uQQQ5SectorMul",      &fuQQQ5SectorMul,        "uQQQ5SectorMul/I");
    tree_Combined->Branch("uQQQ5DetSectorMul",   &fuQQQ5DetSectorMul,     "uQQQ5DetSectorMul[2]/I");
    tree_Combined->Branch("uQQQ5DetSector",      &fuQQQ5DetSector,        "uQQQ5DetSector[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5Sector",         &fuQQQ5Sector,           "uQQQ5Sector[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5SectorChannel",  &fuQQQ5SectorChannel,        "uQQQ5SectorChannel[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5SectorADC",      &fuQQQ5SectorADC,        "uQQQ5SectorADC[uQQQ5SectorMul]/I");
    // ----------------------------------------------------------------------------------------

    // BB10 Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("BB10Mul",                &fBB10Mul,          "BB10Mul/I");
    tree_Combined->Branch("BB10DetMul",             &fBB10DetMul,       "BB10DetMul[12]/I");
    tree_Combined->Branch("BB10Det",                &fBB10Det,          "BB10Det[BB10Mul]/I");
    tree_Combined->Branch("BB10Strip",              &fBB10Strip,        "BB10Strip[BB10Mul]/I");
    tree_Combined->Branch("BB10Channel",            &fBB10Channel,      "BB10Channel[BB10Mul]/I");
    tree_Combined->Branch("BB10ADC",                &fBB10ADC,          "BB10ADC[BB10Mul]/I");
    // ----------------------------------------------------------------------------------------

    // Super X3 Downstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dSX3LeftMul",            &fdSX3LeftMul,      "dSX3LeftMul/I");
    tree_Combined->Branch("dSX3RightMul",           &fdSX3RightMul,     "dSX3RightMul/I");
    tree_Combined->Branch("dSX3DetLeftMul",         &fdSX3DetLeftMul,       "dSX3DetLeftMul[12]/I");
    tree_Combined->Branch("dSX3DetRightMul",        &fdSX3DetRightMul,      "dSX3DetRightMul[12]/I");
    tree_Combined->Branch("dSX3DetLeft",            &fdSX3DetLeft,      "dSX3DetLeft[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3DetRight",           &fdSX3DetRight,     "dSX3DetRight[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftStrip",          &fdSX3LeftStrip,        "dSX3LeftStrip[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightStrip",         &fdSX3RightStrip,       "dSX3RightStrip[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftChannel",        &fdSX3LeftChannel,      "dSX3LeftChannel[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightChannel",       &fdSX3RightChannel,     "dSX3RightChannel[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftADC",            &fdSX3LeftADC,      "dSX3LeftADC[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightADC",           &fdSX3RightADC,     "dSX3RightADC[dSX3RightMul]/I");

    tree_Combined->Branch("dSX3BackMul",            &fdSX3BackMul,          "dSX3BackMul/I");
    tree_Combined->Branch("dSX3DetBackMul",         &fdSX3DetBackMul,           "dSX3DetBackMul[12]/I");
    tree_Combined->Branch("dSX3DetBack",            &fdSX3DetBack,          "dSX3DetBack[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackSector",         &fdSX3BackSector,       "dSX3BackSector[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackChannel",        &fdSX3BackChannel,      "dSX3BackChannel[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackADC",            &fdSX3BackADC,      "dSX3BackADC[dSX3BackMul]/I");
    // ----------------------------------------------------------------------------------------

    // Super X3 Upstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("uSX3LeftMul",            &fuSX3LeftMul,      "uSX3LeftMul/I");
    tree_Combined->Branch("uSX3RightMul",           &fuSX3RightMul,     "uSX3RightMul/I");
    tree_Combined->Branch("uSX3DetLeftMul",         &fuSX3DetLeftMul,       "uSX3DetLeftMul[12]/I");
    tree_Combined->Branch("uSX3DetRightMul",        &fuSX3DetRightMul,      "uSX3DetRightMul[12]/I");
    tree_Combined->Branch("uSX3DetLeft",            &fuSX3DetLeft,      "uSX3DetLeft[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3DetRight",           &fuSX3DetRight,     "uSX3DetRight[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftStrip",          &fuSX3LeftStrip,        "uSX3LeftStrip[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightStrip",         &fuSX3RightStrip,       "uSX3RightStrip[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftChannel",        &fuSX3LeftChannel,      "uSX3LeftChannel[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightChannel",       &fuSX3RightChannel,     "uSX3RightChannel[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftADC",            &fuSX3LeftADC,      "uSX3LeftADC[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightADC",           &fuSX3RightADC,     "uSX3RightADC[uSX3RightMul]/I");

    tree_Combined->Branch("uSX3BackMul",            &fuSX3BackMul,          "uSX3BackMul/I");
    tree_Combined->Branch("uSX3DetBackMul",         &fuSX3DetBackMul,           "uSX3DetBackMul[12]/I");
    tree_Combined->Branch("uSX3DetBack",            &fuSX3DetBack,          "uSX3DetBack[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackSector",         &fuSX3BackSector,       "uSX3BackSector[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackChannel",        &fuSX3BackChannel,      "uSX3BackChannel[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackADC",            &fuSX3BackADC,      "uSX3BackADC[uSX3BackMul]/I");

    // ----------------------------------------------------------------------------------------

    // Timing
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("tdcSilicon",             &fTDCSilicon);
    tree_Combined->Branch("tdcSiliconDivTrig",      &fTDCSiliconDivTrig);
    tree_Combined->Branch("tdcSiliconGRETINATrig",  &fTDCSiliconGRETINATrig);
    tree_Combined->Branch("tdcRF",                  &fTDCRF);
    tree_Combined->Branch("tdcGRETINA",             &fTDCGRETINA);
    tree_Combined->Branch("tdcSiliconAlt",          &fTDCSiliconAlt);
    tree_Combined->Branch("tdcSiliconUpstream",     &fTDCSiliconUpstream);

    tree_Combined->Branch("timeStamp",              &fTimeStamp);
    tree_Combined->Branch("GRETINATimeStamp",       &fGRETINATimeStamp);
    // ----------------------------------------------------------------------------------------


    // Set GRETINA branches in Combined tree
    tree_Combined->Branch("foundGRETINA", &foundGRETINA);

    // Mode 2
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("xtalsMul", &xtalsMul, "xtalsMul/I");
    tree_Combined->Branch("xtals_xlab", &xtals_xlab, "xtals_xlab[xtalsMul]/F");
    tree_Combined->Branch("xtals_ylab", &xtals_ylab, "xtals_ylab[xtalsMul]/F");
    tree_Combined->Branch("xtals_zlab", &xtals_zlab, "xtals_zlab[xtalsMul]/F");
    tree_Combined->Branch("xtals_cc", &xtals_cc, "xtals_cc[xtalsMul]/F");
    tree_Combined->Branch("xtals_edop", &xtals_edop, "xtals_edop[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopMaxInt", &xtals_edopMaxInt, "xtals_edopMaxInt[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopSeg", &xtals_edopSeg, "xtals_edopSeg[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopXtal", &xtals_edopXtal, "xtals_edopXtal[xtalsMul]/F");
    tree_Combined->Branch("xtals_crystalNum", &xtals_crystalNum, "xtals_crystalNum[xtalsMul]/I");
    tree_Combined->Branch("xtals_quadNum", &xtals_quadNum, "xtals_quadNum[xtalsMul]/I");
    tree_Combined->Branch("xtals_t0", &xtals_t0, "xtals_t0[xtalsMul]/F");
    tree_Combined->Branch("xtals_timestamp", &xtals_timestamp, "xtals_timestamp[xtalsMul]/L");
    // ----------------------------------------------------------------------------------------

    // Mode 1 if selected
    // ----------------------------------------------------------------------------------------
    if (run.withTracked) {
        tree_Combined->Branch("gammasMul", &gammasMul, "gammasMul/I");
        tree_Combined->Branch("gammas_cc", &gammas_cc, "gammas_cc[gammasMul]/F");
        tree_Combined->Branch("gammas_xlab", &gammas_xlab,  "gammas_xlab[gammasMul]/F");
        tree_Combined->Branch("gammas_ylab", &gammas_ylab,  "gammas_ylab[gammasMul]/F");
        tree_Combined->Branch("gammas_zlab", &gammas_zlab,  "gammas_zlab[gammasMul]/F");
        tree_Combined->Branch("gammas_timestamp", &gammas_timestamp, "gammas_timestamp[gammasMul]/L");
    }
    // ----------------------------------------------------------------------------------------

    for(auto matchedEvent: matchedEvents_) {

        // Handle ORRUBA
        tree_ORRUBA->GetEntry(matchedEvent.orrubaNumber);
        fRunNumber = RunNumber;

		// First copy QQQ5 dE data to merged tree
        // ----------------------------------------------------------------------------------------
        fdQQQ5RingMul_dE = dQQQ5RingMul_dE;
        for(int i=0; i<dQQQ5RingMul_dE; i++) {

            fdQQQ5DetRing_dE[i] = dQQQ5DetRing_dE[i];
            fdQQQ5Ring_dE[i] = dQQQ5Ring_dE[i];
            fdQQQ5RingChannel_dE[i] = dQQQ5RingChannel_dE[i];
            fdQQQ5RingADC_dE[i] = dQQQ5RingADC_dE[i];
        }

        fdQQQ5SectorMul_dE = dQQQ5SectorMul_dE;
        for(int i=0; i<dQQQ5SectorMul_dE; i++) {
            fdQQQ5DetSector_dE[i] = dQQQ5DetSector_dE[i];
            fdQQQ5Sector_dE[i] = dQQQ5Sector_dE[i];
            fdQQQ5SectorChannel_dE[i] = dQQQ5SectorChannel_dE[i];
            fdQQQ5SectorADC_dE[i] = dQQQ5SectorADC_dE[i];
        }

        for(int i=0; i<2; i++) {
            fdQQQ5DetRingMul_dE[i] = dQQQ5DetRingMul_dE[i];
            fdQQQ5DetSectorMul_dE[i] = dQQQ5DetSectorMul_dE[i];
        }
        // ----------------------------------------------------------------------------------------

		// Then QQQ5 E
        // ----------------------------------------------------------------------------------------
        fdQQQ5RingMul_E = dQQQ5RingMul_E;
        //std::cout << "dQQQ5RingMul_E = " << dQQQ5RingMul_E << std::endl;
        for(int i=0; i<dQQQ5RingMul_E; i++) {

            fdQQQ5DetRing_E[i] = dQQQ5DetRing_E[i];
            fdQQQ5Ring_E[i] = dQQQ5Ring_E[i];
            fdQQQ5RingChannel_E[i] = dQQQ5RingChannel_E[i];
            fdQQQ5RingADC_E[i] = dQQQ5RingADC_E[i];
        }

        fdQQQ5SectorMul_E = dQQQ5SectorMul_E;
        for(int i=0; i<dQQQ5SectorMul_E; i++) {
            fdQQQ5DetSector_E[i] = dQQQ5DetSector_E[i];
            fdQQQ5Sector_E[i] = dQQQ5Sector_E[i];
            fdQQQ5SectorChannel_E[i] = dQQQ5SectorChannel_E[i];
            fdQQQ5SectorADC_E[i] = dQQQ5SectorADC_E[i];
        }

        for(int i=0; i<4; i++) {
            fdQQQ5DetRingMul_E[i] = dQQQ5DetRingMul_E[i];
            fdQQQ5DetSectorMul_E[i] = dQQQ5DetSectorMul_E[i];
        }
        // ----------------------------------------------------------------------------------------

		// Then Upstream QQQ5
        // ----------------------------------------------------------------------------------------
        fuQQQ5RingMul = uQQQ5RingMul;
        for(int i=0; i<uQQQ5RingMul; i++) {

            fuQQQ5DetRing[i] = uQQQ5DetRing[i];
            fuQQQ5Ring[i] = uQQQ5Ring[i];
            fuQQQ5RingChannel[i] = uQQQ5RingChannel[i];
            fuQQQ5RingADC[i] = uQQQ5RingADC[i];
        }

        fuQQQ5SectorMul = uQQQ5SectorMul;
        for(int i=0; i<uQQQ5SectorMul; i++) {
            fuQQQ5DetSector[i] = uQQQ5DetSector[i];
            fuQQQ5Sector[i] = uQQQ5Sector[i];
            fuQQQ5SectorChannel[i] = uQQQ5SectorChannel[i];
            fuQQQ5SectorADC[i] = uQQQ5SectorADC[i];
        }
        for(int i=0; i<4; i++) {
            fuQQQ5DetRingMul[i] = uQQQ5DetRingMul[i];
            fuQQQ5DetSectorMul[i] = uQQQ5DetSectorMul[i];
        }
        // ----------------------------------------------------------------------------------------

		// Now BB10
        // ----------------------------------------------------------------------------------------
        fBB10Mul = BB10Mul;
        for(int i=0; i<BB10Mul; i++) {
            fBB10Det[i] = BB10Det[i];
            fBB10Strip[i] = BB10Strip[i];
            fBB10Channel[i] = BB10Channel[i];
            fBB10ADC[i] = BB10ADC[i];
        }
        for(int i=0; i<12; i++) {
            fBB10DetMul[i] = BB10DetMul[i];
        }
        // ----------------------------------------------------------------------------------------


		// Now dSX3s
        // ----------------------------------------------------------------------------------------
        fdSX3LeftMul = dSX3LeftMul;
        for(int i=0; i<dSX3LeftMul; i++) {
            fdSX3DetLeft[i] = dSX3DetLeft[i];
            fdSX3LeftStrip[i] = dSX3LeftStrip[i];
            fdSX3LeftChannel[i] = dSX3LeftChannel[i];
            fdSX3LeftADC[i] = dSX3LeftADC[i];
        }
        fdSX3RightMul = dSX3RightMul;
        for(int i=0; i<dSX3RightMul; i++) {
            fdSX3DetRight[i] = dSX3DetRight[i];
            fdSX3RightStrip[i] = dSX3RightStrip[i];
            fdSX3RightChannel[i] = dSX3RightChannel[i];
            fdSX3RightADC[i] = dSX3RightADC[i];
        }
        fdSX3BackMul = dSX3BackMul;
        for(int i=0; i<dSX3BackMul; i++) {
            fdSX3DetBack[i] = dSX3DetBack[i];
            fdSX3BackSector[i] = dSX3BackSector[i];
            fdSX3BackChannel[i] = dSX3BackChannel[i];
            fdSX3BackADC[i] = dSX3BackADC[i];
        }
        for(int i=0; i<12; i++) {
            fdSX3DetLeftMul[i] = dSX3DetLeftMul[i];
            fdSX3DetRightMul[i] = dSX3DetRightMul[i];
            fdSX3DetBackMul[i] = dSX3DetBackMul[i];
        }
        // ----------------------------------------------------------------------------------------

		// Finally uSX3s
        // ----------------------------------------------------------------------------------------
        fuSX3LeftMul = uSX3LeftMul;
        for(int i=0; i<uSX3LeftMul; i++) {
            fuSX3DetLeft[i] = uSX3DetLeft[i];
            fuSX3LeftStrip[i] = uSX3LeftStrip[i];
            fuSX3LeftChannel[i] = uSX3LeftChannel[i];
            fuSX3LeftADC[i] = uSX3LeftADC[i];
        }
        fuSX3RightMul = uSX3RightMul;
        for(int i=0; i<uSX3RightMul; i++) {
            fuSX3DetRight[i] = uSX3DetRight[i];
            fuSX3RightStrip[i] = uSX3RightStrip[i];
            fuSX3RightChannel[i] = uSX3RightChannel[i];
            fuSX3RightADC[i] = uSX3RightADC[i];
        }
        fuSX3BackMul = uSX3BackMul;
        for(int i=0; i<uSX3BackMul; i++) {
            fuSX3DetBack[i] = uSX3DetBack[i];
            fuSX3BackSector[i] = uSX3BackSector[i];
            fuSX3BackChannel[i] = uSX3BackChannel[i];
            fuSX3BackADC[i] = uSX3BackADC[i];
        }
        for(int i=0; i<12; i++) {
            fuSX3DetLeftMul[i] = uSX3DetLeftMul[i];
            fuSX3DetRightMul[i] = uSX3DetRightMul[i];
            fuSX3DetBackMul[i] = uSX3DetBackMul[i];
        }
        // ----------------------------------------------------------------------------------------

        fTDCSilicon = TDCSilicon;
        fTDCSiliconDivTrig = TDCSiliconDivTrig;
        fTDCSiliconGRETINATrig = TDCSiliconGRETINATrig;
        fTDCRF = TDCRF;
        fTDCGRETINA = TDCGRETINA;
        fTDCSiliconAlt = TDCSiliconAlt;
        fTDCSiliconUpstream = TDCSiliconUpstream;

        fTimeStamp = TimeStamp;
		fGRETINATimeStamp = matchedEvent.gretinaTimeStamp;

        // Handle GRETINA
        xtalsMul = 0;
        gammasMul = 0;

        if(matchedEvent.gretinaTimeStamp > 1) {
            foundGRETINA = true;
            tree_GRETINA->GetEntry(matchedEvent.gretinaNumber);
            for(auto g2Event: g2->xtals) {
                xtals_xlab[xtalsMul] = g2Event.maxIntPtXYZLab().X();
                xtals_ylab[xtalsMul] = g2Event.maxIntPtXYZLab().Y();
                xtals_zlab[xtalsMul] = g2Event.maxIntPtXYZLab().Z();
                xtals_cc[xtalsMul] = g2Event.cc;
                xtals_edop[xtalsMul] = g2Event.edop;
                xtals_edopMaxInt[xtalsMul] = g2Event.edop_maxInt;
                xtals_edopSeg[xtalsMul] = g2Event.edopSeg;
                xtals_edopXtal[xtalsMul] = g2Event.edopXtal;
                xtals_crystalNum[xtalsMul] = g2Event.crystalNum;
                xtals_quadNum[xtalsMul] = g2Event.quadNum;
                xtals_t0[xtalsMul] = g2Event.t0;
                xtals_timestamp[xtalsMul] = g2Event.timestamp;
                xtalsMul++;
            }

            if (run.withTracked) {
                for(auto g1Event: g1->gammas) {
                    gammas_cc[gammasMul] = g1Event.cc;
                    gammas_xlab[gammasMul] = g1Event.xyzLab1.X();
                    gammas_ylab[gammasMul] = g1Event.xyzLab1.Y();
                    gammas_zlab[gammasMul] = g1Event.xyzLab1.Z();
                    gammas_timestamp[gammasMul] = g1Event.timestamp;
                    gammasMul++;
                }
            }

        }
        else {
            foundGRETINA = false;
        }

        tree_Combined->Fill();
        if(matchedEvent.orrubaNumber % 10000==0) std::cout << "Progress :" << static_cast<int>(matchedEvent.orrubaNumber*100.0/nentriesORRUBA) << " %\r\a";
    }
    std::cout << std::endl;
    tree_Combined->Write();
    f_Combined->Close();

    f_ORRUBA->Close();
    f_GRETINA->Close();

    std::cout << PrintOutput("\t\tFinished combining ORRUBA and GRETINA Trees based on time stamps", "blue") << std::endl;
    std::cout << PrintOutput("\t\tCombined TTree 'data' written to file: ", "blue") << run.combinedPath << std::endl;


    std::ofstream statFile("../LogFiles/unpack.log",std::ofstream::app);
    statFile << "Run Number " << fRunNumber << std::endl;
    statFile << "EB_DIFF_TIME:" << '\t' << '\t' << EB_DIFF_TIME << std::endl;
    statFile << "timeThreshold:" << '\t' << '\t' << timeThreshold << std::endl;
    statFile << "timeFoundBreak" << '\t' << '\t' << timeFoundBreak << std::endl;
    statFile << "timeNotFoundBreak" << '\t' << '\t' << timeFoundBreak << std::endl;
    statFile << "ORRUBA Entries" << '\t' << '\t' << nentriesORRUBA << std::endl;
    statFile << "GRETINA Entries" << '\t' << '\t' << nentriesGRETINA << std::endl;
    statFile << "Matched Entries" << '\t' << '\t' << nentriesMatched << std::endl;
    statFile << "Time to match" << (duration.count()/1000000.0) << std::endl;
    statFile << std::endl;
    statFile.close();

}


void Unpack::CombineReaderCompare(fileListStruct run) {

    // SC: Declare timing variables that are used in event building
    Long64_t timeThreshold, timeFoundBreak, timeNotFoundBreak;
    std::cout << PrintOutput("\tCombining ORRUBA and GRETINA trees based on timestamp:", "yellow") << std::endl;
    std::cout << PrintOutput("\t\tOpening ORRUBA file: ", "blue") << run.rootPathRaw.c_str() << std::endl;
    auto f_ORRUBA = TFile::Open(Form("%s", run.rootPathRaw.c_str()));
    if(!f_ORRUBA) {
        std::cout << PrintOutput("\t\tCould not open Combined file: ", "red") << run.rootPathRaw.c_str() << std::endl;
        return;
    }
    TTreeReader t_ORRUBA("dataRaw", f_ORRUBA);
    Long64_t nentriesORRUBA = t_ORRUBA.GetEntries(true);
    if(nentriesORRUBA == 0) {
        std::cout << PrintOutput("\t\tCould not open TTree 'data' in ORRBUA file", "red") << std::endl;
        return;
    }
    TTree *tree_ORRUBA = (TTree*)f_ORRUBA->Get("dataRaw");

    std::cout << PrintOutput("\t\tOpening GRETINA file: ", "blue") << run.gretinaPath.c_str() << std::endl;
    auto f_GRETINA = TFile::Open(Form("%s", run.gretinaPath.c_str()));
    if(!f_GRETINA) {
        std::cout << PrintOutput("\t\tCould not open GRETINA file: ", "red") << run.gretinaPath.c_str() << std::endl;
        return;
    }

    TTree *tree_GRETINA = (TTree*)f_GRETINA->Get("teb");
    Long64_t nentriesGRETINA = tree_GRETINA->GetEntries();
    g1OUT *g1 = 0;
    g2OUT *g2 = 0;

    // g2 branch in GRETINA tree holds mode 2 data
    tree_GRETINA->SetBranchAddress("g2", &g2);

    std::cout << PrintOutput("\t\t\tTotal ORRUBA Entries: ", "yellow") << nentriesORRUBA << PrintOutput("; Total GRETINA Entries: ", "yellow") << nentriesGRETINA << std::endl;

    TTreeReaderValue<ULong64_t> orrubaTimeStamp(t_ORRUBA, "timeStamp");

    std::vector<std::pair<Int_t, Long64_t> > orrubaTimeStamps_;
    std::vector<std::pair<Int_t, Long64_t> > gretinaTimeStamps_, gretinaTimeStamps2_;

    // Loop through ORRUBA events and get the timestamps
    auto start = std::chrono::high_resolution_clock::now();
    Int_t i = 0;
    while(t_ORRUBA.Next()) {
        orrubaTimeStamps_.push_back(std::make_pair(i, *orrubaTimeStamp));
        i++;
    }
    std::cout << "Generated timestamp array for ORRUBA.." << std::endl;
    //std::sort(orrubaTimeStamps_.begin(),orrubaTimeStamps_.end(),TSAscSort);

    //original gretina timestamp array
    std::cout << "Using loop to get timestamp array" << std::endl;
    for (int i = 0; i < nentriesGRETINA; i++) {
        tree_GRETINA->GetEntry(i);
        for (auto g2Event: g2->xtals) {
            gretinaTimeStamps_.push_back(std::make_pair(i, g2Event.timestamp));
            break;
        }
    }

    auto cp1 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(cp1-start);
    std::cout <<  dur.count()/1.0e6 << std::endl;

    tree_GRETINA->SetEstimate(-1);
    std::cout << "Using Draw to get timestamp array" << std::endl;
    Int_t testn = tree_GRETINA->Draw("Entry$:xtals.timestamp[0]","","goff");
    double* gtimestamparr= (double*)tree_GRETINA->GetVal(1);
    double* entryg = (double*)tree_GRETINA->GetVal(0);


    for(int i=0; i<testn; i++){
        gretinaTimeStamps2_.push_back(std::make_pair(entryg[i],gtimestamparr[i]));
    }
    std::sort(gretinaTimeStamps2_.begin(),gretinaTimeStamps2_.end(),TSAscSort);

    std::cout << "testn:" << testn << " nentries:" << nentriesGRETINA << " "<< gretinaTimeStamps_.size()<< std::endl;
    auto cp2 = std::chrono::high_resolution_clock::now();
    dur = std::chrono::duration_cast<std::chrono::microseconds>(cp2-cp1);
    std::cout <<  dur.count()/1.0e6 << std::endl;

    for(int i=0; i<gretinaTimeStamps_.size(); i++){
        assert(fabs(gtimestamparr[i]-gretinaTimeStamps_.at(i).second)<0.1);
        assert(fabs(entryg[i]-gretinaTimeStamps_.at(i).first)<0.1);
        //if(i<100) printf("%lf\t%d\n",entryg[i], gretinaTimeStamps_.at(i).first);
    }
    std::cout << "All timestamps match!" << std::endl;
    std::cout << "All entries match!" << std::endl;

    std::sort(gretinaTimeStamps_.begin(),gretinaTimeStamps_.end(),TSAscSort);


    std::cout << "Generated timestamp array for GRETINA.." << std::endl;
    // Loop through ORRUBA events and for each event, match to the corresponding GRETINA event based on the timestamp
    // The difference of timestamps is to be < 1000 which is a lot considering the timestamps between two ORRUBA events
    // are generally on the order of 100,000.
   // return;
    Long64_t nentriesMatched = 0;
//    gretinaTimeStamps2_=gretinaTimeStamps_;

    timeThreshold = 1000;
    timeFoundBreak = 0;
    timeNotFoundBreak = 1000;
    std::cout << "Matching indices.. " << std::endl;
    std::vector<matchedEvents> matchedEvents_, matchedEvents2_;

    size_t newstart = 0;
  //  /* //original match-loop
    for(size_t i = 0; i < orrubaTimeStamps_.size(); i++) { // SC: Loop through ORRUBA timestamps
        size_t found_j = 0;
        int found_index = 0;
        Long64_t orrubaTime = orrubaTimeStamps_[i].second;
        Bool_t found = false;

        size_t best_j;
        Long64_t closestTime = 100000;
        Long64_t gretinaTime;
        for(size_t j = 0; j < gretinaTimeStamps_.size(); j++) { // SC: Loop through GRETINA timestamps
            size_t timeDiff = fabs(orrubaTime - gretinaTimeStamps_[j].second); // SC: Find timing difference

            if((timeDiff < timeThreshold) && (timeDiff < closestTime)) { // If this is closest time difference, take it
                closestTime = fabs(orrubaTime - gretinaTimeStamps_[j].second);
                gretinaTime = gretinaTimeStamps_[j].second;
                best_j = gretinaTimeStamps_[j].first;
                found_index = j;
                found = true;
                //newstart = found_index;
            }
            else if(timeDiff > closestTime && found){
                break;
            }
            if(timeDiff > timeNotFoundBreak && (gretinaTimeStamps_[j].second > orrubaTime)){
                //newstart = found_index - 20;
                break; // SC: Looks like this breaks the statement if it seems a match isn't found
            }
        }

        // Record ORRUBA + GRETINA timestamps
        if(found) {
            matchedEvents hit = {i, best_j, orrubaTime, gretinaTime};
            matchedEvents_.push_back(hit);
            nentriesMatched++;
        }
        // Record ORRUBA hits that do not have a GRETINA timestamp
        else {
            matchedEvents hit = {i, 0, orrubaTime, 0};
            matchedEvents_.push_back(hit);
        }

        // Remove the first found_index elements and shift everything else down by found_index indices
        // This is so that we don't have to loop through GRETINA events that have already been matched
        // Don't do it for every event as it will slow it down too much. Every 500 seems to work well
        if((i % 500 == 0) && found) gretinaTimeStamps_.erase(gretinaTimeStamps_.begin(), gretinaTimeStamps_.begin() + found_index);
        if(i % 10000==0) std::cout << "Progress :" << static_cast<int>(i*100./orrubaTimeStamps_.size()) << " %\r";
    }


    std::cout << PrintOutput("\t\tMatched ORRUBA and GRETINA time stamps", "blue") << std::endl;
    auto cp3 = std::chrono::high_resolution_clock::now();
    dur = std::chrono::duration_cast<std::chrono::microseconds>(cp3-cp2);
    std::cout <<  dur.count()/1.0e6 << std::endl;

    newstart = 0;
    for(size_t i = 0; i < orrubaTimeStamps_.size(); i++) { // SC: Loop through ORRUBA timestamps
        size_t found_j = 0;
        int found_index = 0;
        Long64_t orrubaTime = orrubaTimeStamps_[i].second;
        Bool_t found = false;

        size_t best_j;
        Long64_t closestTime = 100000;
        Long64_t gretinaTime;
        for(size_t j = newstart; j < gretinaTimeStamps2_.size(); j++) { // SC: Loop through GRETINA timestamps
            size_t timeDiff = fabs(orrubaTime - gretinaTimeStamps2_[j].second); // SC: Find timing difference

            if((timeDiff < timeThreshold) && (timeDiff < closestTime)) { // If this is closest time difference, take it
                closestTime = fabs(orrubaTime - gretinaTimeStamps2_[j].second);
                gretinaTime = gretinaTimeStamps2_[j].second;
                best_j = gretinaTimeStamps2_[j].first;
                found_index = j;
                found = true;
                newstart = found_index;
            }
            else if(timeDiff > closestTime && found){
                break;
            }
            if(timeDiff > timeNotFoundBreak && (gretinaTimeStamps2_[j].second > orrubaTime)){
                break; // SC: Looks like this breaks the statement if it seems a match isn't found
            }
        }

        // Record ORRUBA + GRETINA timestamps
        if(found) {
            matchedEvents hit = {i, best_j, orrubaTime, gretinaTime};
            matchedEvents2_.push_back(hit);
            nentriesMatched++;
        }
        // Record ORRUBA hits that do not have a GRETINA timestamp
        else {
            matchedEvents hit = {i, 0, orrubaTime, 0};
            matchedEvents2_.push_back(hit);
        }

        // Remove the first found_index elements and shift everything else down by found_index indices
        // This is so that we don't have to loop through GRETINA events that have already been matched
        // Don't do it for every event as it will slow it down too much. Every 500 seems to work well
        //if((i % 500 == 0) && found) gretinaTimeStamps_.erase(gretinaTimeStamps_.begin(), gretinaTimeStamps_.begin() + found_index);
        if(i % 10000==0) std::cout << "Progress :" << static_cast<int>(i*100./orrubaTimeStamps_.size()) << " %\r";
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

    std::cout << PrintOutput("\t\tMatched ORRUBA and GRETINA time stamps", "blue") << std::endl;
    auto cp4 = std::chrono::high_resolution_clock::now();
    dur = std::chrono::duration_cast<std::chrono::microseconds>(cp4-cp3);
    std::cout <<  dur.count()/1.0e6 << std::endl;

    int badcount=0;
    for(int i=0; i<matchedEvents_.size(); i++){
        //assert(matchedEvents2_.at(i).orrubaNumber==matchedEvents_.at(i).orrubaNumber);
        //assert(matchedEvents2_.at(i).gretinaNumber==matchedEvents_.at(i).gretinaNumber);

/*        if(matchedEvents2_.at(i).orrubaNumber!=matchedEvents_.at(i).orrubaNumber ||
           matchedEvents2_.at(i).gretinaNumber!=matchedEvents_.at(i).gretinaNumber ||
           matchedEvents2_.at(i).orrubaTimeStamp!=matchedEvents_.at(i).orrubaTimeStamp ||
           matchedEvents2_.at(i).gretinaTimeStamp!=matchedEvents_.at(i).gretinaTimeStamp )*/{

        badcount +=1;
        std::cerr
        << matchedEvents2_.at(i).orrubaNumber << " " << matchedEvents_.at(i).orrubaNumber << " "
        << matchedEvents2_.at(i).gretinaNumber << " " << matchedEvents_.at(i).gretinaNumber << " "
        << matchedEvents2_.at(i).orrubaTimeStamp << " " << matchedEvents_.at(i).orrubaTimeStamp << " "
        << matchedEvents2_.at(i).gretinaTimeStamp << " " << matchedEvents_.at(i).gretinaTimeStamp <<
        std::endl;
        }
    }

    std::cout << " new:"<< matchedEvents2_.size() << " orig:" << matchedEvents_.size() << " badcount:" << badcount <<std::endl;

   // return;
    // Reset ORRUBA TTreeReaders
    t_ORRUBA.Restart();

    // Create Combined TTree
    TFile* f_Combined = new TFile(run.combinedPath.c_str(), "recreate");
    TTree* tree_Combined = new TTree("mergtree", "Combined ORRUBA and GRETINA data");

    // Set branch address if file contains tracked data
    if (run.withTracked){
        tree_GRETINA->SetBranchAddress("g1", &g1);
    }

    // Get ORRUBA branches from ORRUBA tree
    int RunNumber;

    tree_ORRUBA->SetBranchAddress("RunNumber", &RunNumber);

    // QQQ5 dE Detectors
    // ----------------------------------------------------------------------------------------
	tree_ORRUBA->SetBranchAddress("dQQQ5RingMul_dE",        &dQQQ5RingMul_dE);
	tree_ORRUBA->SetBranchAddress("dQQQ5DetRingMul_dE",     &dQQQ5DetRingMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRing_dE",        &dQQQ5DetRing_dE);
	tree_ORRUBA->SetBranchAddress("dQQQ5Ring_dE",           &dQQQ5Ring_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingChannel_dE",    &dQQQ5RingChannel_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingADC_dE",        &dQQQ5RingADC_dE);

    tree_ORRUBA->SetBranchAddress("dQQQ5SectorMul_dE",     &dQQQ5SectorMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSectorMul_dE",   &dQQQ5DetSectorMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSector_dE",      &dQQQ5DetSector_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5Sector_dE",         &dQQQ5Sector_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorChannel_dE",  &dQQQ5SectorChannel_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorADC_dE",      &dQQQ5SectorADC_dE);
    // ----------------------------------------------------------------------------------------

    // QQQ5 E Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("dQQQ5RingMul_E",        &dQQQ5RingMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRingMul_E",     &dQQQ5DetRingMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRing_E",        &dQQQ5DetRing_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5Ring_E",           &dQQQ5Ring_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingChannel_E",    &dQQQ5RingChannel_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingADC_E",        &dQQQ5RingADC_E);

    tree_ORRUBA->SetBranchAddress("dQQQ5SectorMul_E",     &dQQQ5SectorMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSectorMul_E",   &dQQQ5DetSectorMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSector_E",      &dQQQ5DetSector_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5Sector_E",         &dQQQ5Sector_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorChannel_E",  &dQQQ5SectorChannel_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorADC_E",      &dQQQ5SectorADC_E);
    // ----------------------------------------------------------------------------------------

    // Upstream QQQ5 Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("uQQQ5RingMul",        &uQQQ5RingMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetRingMul",     &uQQQ5DetRingMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetRing",        &uQQQ5DetRing);
    tree_ORRUBA->SetBranchAddress("uQQQ5Ring",           &uQQQ5Ring);
    tree_ORRUBA->SetBranchAddress("uQQQ5RingChannel",    &uQQQ5RingChannel);
    tree_ORRUBA->SetBranchAddress("uQQQ5RingADC",        &uQQQ5RingADC);

    tree_ORRUBA->SetBranchAddress("uQQQ5SectorMul",     &uQQQ5SectorMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetSectorMul",   &uQQQ5DetSectorMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetSector",      &uQQQ5DetSector);
    tree_ORRUBA->SetBranchAddress("uQQQ5Sector",         &uQQQ5Sector);
    tree_ORRUBA->SetBranchAddress("uQQQ5SectorChannel",  &uQQQ5SectorChannel);
    tree_ORRUBA->SetBranchAddress("uQQQ5SectorADC",      &uQQQ5SectorADC);
    // ----------------------------------------------------------------------------------------

    // BB10 Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("BB10Mul",                &BB10Mul);
    tree_ORRUBA->SetBranchAddress("BB10DetMul",             &BB10DetMul);
    tree_ORRUBA->SetBranchAddress("BB10Det",                &BB10Det);
    tree_ORRUBA->SetBranchAddress("BB10Strip",              &BB10Strip);
    tree_ORRUBA->SetBranchAddress("BB10Channel",            &BB10Channel);
    tree_ORRUBA->SetBranchAddress("BB10ADC",                &BB10ADC);
    // ----------------------------------------------------------------------------------------

    // Super X3 Downstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("dSX3LeftMul",            &dSX3LeftMul);
    tree_ORRUBA->SetBranchAddress("dSX3RightMul",           &dSX3RightMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetLeftMul",         &dSX3DetLeftMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetRightMul",        &dSX3DetRightMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetLeft",            &dSX3DetLeft);
    tree_ORRUBA->SetBranchAddress("dSX3DetRight",           &dSX3DetRight);
    tree_ORRUBA->SetBranchAddress("dSX3LeftStrip",          &dSX3LeftStrip);
    tree_ORRUBA->SetBranchAddress("dSX3RightStrip",         &dSX3RightStrip);
    tree_ORRUBA->SetBranchAddress("dSX3LeftChannel",        &dSX3LeftChannel);
    tree_ORRUBA->SetBranchAddress("dSX3RightChannel",       &dSX3RightChannel);
    tree_ORRUBA->SetBranchAddress("dSX3LeftADC",            &dSX3LeftADC);
    tree_ORRUBA->SetBranchAddress("dSX3RightADC",           &dSX3RightADC);

    tree_ORRUBA->SetBranchAddress("dSX3BackMul",            &dSX3BackMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetBackMul",         &dSX3DetBackMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetBack",            &dSX3DetBack);
    tree_ORRUBA->SetBranchAddress("dSX3BackSector",         &dSX3BackSector);
    tree_ORRUBA->SetBranchAddress("dSX3BackChannel",        &dSX3BackChannel);
    tree_ORRUBA->SetBranchAddress("dSX3BackADC",            &dSX3BackADC);
    // ----------------------------------------------------------------------------------------

    // Super X3 Upstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("uSX3LeftMul",            &uSX3LeftMul);
	tree_ORRUBA->SetBranchAddress("uSX3RightMul",           &uSX3RightMul);
	tree_ORRUBA->SetBranchAddress("uSX3DetLeftMul",         &uSX3DetLeftMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetRightMul",        &uSX3DetRightMul);
	tree_ORRUBA->SetBranchAddress("uSX3DetLeft",            &uSX3DetLeft);
	tree_ORRUBA->SetBranchAddress("uSX3DetRight",           &uSX3DetRight);
    tree_ORRUBA->SetBranchAddress("uSX3LeftStrip",          &uSX3LeftStrip);
    tree_ORRUBA->SetBranchAddress("uSX3RightStrip",         &uSX3RightStrip);
    tree_ORRUBA->SetBranchAddress("uSX3LeftChannel",        &uSX3LeftChannel);
    tree_ORRUBA->SetBranchAddress("uSX3RightChannel",       &uSX3RightChannel);
    tree_ORRUBA->SetBranchAddress("uSX3LeftADC",            &uSX3LeftADC);
    tree_ORRUBA->SetBranchAddress("uSX3RightADC",           &uSX3RightADC);

    tree_ORRUBA->SetBranchAddress("uSX3BackMul",            &uSX3BackMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetBackMul",         &uSX3DetBackMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetBack",            &uSX3DetBack);
    tree_ORRUBA->SetBranchAddress("uSX3BackSector",         &uSX3BackSector);
    tree_ORRUBA->SetBranchAddress("uSX3BackChannel",        &uSX3BackChannel);
    tree_ORRUBA->SetBranchAddress("uSX3BackADC",            &uSX3BackADC);
    // ----------------------------------------------------------------------------------------

    // Timing
    // ----------------------------------------------------------------------------------------

    tree_ORRUBA->SetBranchAddress("tdcSilicon",             &TDCSilicon);
    tree_ORRUBA->SetBranchAddress("tdcSiliconDivTrig",      &TDCSiliconDivTrig);
    tree_ORRUBA->SetBranchAddress("tdcSiliconGRETINATrig",  &TDCSiliconGRETINATrig);
    tree_ORRUBA->SetBranchAddress("tdcRF",                  &TDCRF);
    tree_ORRUBA->SetBranchAddress("tdcGRETINA",             &TDCGRETINA);
    tree_ORRUBA->SetBranchAddress("tdcSiliconAlt",          &TDCSiliconAlt);
    tree_ORRUBA->SetBranchAddress("tdcSiliconUpstream",     &TDCSiliconUpstream);

    tree_ORRUBA->SetBranchAddress("timeStamp", &TimeStamp);
    // ----------------------------------------------------------------------------------------

    // Set ORRUBA branches in Combined tree
    int fRunNumber;

    tree_Combined->Branch("RunNumber", &fRunNumber, "RunNumber/I");

    // QQQ5 dE Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dQQQ5RingMul_dE",        &fdQQQ5RingMul_dE,      "dQQQ5RingMul_dE/I");
    tree_Combined->Branch("dQQQ5DetRingMul_dE",     &fdQQQ5DetRingMul_dE,       "dQQQ5DetRingMul_dE[2]/I");
    tree_Combined->Branch("dQQQ5DetRing_dE",        &fdQQQ5DetRing_dE,      "dQQQ5DetRing_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5Ring_dE",           &fdQQQ5Ring_dE,         "dQQQ5Ring_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5RingChannel_dE",    &fdQQQ5RingChannel_dE,      "dQQQ5RingChannel_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5RingADC_dE",        &fdQQQ5RingADC_dE,          "dQQQ5RingADC_dE[dQQQ5RingMul_dE]/I");

    tree_Combined->Branch("dQQQ5SectorMul_dE",      &fdQQQ5SectorMul_dE,        "dQQQ5SectorMul_dE/I");
    tree_Combined->Branch("dQQQ5DetSectorMul_dE",   &fdQQQ5DetSectorMul_dE,     "dQQQ5DetSectorMul_dE[2]/I");
    tree_Combined->Branch("dQQQ5DetSector_dE",      &fdQQQ5DetSector_dE,        "dQQQ5DetSector_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5Sector_dE",         &fdQQQ5Sector_dE,           "dQQQ5Sector_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5SectorChannel_dE",  &fdQQQ5SectorChannel_dE,        "dQQQ5SectorChannel_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5SectorADC_dE",      &fdQQQ5SectorADC_dE,        "dQQQ5SectorADC_dE[dQQQ5SectorMul_dE]/I");
    // ----------------------------------------------------------------------------------------

    // QQQ5 E Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dQQQ5RingMul_E",        &fdQQQ5RingMul_E,      "dQQQ5RingMul_E/I");
    tree_Combined->Branch("dQQQ5DetRingMul_E",     &fdQQQ5DetRingMul_E,       "dQQQ5DetRingMul_E[2]/I");
    tree_Combined->Branch("dQQQ5DetRing_E",        &fdQQQ5DetRing_E,      "dQQQ5DetRing_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5Ring_E",           &fdQQQ5Ring_E,         "dQQQ5Ring_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5RingChannel_E",    &fdQQQ5RingChannel_E,      "dQQQ5RingChannel_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5RingADC_E",        &fdQQQ5RingADC_E,          "dQQQ5RingADC_E[dQQQ5RingMul_E]/I");

    tree_Combined->Branch("dQQQ5SectorMul_E",      &fdQQQ5SectorMul_E,        "dQQQ5SectorMul_E/I");
    tree_Combined->Branch("dQQQ5DetSectorMul_E",   &fdQQQ5DetSectorMul_E,     "dQQQ5DetSectorMul_E[2]/I");
    tree_Combined->Branch("dQQQ5DetSector_E",      &fdQQQ5DetSector_E,        "dQQQ5DetSector_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5Sector_E",         &fdQQQ5Sector_E,           "dQQQ5Sector_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5SectorChannel_E",  &fdQQQ5SectorChannel_E,        "dQQQ5SectorChannel_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5SectorADC_E",      &fdQQQ5SectorADC_E,        "dQQQ5SectorADC_E[dQQQ5SectorMul_E]/I");
    // ----------------------------------------------------------------------------------------

    // Upstream QQQ5 Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("uQQQ5RingMul",        &fuQQQ5RingMul,      "uQQQ5RingMul/I");
    tree_Combined->Branch("uQQQ5DetRingMul",     &fuQQQ5DetRingMul,       "uQQQ5DetRingMul[2]/I");
    tree_Combined->Branch("uQQQ5DetRing",        &fuQQQ5DetRing,      "uQQQ5DetRing[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5Ring",           &fuQQQ5Ring,         "uQQQ5Ring[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5RingChannel",    &fuQQQ5RingChannel,      "uQQQ5RingChannel[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5RingADC",        &fuQQQ5RingADC,          "uQQQ5RingADC[uQQQ5RingMul]/I");

    tree_Combined->Branch("uQQQ5SectorMul",      &fuQQQ5SectorMul,        "uQQQ5SectorMul/I");
    tree_Combined->Branch("uQQQ5DetSectorMul",   &fuQQQ5DetSectorMul,     "uQQQ5DetSectorMul[2]/I");
    tree_Combined->Branch("uQQQ5DetSector",      &fuQQQ5DetSector,        "uQQQ5DetSector[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5Sector",         &fuQQQ5Sector,           "uQQQ5Sector[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5SectorChannel",  &fuQQQ5SectorChannel,        "uQQQ5SectorChannel[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5SectorADC",      &fuQQQ5SectorADC,        "uQQQ5SectorADC[uQQQ5SectorMul]/I");
    // ----------------------------------------------------------------------------------------

    // BB10 Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("BB10Mul",                &fBB10Mul,          "BB10Mul/I");
    tree_Combined->Branch("BB10DetMul",             &fBB10DetMul,       "BB10DetMul[12]/I");
    tree_Combined->Branch("BB10Det",                &fBB10Det,          "BB10Det[BB10Mul]/I");
    tree_Combined->Branch("BB10Strip",              &fBB10Strip,        "BB10Strip[BB10Mul]/I");
    tree_Combined->Branch("BB10Channel",            &fBB10Channel,      "BB10Channel[BB10Mul]/I");
    tree_Combined->Branch("BB10ADC",                &fBB10ADC,          "BB10ADC[BB10Mul]/I");
    // ----------------------------------------------------------------------------------------

    // Super X3 Downstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dSX3LeftMul",            &fdSX3LeftMul,      "dSX3LeftMul/I");
    tree_Combined->Branch("dSX3RightMul",           &fdSX3RightMul,     "dSX3RightMul/I");
    tree_Combined->Branch("dSX3DetLeftMul",         &fdSX3DetLeftMul,       "dSX3DetLeftMul[12]/I");
    tree_Combined->Branch("dSX3DetRightMul",        &fdSX3DetRightMul,      "dSX3DetRightMul[12]/I");
    tree_Combined->Branch("dSX3DetLeft",            &fdSX3DetLeft,      "dSX3DetLeft[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3DetRight",           &fdSX3DetRight,     "dSX3DetRight[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftStrip",          &fdSX3LeftStrip,        "dSX3LeftStrip[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightStrip",         &fdSX3RightStrip,       "dSX3RightStrip[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftChannel",        &fdSX3LeftChannel,      "dSX3LeftChannel[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightChannel",       &fdSX3RightChannel,     "dSX3RightChannel[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftADC",            &fdSX3LeftADC,      "dSX3LeftADC[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightADC",           &fdSX3RightADC,     "dSX3RightADC[dSX3RightMul]/I");

    tree_Combined->Branch("dSX3BackMul",            &fdSX3BackMul,          "dSX3BackMul/I");
    tree_Combined->Branch("dSX3DetBackMul",         &fdSX3DetBackMul,           "dSX3DetBackMul[12]/I");
    tree_Combined->Branch("dSX3DetBack",            &fdSX3DetBack,          "dSX3DetBack[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackSector",         &fdSX3BackSector,       "dSX3BackSector[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackChannel",        &fdSX3BackChannel,      "dSX3BackChannel[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackADC",            &fdSX3BackADC,      "dSX3BackADC[dSX3BackMul]/I");
    // ----------------------------------------------------------------------------------------

    // Super X3 Upstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("uSX3LeftMul",            &fuSX3LeftMul,      "uSX3LeftMul/I");
    tree_Combined->Branch("uSX3RightMul",           &fuSX3RightMul,     "uSX3RightMul/I");
    tree_Combined->Branch("uSX3DetLeftMul",         &fuSX3DetLeftMul,       "uSX3DetLeftMul[12]/I");
    tree_Combined->Branch("uSX3DetRightMul",        &fuSX3DetRightMul,      "uSX3DetRightMul[12]/I");
    tree_Combined->Branch("uSX3DetLeft",            &fuSX3DetLeft,      "uSX3DetLeft[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3DetRight",           &fuSX3DetRight,     "uSX3DetRight[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftStrip",          &fuSX3LeftStrip,        "uSX3LeftStrip[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightStrip",         &fuSX3RightStrip,       "uSX3RightStrip[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftChannel",        &fuSX3LeftChannel,      "uSX3LeftChannel[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightChannel",       &fuSX3RightChannel,     "uSX3RightChannel[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftADC",            &fuSX3LeftADC,      "uSX3LeftADC[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightADC",           &fuSX3RightADC,     "uSX3RightADC[uSX3RightMul]/I");

    tree_Combined->Branch("uSX3BackMul",            &fuSX3BackMul,          "uSX3BackMul/I");
    tree_Combined->Branch("uSX3DetBackMul",         &fuSX3DetBackMul,           "uSX3DetBackMul[12]/I");
    tree_Combined->Branch("uSX3DetBack",            &fuSX3DetBack,          "uSX3DetBack[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackSector",         &fuSX3BackSector,       "uSX3BackSector[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackChannel",        &fuSX3BackChannel,      "uSX3BackChannel[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackADC",            &fuSX3BackADC,      "uSX3BackADC[uSX3BackMul]/I");

    // ----------------------------------------------------------------------------------------

    // Timing
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("tdcSilicon",             &fTDCSilicon);
    tree_Combined->Branch("tdcSiliconDivTrig",      &fTDCSiliconDivTrig);
    tree_Combined->Branch("tdcSiliconGRETINATrig",  &fTDCSiliconGRETINATrig);
    tree_Combined->Branch("tdcRF",                  &fTDCRF);
    tree_Combined->Branch("tdcGRETINA",             &fTDCGRETINA);
    tree_Combined->Branch("tdcSiliconAlt",          &fTDCSiliconAlt);
    tree_Combined->Branch("tdcSiliconUpstream",     &fTDCSiliconUpstream);

    tree_Combined->Branch("timeStamp",              &fTimeStamp);
    tree_Combined->Branch("GRETINATimeStamp",       &fGRETINATimeStamp);
    // ----------------------------------------------------------------------------------------


    // Set GRETINA branches in Combined tree
    tree_Combined->Branch("foundGRETINA", &foundGRETINA);

    // Mode 2
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("xtalsMul", &xtalsMul, "xtalsMul/I");
    tree_Combined->Branch("xtals_xlab", &xtals_xlab, "xtals_xlab[xtalsMul]/F");
    tree_Combined->Branch("xtals_ylab", &xtals_ylab, "xtals_ylab[xtalsMul]/F");
    tree_Combined->Branch("xtals_zlab", &xtals_zlab, "xtals_zlab[xtalsMul]/F");
    tree_Combined->Branch("xtals_cc", &xtals_cc, "xtals_cc[xtalsMul]/F");
    tree_Combined->Branch("xtals_edop", &xtals_edop, "xtals_edop[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopMaxInt", &xtals_edopMaxInt, "xtals_edopMaxInt[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopSeg", &xtals_edopSeg, "xtals_edopSeg[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopXtal", &xtals_edopXtal, "xtals_edopXtal[xtalsMul]/F");
    tree_Combined->Branch("xtals_crystalNum", &xtals_crystalNum, "xtals_crystalNum[xtalsMul]/I");
    tree_Combined->Branch("xtals_quadNum", &xtals_quadNum, "xtals_quadNum[xtalsMul]/I");
    tree_Combined->Branch("xtals_t0", &xtals_t0, "xtals_t0[xtalsMul]/F");
    tree_Combined->Branch("xtals_timestamp", &xtals_timestamp, "xtals_timestamp[xtalsMul]/L");
    // ----------------------------------------------------------------------------------------

    // Mode 1 if selected
    // ----------------------------------------------------------------------------------------
    if (run.withTracked) {
        tree_Combined->Branch("gammasMul", &gammasMul, "gammasMul/I");
        tree_Combined->Branch("gammas_cc", &gammas_cc, "gammas_cc[gammasMul]/F");
        tree_Combined->Branch("gammas_xlab", &gammas_xlab,  "gammas_xlab[gammasMul]/F");
        tree_Combined->Branch("gammas_ylab", &gammas_ylab,  "gammas_ylab[gammasMul]/F");
        tree_Combined->Branch("gammas_zlab", &gammas_zlab,  "gammas_zlab[gammasMul]/F");
        tree_Combined->Branch("gammas_timestamp", &gammas_timestamp, "gammas_timestamp[gammasMul]/L");
    }
    // ----------------------------------------------------------------------------------------

    for(auto matchedEvent: matchedEvents_) {

        // Handle ORRUBA
        tree_ORRUBA->GetEntry(matchedEvent.orrubaNumber);
        fRunNumber = RunNumber;

		// First copy QQQ5 dE data to merged tree
        // ----------------------------------------------------------------------------------------
        fdQQQ5RingMul_dE = dQQQ5RingMul_dE;
        for(int i=0; i<dQQQ5RingMul_dE; i++) {

            fdQQQ5DetRing_dE[i] = dQQQ5DetRing_dE[i];
            fdQQQ5Ring_dE[i] = dQQQ5Ring_dE[i];
            fdQQQ5RingChannel_dE[i] = dQQQ5RingChannel_dE[i];
            fdQQQ5RingADC_dE[i] = dQQQ5RingADC_dE[i];
        }

        fdQQQ5SectorMul_dE = dQQQ5SectorMul_dE;
        for(int i=0; i<dQQQ5SectorMul_dE; i++) {
            fdQQQ5DetSector_dE[i] = dQQQ5DetSector_dE[i];
            fdQQQ5Sector_dE[i] = dQQQ5Sector_dE[i];
            fdQQQ5SectorChannel_dE[i] = dQQQ5SectorChannel_dE[i];
            fdQQQ5SectorADC_dE[i] = dQQQ5SectorADC_dE[i];
        }

        for(int i=0; i<2; i++) {
            fdQQQ5DetRingMul_dE[i] = dQQQ5DetRingMul_dE[i];
            fdQQQ5DetSectorMul_dE[i] = dQQQ5DetSectorMul_dE[i];
        }
        // ----------------------------------------------------------------------------------------

		// Then QQQ5 E
        // ----------------------------------------------------------------------------------------
        fdQQQ5RingMul_E = dQQQ5RingMul_E;
        //std::cout << "dQQQ5RingMul_E = " << dQQQ5RingMul_E << std::endl;
        for(int i=0; i<dQQQ5RingMul_E; i++) {

            fdQQQ5DetRing_E[i] = dQQQ5DetRing_E[i];
            fdQQQ5Ring_E[i] = dQQQ5Ring_E[i];
            fdQQQ5RingChannel_E[i] = dQQQ5RingChannel_E[i];
            fdQQQ5RingADC_E[i] = dQQQ5RingADC_E[i];
        }

        fdQQQ5SectorMul_E = dQQQ5SectorMul_E;
        for(int i=0; i<dQQQ5SectorMul_E; i++) {
            fdQQQ5DetSector_E[i] = dQQQ5DetSector_E[i];
            fdQQQ5Sector_E[i] = dQQQ5Sector_E[i];
            fdQQQ5SectorChannel_E[i] = dQQQ5SectorChannel_E[i];
            fdQQQ5SectorADC_E[i] = dQQQ5SectorADC_E[i];
        }

        for(int i=0; i<4; i++) {
            fdQQQ5DetRingMul_E[i] = dQQQ5DetRingMul_E[i];
            fdQQQ5DetSectorMul_E[i] = dQQQ5DetSectorMul_E[i];
        }
        // ----------------------------------------------------------------------------------------

		// Then Upstream QQQ5
        // ----------------------------------------------------------------------------------------
        fuQQQ5RingMul = uQQQ5RingMul;
        for(int i=0; i<uQQQ5RingMul; i++) {

            fuQQQ5DetRing[i] = uQQQ5DetRing[i];
            fuQQQ5Ring[i] = uQQQ5Ring[i];
            fuQQQ5RingChannel[i] = uQQQ5RingChannel[i];
            fuQQQ5RingADC[i] = uQQQ5RingADC[i];
        }

        fuQQQ5SectorMul = uQQQ5SectorMul;
        for(int i=0; i<uQQQ5SectorMul; i++) {
            fuQQQ5DetSector[i] = uQQQ5DetSector[i];
            fuQQQ5Sector[i] = uQQQ5Sector[i];
            fuQQQ5SectorChannel[i] = uQQQ5SectorChannel[i];
            fuQQQ5SectorADC[i] = uQQQ5SectorADC[i];
        }
        for(int i=0; i<4; i++) {
            fuQQQ5DetRingMul[i] = uQQQ5DetRingMul[i];
            fuQQQ5DetSectorMul[i] = uQQQ5DetSectorMul[i];
        }
        // ----------------------------------------------------------------------------------------

		// Now BB10
        // ----------------------------------------------------------------------------------------
        fBB10Mul = BB10Mul;
        for(int i=0; i<BB10Mul; i++) {
            fBB10Det[i] = BB10Det[i];
            fBB10Strip[i] = BB10Strip[i];
            fBB10Channel[i] = BB10Channel[i];
            fBB10ADC[i] = BB10ADC[i];
        }
        for(int i=0; i<12; i++) {
            fBB10DetMul[i] = BB10DetMul[i];
        }
        // ----------------------------------------------------------------------------------------


		// Now dSX3s
        // ----------------------------------------------------------------------------------------
        fdSX3LeftMul = dSX3LeftMul;
        for(int i=0; i<dSX3LeftMul; i++) {
            fdSX3DetLeft[i] = dSX3DetLeft[i];
            fdSX3LeftStrip[i] = dSX3LeftStrip[i];
            fdSX3LeftChannel[i] = dSX3LeftChannel[i];
            fdSX3LeftADC[i] = dSX3LeftADC[i];
        }
        fdSX3RightMul = dSX3RightMul;
        for(int i=0; i<dSX3RightMul; i++) {
            fdSX3DetRight[i] = dSX3DetRight[i];
            fdSX3RightStrip[i] = dSX3RightStrip[i];
            fdSX3RightChannel[i] = dSX3RightChannel[i];
            fdSX3RightADC[i] = dSX3RightADC[i];
        }
        fdSX3BackMul = dSX3BackMul;
        for(int i=0; i<dSX3BackMul; i++) {
            fdSX3DetBack[i] = dSX3DetBack[i];
            fdSX3BackSector[i] = dSX3BackSector[i];
            fdSX3BackChannel[i] = dSX3BackChannel[i];
            fdSX3BackADC[i] = dSX3BackADC[i];
        }
        for(int i=0; i<12; i++) {
            fdSX3DetLeftMul[i] = dSX3DetLeftMul[i];
            fdSX3DetRightMul[i] = dSX3DetRightMul[i];
            fdSX3DetBackMul[i] = dSX3DetBackMul[i];
        }
        // ----------------------------------------------------------------------------------------

		// Finally uSX3s
        // ----------------------------------------------------------------------------------------
        fuSX3LeftMul = uSX3LeftMul;
        for(int i=0; i<uSX3LeftMul; i++) {
            fuSX3DetLeft[i] = uSX3DetLeft[i];
            fuSX3LeftStrip[i] = uSX3LeftStrip[i];
            fuSX3LeftChannel[i] = uSX3LeftChannel[i];
            fuSX3LeftADC[i] = uSX3LeftADC[i];
        }
        fuSX3RightMul = uSX3RightMul;
        for(int i=0; i<uSX3RightMul; i++) {
            fuSX3DetRight[i] = uSX3DetRight[i];
            fuSX3RightStrip[i] = uSX3RightStrip[i];
            fuSX3RightChannel[i] = uSX3RightChannel[i];
            fuSX3RightADC[i] = uSX3RightADC[i];
        }
        fuSX3BackMul = uSX3BackMul;
        for(int i=0; i<uSX3BackMul; i++) {
            fuSX3DetBack[i] = uSX3DetBack[i];
            fuSX3BackSector[i] = uSX3BackSector[i];
            fuSX3BackChannel[i] = uSX3BackChannel[i];
            fuSX3BackADC[i] = uSX3BackADC[i];
        }
        for(int i=0; i<12; i++) {
            fuSX3DetLeftMul[i] = uSX3DetLeftMul[i];
            fuSX3DetRightMul[i] = uSX3DetRightMul[i];
            fuSX3DetBackMul[i] = uSX3DetBackMul[i];
        }
        // ----------------------------------------------------------------------------------------

        fTDCSilicon = TDCSilicon;
        fTDCSiliconDivTrig = TDCSiliconDivTrig;
        fTDCSiliconGRETINATrig = TDCSiliconGRETINATrig;
        fTDCRF = TDCRF;
        fTDCGRETINA = TDCGRETINA;
        fTDCSiliconAlt = TDCSiliconAlt;
        fTDCSiliconUpstream = TDCSiliconUpstream;

        fTimeStamp = TimeStamp;
		fGRETINATimeStamp = matchedEvent.gretinaTimeStamp;

        // Handle GRETINA
        xtalsMul = 0;
        gammasMul = 0;

        if(matchedEvent.gretinaTimeStamp > 1) {
            foundGRETINA = true;
            tree_GRETINA->GetEntry(matchedEvent.gretinaNumber);
            for(auto g2Event: g2->xtals) {
                xtals_xlab[xtalsMul] = g2Event.maxIntPtXYZLab().X();
                xtals_ylab[xtalsMul] = g2Event.maxIntPtXYZLab().Y();
                xtals_zlab[xtalsMul] = g2Event.maxIntPtXYZLab().Z();
                xtals_cc[xtalsMul] = g2Event.cc;
                xtals_edop[xtalsMul] = g2Event.edop;
                xtals_edopMaxInt[xtalsMul] = g2Event.edop_maxInt;
                xtals_edopSeg[xtalsMul] = g2Event.edopSeg;
                xtals_edopXtal[xtalsMul] = g2Event.edopXtal;
                xtals_crystalNum[xtalsMul] = g2Event.crystalNum;
                xtals_quadNum[xtalsMul] = g2Event.quadNum;
                xtals_t0[xtalsMul] = g2Event.t0;
                xtals_timestamp[xtalsMul] = g2Event.timestamp;
                xtalsMul++;
            }

            if (run.withTracked) {
                for(auto g1Event: g1->gammas) {
                    gammas_cc[gammasMul] = g1Event.cc;
                    gammas_xlab[gammasMul] = g1Event.xyzLab1.X();
                    gammas_ylab[gammasMul] = g1Event.xyzLab1.Y();
                    gammas_zlab[gammasMul] = g1Event.xyzLab1.Z();
                    gammas_timestamp[gammasMul] = g1Event.timestamp;
                    gammasMul++;
                }
            }

        }
        else {
            foundGRETINA = false;
        }

        tree_Combined->Fill();
        if(matchedEvent.orrubaNumber % 10000==0) std::cout << "Progress :" << static_cast<int>(matchedEvent.orrubaNumber*100.0/nentriesORRUBA) << " %\r\a";
    }
    std::cout << std::endl;
    tree_Combined->Write();
    f_Combined->Close();

    f_ORRUBA->Close();
    f_GRETINA->Close();

    std::cout << PrintOutput("\t\tFinished combining ORRUBA and GRETINA Trees based on time stamps", "blue") << std::endl;
    std::cout << PrintOutput("\t\tCombined TTree 'data' written to file: ", "blue") << run.combinedPath << std::endl;


    std::ofstream statFile("../LogFiles/unpack.log",std::ofstream::app);
    statFile << "Run Number " << fRunNumber << std::endl;
    statFile << "EB_DIFF_TIME:" << '\t' << '\t' << EB_DIFF_TIME << std::endl;
    statFile << "timeThreshold:" << '\t' << '\t' << timeThreshold << std::endl;
    statFile << "timeFoundBreak" << '\t' << '\t' << timeFoundBreak << std::endl;
    statFile << "timeNotFoundBreak" << '\t' << '\t' << timeFoundBreak << std::endl;
    statFile << "ORRUBA Entries" << '\t' << '\t' << nentriesORRUBA << std::endl;
    statFile << "GRETINA Entries" << '\t' << '\t' << nentriesGRETINA << std::endl;
    statFile << "Matched Entries" << '\t' << '\t' << nentriesMatched << std::endl;
    statFile << "Time to match" << (duration.count()/1000000.0) << std::endl;
    statFile << std::endl;
    statFile.close();

}


void Unpack::CombineReader2(fileListStruct run) {

    // SC: Declare timing variables that are used in event building
    Long64_t timeThreshold, timeFoundBreak, timeNotFoundBreak;

    std::cout << PrintOutput("\tCombining ORRUBA and GRETINA trees based on timestamp:", "yellow") << std::endl;

    std::cout << PrintOutput("\t\tOpening ORRUBA file: ", "blue") << run.rootPathRaw.c_str() << std::endl;
    auto f_ORRUBA = TFile::Open(Form("%s", run.rootPathRaw.c_str()));
    if(!f_ORRUBA) {
        std::cout << PrintOutput("\t\tCould not open Combined file: ", "red") << run.rootPathRaw.c_str() << std::endl;
        return;
    }
    TTreeReader t_ORRUBA("dataRaw", f_ORRUBA);
    Long64_t nentriesORRUBA = t_ORRUBA.GetEntries(true);
    if(nentriesORRUBA == 0) {
        std::cout << PrintOutput("\t\tCould not open TTree 'data' in ORRBUA file", "red") << std::endl;
        return;
    }
    TTree *tree_ORRUBA = (TTree*)f_ORRUBA->Get("dataRaw");

    std::cout << PrintOutput("\t\tOpening GRETINA file: ", "blue") << run.gretinaPath.c_str() << std::endl;
    auto f_GRETINA = TFile::Open(Form("%s", run.gretinaPath.c_str()));
    if(!f_GRETINA) {
        std::cout << PrintOutput("\t\tCould not open GRETINA file: ", "red") << run.gretinaPath.c_str() << std::endl;
        return;
    }

    TTree *tree_GRETINA = (TTree*)f_GRETINA->Get("teb");
    Long64_t nentriesGRETINA = tree_GRETINA->GetEntries();
    g1OUT *g1 = 0;
    g2OUT *g2 = 0;

    // g2 branch in GRETINA tree holds mode 2 data
    tree_GRETINA->SetBranchAddress("g2", &g2);

    std::cout << PrintOutput("\t\t\tTotal ORRUBA Entries: ", "yellow") << nentriesORRUBA << PrintOutput("; Total GRETINA Entries: ", "yellow") << nentriesGRETINA << std::endl;

    TTreeReaderValue<ULong64_t> orrubaTimeStamp(t_ORRUBA, "timeStamp");

    std::vector<std::pair<Int_t, Long64_t> > orrubaTimeStamps_;
    std::vector<std::pair<Int_t, Long64_t> > gretinaTimeStamps_;

    // Loop through ORRUBA events and get the timestamps
    auto start = std::chrono::high_resolution_clock::now();
    Int_t i = 0;
    while(t_ORRUBA.Next()) {
        orrubaTimeStamps_.push_back(std::make_pair(i, *orrubaTimeStamp));
        i++;
    }
    //std::sort(orrubaTimeStamps_.begin(),orrubaTimeStamps_.end(),TSAscSort);
    std::cout << "Generated timestamp array for ORRUBA.." << std::endl;

    auto cp1 = std::chrono::high_resolution_clock::now();

    tree_GRETINA->SetEstimate(-1);
    std::cout << "Using Draw to get timestamp array" << std::endl;
    Int_t testn = tree_GRETINA->Draw("Entry$:xtals.timestamp[0]","","goff");
    double* gtimestamparr= (double*)tree_GRETINA->GetVal(1);
    double* entryg = (double*)tree_GRETINA->GetVal(0);

    for(int i=0; i<testn; i++){
        gretinaTimeStamps_.push_back(std::make_pair(entryg[i],gtimestamparr[i]));
    }
    std::sort(gretinaTimeStamps_.begin(),gretinaTimeStamps_.end(),TSAscSort);

    std::cout << "testn:" << testn << " nentries:" << nentriesGRETINA << " "<< gretinaTimeStamps_.size()<< std::endl;
    auto cp2 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(cp2-cp1);
    std::cout <<  dur.count()/1.0e6 << std::endl;
    std::cout << "Generated timestamp array for GRETINA.." << std::endl;

    // Loop through ORRUBA events and for each event, match to the corresponding GRETINA event based on the timestamp
    // The difference of timestamps is to be < 1000 which is a lot considering the timestamps between two ORRUBA events
    // are generally on the order of 100,000.
    Long64_t nentriesMatched = 0;

    timeThreshold = 1000;
    timeFoundBreak = 0;
    timeNotFoundBreak = 1000;
    std::cout << "Matching indices.. " << std::endl;
    std::vector<matchedEvents> matchedEvents_;

    size_t newstart = 0;
    for(size_t i = 0; i < orrubaTimeStamps_.size(); i++) { // SC: Loop through ORRUBA timestamps
        size_t found_j = 0;
        int found_index = 0;
        Long64_t orrubaTime = orrubaTimeStamps_[i].second;
        Bool_t found = false;

        size_t best_j;
        Long64_t closestTime = 100000;
        Long64_t gretinaTime;
        for(size_t j = newstart; j < gretinaTimeStamps_.size(); j++) { // SC: Loop through GRETINA timestamps
            size_t timeDiff = fabs(orrubaTime - gretinaTimeStamps_[j].second); // SC: Find timing difference

            if((timeDiff < timeThreshold) && (timeDiff < closestTime)) { // If this is closest time difference, take it
                closestTime = fabs(orrubaTime - gretinaTimeStamps_[j].second);
                gretinaTime = gretinaTimeStamps_[j].second;
                best_j = gretinaTimeStamps_[j].first;
                found_index = j;
                found = true;
                newstart = found_index;
            }
            else if(timeDiff > closestTime && found){
                break;
            }
            if(timeDiff > timeNotFoundBreak && (gretinaTimeStamps_[j].second > orrubaTime)){
                break; // SC: Looks like this breaks the statement if it seems a match isn't found
            }
        }

        // Record ORRUBA + GRETINA timestamps
        if(found) {
            matchedEvents hit = {i, best_j, orrubaTime, gretinaTime};
            matchedEvents_.push_back(hit);
            nentriesMatched++;
        }
        // Record ORRUBA hits that do not have a GRETINA timestamp
        else {
            matchedEvents hit = {i, 0, orrubaTime, 0};
            matchedEvents_.push_back(hit);
        }

        // Remove the first found_index elements and shift everything else down by found_index indices
        // This is so that we don't have to loop through GRETINA events that have already been matched
        // Don't do it for every event as it will slow it down too much. Every 500 seems to work well
        //if((i % 500 == 0) && found) gretinaTimeStamps_.erase(gretinaTimeStamps_.begin(), gretinaTimeStamps_.begin() + found_index);
        if(i % 10000==0) std::cout << "Progress :" << static_cast<int>(i*100./orrubaTimeStamps_.size()) << " %\r";
    }

    std::vector<std::pair<Int_t,Long64_t>>().swap(gretinaTimeStamps_);
    std::vector<std::pair<Int_t,Long64_t>>().swap(orrubaTimeStamps_);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);

    std::cout << PrintOutput("\t\tMatched ORRUBA and GRETINA time stamps", "blue") << std::endl;
    auto cp3 = std::chrono::high_resolution_clock::now();
    dur = std::chrono::duration_cast<std::chrono::microseconds>(cp3-cp2);
    std::cout <<  dur.count()/1.0e6 << std::endl;

    // Reset ORRUBA TTreeReaders
    t_ORRUBA.Restart();

    // Create Combined TTree
    TFile* f_Combined = new TFile(run.combinedPath.c_str(), "recreate");
    TTree* tree_Combined = new TTree("mergtree", "Combined ORRUBA and GRETINA data");

    // Set branch address if file contains tracked data
    if (run.withTracked){
        tree_GRETINA->SetBranchAddress("g1", &g1);
    }

    // Get ORRUBA branches from ORRUBA tree
    int RunNumber;

    tree_ORRUBA->SetBranchAddress("RunNumber", &RunNumber);

    // QQQ5 dE Detectors
    // ----------------------------------------------------------------------------------------
	tree_ORRUBA->SetBranchAddress("dQQQ5RingMul_dE",        &dQQQ5RingMul_dE);
	tree_ORRUBA->SetBranchAddress("dQQQ5DetRingMul_dE",     &dQQQ5DetRingMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRing_dE",        &dQQQ5DetRing_dE);
	tree_ORRUBA->SetBranchAddress("dQQQ5Ring_dE",           &dQQQ5Ring_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingChannel_dE",    &dQQQ5RingChannel_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingADC_dE",        &dQQQ5RingADC_dE);

    tree_ORRUBA->SetBranchAddress("dQQQ5SectorMul_dE",     &dQQQ5SectorMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSectorMul_dE",   &dQQQ5DetSectorMul_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSector_dE",      &dQQQ5DetSector_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5Sector_dE",         &dQQQ5Sector_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorChannel_dE",  &dQQQ5SectorChannel_dE);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorADC_dE",      &dQQQ5SectorADC_dE);
    // ----------------------------------------------------------------------------------------

    // QQQ5 E Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("dQQQ5RingMul_E",        &dQQQ5RingMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRingMul_E",     &dQQQ5DetRingMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetRing_E",        &dQQQ5DetRing_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5Ring_E",           &dQQQ5Ring_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingChannel_E",    &dQQQ5RingChannel_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5RingADC_E",        &dQQQ5RingADC_E);

    tree_ORRUBA->SetBranchAddress("dQQQ5SectorMul_E",     &dQQQ5SectorMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSectorMul_E",   &dQQQ5DetSectorMul_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5DetSector_E",      &dQQQ5DetSector_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5Sector_E",         &dQQQ5Sector_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorChannel_E",  &dQQQ5SectorChannel_E);
    tree_ORRUBA->SetBranchAddress("dQQQ5SectorADC_E",      &dQQQ5SectorADC_E);
    // ----------------------------------------------------------------------------------------

    // Upstream QQQ5 Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("uQQQ5RingMul",        &uQQQ5RingMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetRingMul",     &uQQQ5DetRingMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetRing",        &uQQQ5DetRing);
    tree_ORRUBA->SetBranchAddress("uQQQ5Ring",           &uQQQ5Ring);
    tree_ORRUBA->SetBranchAddress("uQQQ5RingChannel",    &uQQQ5RingChannel);
    tree_ORRUBA->SetBranchAddress("uQQQ5RingADC",        &uQQQ5RingADC);

    tree_ORRUBA->SetBranchAddress("uQQQ5SectorMul",     &uQQQ5SectorMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetSectorMul",   &uQQQ5DetSectorMul);
    tree_ORRUBA->SetBranchAddress("uQQQ5DetSector",      &uQQQ5DetSector);
    tree_ORRUBA->SetBranchAddress("uQQQ5Sector",         &uQQQ5Sector);
    tree_ORRUBA->SetBranchAddress("uQQQ5SectorChannel",  &uQQQ5SectorChannel);
    tree_ORRUBA->SetBranchAddress("uQQQ5SectorADC",      &uQQQ5SectorADC);
    // ----------------------------------------------------------------------------------------

    // BB10 Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("BB10Mul",                &BB10Mul);
    tree_ORRUBA->SetBranchAddress("BB10DetMul",             &BB10DetMul);
    tree_ORRUBA->SetBranchAddress("BB10Det",                &BB10Det);
    tree_ORRUBA->SetBranchAddress("BB10Strip",              &BB10Strip);
    tree_ORRUBA->SetBranchAddress("BB10Channel",            &BB10Channel);
    tree_ORRUBA->SetBranchAddress("BB10ADC",                &BB10ADC);
    // ----------------------------------------------------------------------------------------

    // Super X3 Downstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("dSX3LeftMul",            &dSX3LeftMul);
    tree_ORRUBA->SetBranchAddress("dSX3RightMul",           &dSX3RightMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetLeftMul",         &dSX3DetLeftMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetRightMul",        &dSX3DetRightMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetLeft",            &dSX3DetLeft);
    tree_ORRUBA->SetBranchAddress("dSX3DetRight",           &dSX3DetRight);
    tree_ORRUBA->SetBranchAddress("dSX3LeftStrip",          &dSX3LeftStrip);
    tree_ORRUBA->SetBranchAddress("dSX3RightStrip",         &dSX3RightStrip);
    tree_ORRUBA->SetBranchAddress("dSX3LeftChannel",        &dSX3LeftChannel);
    tree_ORRUBA->SetBranchAddress("dSX3RightChannel",       &dSX3RightChannel);
    tree_ORRUBA->SetBranchAddress("dSX3LeftADC",            &dSX3LeftADC);
    tree_ORRUBA->SetBranchAddress("dSX3RightADC",           &dSX3RightADC);

    tree_ORRUBA->SetBranchAddress("dSX3BackMul",            &dSX3BackMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetBackMul",         &dSX3DetBackMul);
    tree_ORRUBA->SetBranchAddress("dSX3DetBack",            &dSX3DetBack);
    tree_ORRUBA->SetBranchAddress("dSX3BackSector",         &dSX3BackSector);
    tree_ORRUBA->SetBranchAddress("dSX3BackChannel",        &dSX3BackChannel);
    tree_ORRUBA->SetBranchAddress("dSX3BackADC",            &dSX3BackADC);
    // ----------------------------------------------------------------------------------------

    // Super X3 Upstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_ORRUBA->SetBranchAddress("uSX3LeftMul",            &uSX3LeftMul);
	tree_ORRUBA->SetBranchAddress("uSX3RightMul",           &uSX3RightMul);
	tree_ORRUBA->SetBranchAddress("uSX3DetLeftMul",         &uSX3DetLeftMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetRightMul",        &uSX3DetRightMul);
	tree_ORRUBA->SetBranchAddress("uSX3DetLeft",            &uSX3DetLeft);
	tree_ORRUBA->SetBranchAddress("uSX3DetRight",           &uSX3DetRight);
    tree_ORRUBA->SetBranchAddress("uSX3LeftStrip",          &uSX3LeftStrip);
    tree_ORRUBA->SetBranchAddress("uSX3RightStrip",         &uSX3RightStrip);
    tree_ORRUBA->SetBranchAddress("uSX3LeftChannel",        &uSX3LeftChannel);
    tree_ORRUBA->SetBranchAddress("uSX3RightChannel",       &uSX3RightChannel);
    tree_ORRUBA->SetBranchAddress("uSX3LeftADC",            &uSX3LeftADC);
    tree_ORRUBA->SetBranchAddress("uSX3RightADC",           &uSX3RightADC);

    tree_ORRUBA->SetBranchAddress("uSX3BackMul",            &uSX3BackMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetBackMul",         &uSX3DetBackMul);
    tree_ORRUBA->SetBranchAddress("uSX3DetBack",            &uSX3DetBack);
    tree_ORRUBA->SetBranchAddress("uSX3BackSector",         &uSX3BackSector);
    tree_ORRUBA->SetBranchAddress("uSX3BackChannel",        &uSX3BackChannel);
    tree_ORRUBA->SetBranchAddress("uSX3BackADC",            &uSX3BackADC);
    // ----------------------------------------------------------------------------------------

    // Timing
    // ----------------------------------------------------------------------------------------

    tree_ORRUBA->SetBranchAddress("tdcSilicon",             &TDCSilicon);
    tree_ORRUBA->SetBranchAddress("tdcSiliconDivTrig",      &TDCSiliconDivTrig);
    tree_ORRUBA->SetBranchAddress("tdcSiliconGRETINATrig",  &TDCSiliconGRETINATrig);
    tree_ORRUBA->SetBranchAddress("tdcRF",                  &TDCRF);
    tree_ORRUBA->SetBranchAddress("tdcGRETINA",             &TDCGRETINA);
    tree_ORRUBA->SetBranchAddress("tdcSiliconAlt",          &TDCSiliconAlt);
    tree_ORRUBA->SetBranchAddress("tdcSiliconUpstream",     &TDCSiliconUpstream);

    tree_ORRUBA->SetBranchAddress("timeStamp", &TimeStamp);
    // ----------------------------------------------------------------------------------------

    // Set ORRUBA branches in Combined tree
    int fRunNumber;

    tree_Combined->Branch("RunNumber", &fRunNumber, "RunNumber/I");

    // QQQ5 dE Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dQQQ5RingMul_dE",        &fdQQQ5RingMul_dE,      "dQQQ5RingMul_dE/I");
    tree_Combined->Branch("dQQQ5DetRingMul_dE",     &fdQQQ5DetRingMul_dE,       "dQQQ5DetRingMul_dE[2]/I");
    tree_Combined->Branch("dQQQ5DetRing_dE",        &fdQQQ5DetRing_dE,      "dQQQ5DetRing_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5Ring_dE",           &fdQQQ5Ring_dE,         "dQQQ5Ring_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5RingChannel_dE",    &fdQQQ5RingChannel_dE,      "dQQQ5RingChannel_dE[dQQQ5RingMul_dE]/I");
    tree_Combined->Branch("dQQQ5RingADC_dE",        &fdQQQ5RingADC_dE,          "dQQQ5RingADC_dE[dQQQ5RingMul_dE]/I");

    tree_Combined->Branch("dQQQ5SectorMul_dE",      &fdQQQ5SectorMul_dE,        "dQQQ5SectorMul_dE/I");
    tree_Combined->Branch("dQQQ5DetSectorMul_dE",   &fdQQQ5DetSectorMul_dE,     "dQQQ5DetSectorMul_dE[2]/I");
    tree_Combined->Branch("dQQQ5DetSector_dE",      &fdQQQ5DetSector_dE,        "dQQQ5DetSector_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5Sector_dE",         &fdQQQ5Sector_dE,           "dQQQ5Sector_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5SectorChannel_dE",  &fdQQQ5SectorChannel_dE,        "dQQQ5SectorChannel_dE[dQQQ5SectorMul_dE]/I");
    tree_Combined->Branch("dQQQ5SectorADC_dE",      &fdQQQ5SectorADC_dE,        "dQQQ5SectorADC_dE[dQQQ5SectorMul_dE]/I");
    // ----------------------------------------------------------------------------------------

    // QQQ5 E Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dQQQ5RingMul_E",        &fdQQQ5RingMul_E,      "dQQQ5RingMul_E/I");
    tree_Combined->Branch("dQQQ5DetRingMul_E",     &fdQQQ5DetRingMul_E,       "dQQQ5DetRingMul_E[2]/I");
    tree_Combined->Branch("dQQQ5DetRing_E",        &fdQQQ5DetRing_E,      "dQQQ5DetRing_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5Ring_E",           &fdQQQ5Ring_E,         "dQQQ5Ring_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5RingChannel_E",    &fdQQQ5RingChannel_E,      "dQQQ5RingChannel_E[dQQQ5RingMul_E]/I");
    tree_Combined->Branch("dQQQ5RingADC_E",        &fdQQQ5RingADC_E,          "dQQQ5RingADC_E[dQQQ5RingMul_E]/I");

    tree_Combined->Branch("dQQQ5SectorMul_E",      &fdQQQ5SectorMul_E,        "dQQQ5SectorMul_E/I");
    tree_Combined->Branch("dQQQ5DetSectorMul_E",   &fdQQQ5DetSectorMul_E,     "dQQQ5DetSectorMul_E[2]/I");
    tree_Combined->Branch("dQQQ5DetSector_E",      &fdQQQ5DetSector_E,        "dQQQ5DetSector_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5Sector_E",         &fdQQQ5Sector_E,           "dQQQ5Sector_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5SectorChannel_E",  &fdQQQ5SectorChannel_E,        "dQQQ5SectorChannel_E[dQQQ5SectorMul_E]/I");
    tree_Combined->Branch("dQQQ5SectorADC_E",      &fdQQQ5SectorADC_E,        "dQQQ5SectorADC_E[dQQQ5SectorMul_E]/I");
    // ----------------------------------------------------------------------------------------

    // Upstream QQQ5 Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("uQQQ5RingMul",        &fuQQQ5RingMul,      "uQQQ5RingMul/I");
    tree_Combined->Branch("uQQQ5DetRingMul",     &fuQQQ5DetRingMul,       "uQQQ5DetRingMul[2]/I");
    tree_Combined->Branch("uQQQ5DetRing",        &fuQQQ5DetRing,      "uQQQ5DetRing[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5Ring",           &fuQQQ5Ring,         "uQQQ5Ring[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5RingChannel",    &fuQQQ5RingChannel,      "uQQQ5RingChannel[uQQQ5RingMul]/I");
    tree_Combined->Branch("uQQQ5RingADC",        &fuQQQ5RingADC,          "uQQQ5RingADC[uQQQ5RingMul]/I");

    tree_Combined->Branch("uQQQ5SectorMul",      &fuQQQ5SectorMul,        "uQQQ5SectorMul/I");
    tree_Combined->Branch("uQQQ5DetSectorMul",   &fuQQQ5DetSectorMul,     "uQQQ5DetSectorMul[2]/I");
    tree_Combined->Branch("uQQQ5DetSector",      &fuQQQ5DetSector,        "uQQQ5DetSector[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5Sector",         &fuQQQ5Sector,           "uQQQ5Sector[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5SectorChannel",  &fuQQQ5SectorChannel,        "uQQQ5SectorChannel[uQQQ5SectorMul]/I");
    tree_Combined->Branch("uQQQ5SectorADC",      &fuQQQ5SectorADC,        "uQQQ5SectorADC[uQQQ5SectorMul]/I");
    // ----------------------------------------------------------------------------------------

    // BB10 Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("BB10Mul",                &fBB10Mul,          "BB10Mul/I");
    tree_Combined->Branch("BB10DetMul",             &fBB10DetMul,       "BB10DetMul[12]/I");
    tree_Combined->Branch("BB10Det",                &fBB10Det,          "BB10Det[BB10Mul]/I");
    tree_Combined->Branch("BB10Strip",              &fBB10Strip,        "BB10Strip[BB10Mul]/I");
    tree_Combined->Branch("BB10Channel",            &fBB10Channel,      "BB10Channel[BB10Mul]/I");
    tree_Combined->Branch("BB10ADC",                &fBB10ADC,          "BB10ADC[BB10Mul]/I");
    // ----------------------------------------------------------------------------------------

    // Super X3 Downstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("dSX3LeftMul",            &fdSX3LeftMul,      "dSX3LeftMul/I");
    tree_Combined->Branch("dSX3RightMul",           &fdSX3RightMul,     "dSX3RightMul/I");
    tree_Combined->Branch("dSX3DetLeftMul",         &fdSX3DetLeftMul,       "dSX3DetLeftMul[12]/I");
    tree_Combined->Branch("dSX3DetRightMul",        &fdSX3DetRightMul,      "dSX3DetRightMul[12]/I");
    tree_Combined->Branch("dSX3DetLeft",            &fdSX3DetLeft,      "dSX3DetLeft[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3DetRight",           &fdSX3DetRight,     "dSX3DetRight[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftStrip",          &fdSX3LeftStrip,        "dSX3LeftStrip[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightStrip",         &fdSX3RightStrip,       "dSX3RightStrip[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftChannel",        &fdSX3LeftChannel,      "dSX3LeftChannel[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightChannel",       &fdSX3RightChannel,     "dSX3RightChannel[dSX3RightMul]/I");
    tree_Combined->Branch("dSX3LeftADC",            &fdSX3LeftADC,      "dSX3LeftADC[dSX3LeftMul]/I");
    tree_Combined->Branch("dSX3RightADC",           &fdSX3RightADC,     "dSX3RightADC[dSX3RightMul]/I");

    tree_Combined->Branch("dSX3BackMul",            &fdSX3BackMul,          "dSX3BackMul/I");
    tree_Combined->Branch("dSX3DetBackMul",         &fdSX3DetBackMul,           "dSX3DetBackMul[12]/I");
    tree_Combined->Branch("dSX3DetBack",            &fdSX3DetBack,          "dSX3DetBack[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackSector",         &fdSX3BackSector,       "dSX3BackSector[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackChannel",        &fdSX3BackChannel,      "dSX3BackChannel[dSX3BackMul]/I");
    tree_Combined->Branch("dSX3BackADC",            &fdSX3BackADC,      "dSX3BackADC[dSX3BackMul]/I");
    // ----------------------------------------------------------------------------------------

    // Super X3 Upstream Detectors
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("uSX3LeftMul",            &fuSX3LeftMul,      "uSX3LeftMul/I");
    tree_Combined->Branch("uSX3RightMul",           &fuSX3RightMul,     "uSX3RightMul/I");
    tree_Combined->Branch("uSX3DetLeftMul",         &fuSX3DetLeftMul,       "uSX3DetLeftMul[12]/I");
    tree_Combined->Branch("uSX3DetRightMul",        &fuSX3DetRightMul,      "uSX3DetRightMul[12]/I");
    tree_Combined->Branch("uSX3DetLeft",            &fuSX3DetLeft,      "uSX3DetLeft[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3DetRight",           &fuSX3DetRight,     "uSX3DetRight[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftStrip",          &fuSX3LeftStrip,        "uSX3LeftStrip[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightStrip",         &fuSX3RightStrip,       "uSX3RightStrip[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftChannel",        &fuSX3LeftChannel,      "uSX3LeftChannel[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightChannel",       &fuSX3RightChannel,     "uSX3RightChannel[uSX3RightMul]/I");
    tree_Combined->Branch("uSX3LeftADC",            &fuSX3LeftADC,      "uSX3LeftADC[uSX3LeftMul]/I");
    tree_Combined->Branch("uSX3RightADC",           &fuSX3RightADC,     "uSX3RightADC[uSX3RightMul]/I");

    tree_Combined->Branch("uSX3BackMul",            &fuSX3BackMul,          "uSX3BackMul/I");
    tree_Combined->Branch("uSX3DetBackMul",         &fuSX3DetBackMul,           "uSX3DetBackMul[12]/I");
    tree_Combined->Branch("uSX3DetBack",            &fuSX3DetBack,          "uSX3DetBack[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackSector",         &fuSX3BackSector,       "uSX3BackSector[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackChannel",        &fuSX3BackChannel,      "uSX3BackChannel[uSX3BackMul]/I");
    tree_Combined->Branch("uSX3BackADC",            &fuSX3BackADC,      "uSX3BackADC[uSX3BackMul]/I");

    // ----------------------------------------------------------------------------------------

    // Timing
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("tdcSilicon",             &fTDCSilicon);
    tree_Combined->Branch("tdcSiliconDivTrig",      &fTDCSiliconDivTrig);
    tree_Combined->Branch("tdcSiliconGRETINATrig",  &fTDCSiliconGRETINATrig);
    tree_Combined->Branch("tdcRF",                  &fTDCRF);
    tree_Combined->Branch("tdcGRETINA",             &fTDCGRETINA);
    tree_Combined->Branch("tdcSiliconAlt",          &fTDCSiliconAlt);
    tree_Combined->Branch("tdcSiliconUpstream",     &fTDCSiliconUpstream);

    tree_Combined->Branch("timeStamp",              &fTimeStamp);
    tree_Combined->Branch("GRETINATimeStamp",       &fGRETINATimeStamp);
    // ----------------------------------------------------------------------------------------


    // Set GRETINA branches in Combined tree
    tree_Combined->Branch("foundGRETINA", &foundGRETINA);

    // Mode 2
    // ----------------------------------------------------------------------------------------
    tree_Combined->Branch("xtalsMul", &xtalsMul, "xtalsMul/I");
    tree_Combined->Branch("xtals_xlab", &xtals_xlab, "xtals_xlab[xtalsMul]/F");
    tree_Combined->Branch("xtals_ylab", &xtals_ylab, "xtals_ylab[xtalsMul]/F");
    tree_Combined->Branch("xtals_zlab", &xtals_zlab, "xtals_zlab[xtalsMul]/F");
    tree_Combined->Branch("xtals_cc", &xtals_cc, "xtals_cc[xtalsMul]/F");
    tree_Combined->Branch("xtals_edop", &xtals_edop, "xtals_edop[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopMaxInt", &xtals_edopMaxInt, "xtals_edopMaxInt[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopSeg", &xtals_edopSeg, "xtals_edopSeg[xtalsMul]/F");
    tree_Combined->Branch("xtals_edopXtal", &xtals_edopXtal, "xtals_edopXtal[xtalsMul]/F");
    tree_Combined->Branch("xtals_crystalNum", &xtals_crystalNum, "xtals_crystalNum[xtalsMul]/I");
    tree_Combined->Branch("xtals_quadNum", &xtals_quadNum, "xtals_quadNum[xtalsMul]/I");
    tree_Combined->Branch("xtals_t0", &xtals_t0, "xtals_t0[xtalsMul]/F");
    tree_Combined->Branch("xtals_timestamp", &xtals_timestamp, "xtals_timestamp[xtalsMul]/L");
    // ----------------------------------------------------------------------------------------

    // Mode 1 if selected
    // ----------------------------------------------------------------------------------------
    if (run.withTracked) {
        tree_Combined->Branch("gammasMul", &gammasMul, "gammasMul/I");
        tree_Combined->Branch("gammas_cc", &gammas_cc, "gammas_cc[gammasMul]/F");
        tree_Combined->Branch("gammas_xlab", &gammas_xlab,  "gammas_xlab[gammasMul]/F");
        tree_Combined->Branch("gammas_ylab", &gammas_ylab,  "gammas_ylab[gammasMul]/F");
        tree_Combined->Branch("gammas_zlab", &gammas_zlab,  "gammas_zlab[gammasMul]/F");
        tree_Combined->Branch("gammas_timestamp", &gammas_timestamp, "gammas_timestamp[gammasMul]/L");
    }
    // ----------------------------------------------------------------------------------------

    for(auto matchedEvent: matchedEvents_) {

        // Handle ORRUBA
        tree_ORRUBA->GetEntry(matchedEvent.orrubaNumber);
        fRunNumber = RunNumber;

		// First copy QQQ5 dE data to merged tree
        // ----------------------------------------------------------------------------------------
        fdQQQ5RingMul_dE = dQQQ5RingMul_dE;
        for(int i=0; i<dQQQ5RingMul_dE; i++) {

            fdQQQ5DetRing_dE[i] = dQQQ5DetRing_dE[i];
            fdQQQ5Ring_dE[i] = dQQQ5Ring_dE[i];
            fdQQQ5RingChannel_dE[i] = dQQQ5RingChannel_dE[i];
            fdQQQ5RingADC_dE[i] = dQQQ5RingADC_dE[i];
        }

        fdQQQ5SectorMul_dE = dQQQ5SectorMul_dE;
        for(int i=0; i<dQQQ5SectorMul_dE; i++) {
            fdQQQ5DetSector_dE[i] = dQQQ5DetSector_dE[i];
            fdQQQ5Sector_dE[i] = dQQQ5Sector_dE[i];
            fdQQQ5SectorChannel_dE[i] = dQQQ5SectorChannel_dE[i];
            fdQQQ5SectorADC_dE[i] = dQQQ5SectorADC_dE[i];
        }

        for(int i=0; i<2; i++) {
            fdQQQ5DetRingMul_dE[i] = dQQQ5DetRingMul_dE[i];
            fdQQQ5DetSectorMul_dE[i] = dQQQ5DetSectorMul_dE[i];
        }
        // ----------------------------------------------------------------------------------------

		// Then QQQ5 E
        // ----------------------------------------------------------------------------------------
        fdQQQ5RingMul_E = dQQQ5RingMul_E;
        //std::cout << "dQQQ5RingMul_E = " << dQQQ5RingMul_E << std::endl;
        for(int i=0; i<dQQQ5RingMul_E; i++) {

            fdQQQ5DetRing_E[i] = dQQQ5DetRing_E[i];
            fdQQQ5Ring_E[i] = dQQQ5Ring_E[i];
            fdQQQ5RingChannel_E[i] = dQQQ5RingChannel_E[i];
            fdQQQ5RingADC_E[i] = dQQQ5RingADC_E[i];
        }

        fdQQQ5SectorMul_E = dQQQ5SectorMul_E;
        for(int i=0; i<dQQQ5SectorMul_E; i++) {
            fdQQQ5DetSector_E[i] = dQQQ5DetSector_E[i];
            fdQQQ5Sector_E[i] = dQQQ5Sector_E[i];
            fdQQQ5SectorChannel_E[i] = dQQQ5SectorChannel_E[i];
            fdQQQ5SectorADC_E[i] = dQQQ5SectorADC_E[i];
        }

        for(int i=0; i<4; i++) {
            fdQQQ5DetRingMul_E[i] = dQQQ5DetRingMul_E[i];
            fdQQQ5DetSectorMul_E[i] = dQQQ5DetSectorMul_E[i];
        }
        // ----------------------------------------------------------------------------------------

		// Then Upstream QQQ5
        // ----------------------------------------------------------------------------------------
        fuQQQ5RingMul = uQQQ5RingMul;
        for(int i=0; i<uQQQ5RingMul; i++) {

            fuQQQ5DetRing[i] = uQQQ5DetRing[i];
            fuQQQ5Ring[i] = uQQQ5Ring[i];
            fuQQQ5RingChannel[i] = uQQQ5RingChannel[i];
            fuQQQ5RingADC[i] = uQQQ5RingADC[i];
        }

        fuQQQ5SectorMul = uQQQ5SectorMul;
        for(int i=0; i<uQQQ5SectorMul; i++) {
            fuQQQ5DetSector[i] = uQQQ5DetSector[i];
            fuQQQ5Sector[i] = uQQQ5Sector[i];
            fuQQQ5SectorChannel[i] = uQQQ5SectorChannel[i];
            fuQQQ5SectorADC[i] = uQQQ5SectorADC[i];
        }
        for(int i=0; i<4; i++) {
            fuQQQ5DetRingMul[i] = uQQQ5DetRingMul[i];
            fuQQQ5DetSectorMul[i] = uQQQ5DetSectorMul[i];
        }
        // ----------------------------------------------------------------------------------------

		// Now BB10
        // ----------------------------------------------------------------------------------------
        fBB10Mul = BB10Mul;
        for(int i=0; i<BB10Mul; i++) {
            fBB10Det[i] = BB10Det[i];
            fBB10Strip[i] = BB10Strip[i];
            fBB10Channel[i] = BB10Channel[i];
            fBB10ADC[i] = BB10ADC[i];
        }
        for(int i=0; i<12; i++) {
            fBB10DetMul[i] = BB10DetMul[i];
        }
        // ----------------------------------------------------------------------------------------


		// Now dSX3s
        // ----------------------------------------------------------------------------------------
        fdSX3LeftMul = dSX3LeftMul;
        for(int i=0; i<dSX3LeftMul; i++) {
            fdSX3DetLeft[i] = dSX3DetLeft[i];
            fdSX3LeftStrip[i] = dSX3LeftStrip[i];
            fdSX3LeftChannel[i] = dSX3LeftChannel[i];
            fdSX3LeftADC[i] = dSX3LeftADC[i];
        }
        fdSX3RightMul = dSX3RightMul;
        for(int i=0; i<dSX3RightMul; i++) {
            fdSX3DetRight[i] = dSX3DetRight[i];
            fdSX3RightStrip[i] = dSX3RightStrip[i];
            fdSX3RightChannel[i] = dSX3RightChannel[i];
            fdSX3RightADC[i] = dSX3RightADC[i];
        }
        fdSX3BackMul = dSX3BackMul;
        for(int i=0; i<dSX3BackMul; i++) {
            fdSX3DetBack[i] = dSX3DetBack[i];
            fdSX3BackSector[i] = dSX3BackSector[i];
            fdSX3BackChannel[i] = dSX3BackChannel[i];
            fdSX3BackADC[i] = dSX3BackADC[i];
        }
        for(int i=0; i<12; i++) {
            fdSX3DetLeftMul[i] = dSX3DetLeftMul[i];
            fdSX3DetRightMul[i] = dSX3DetRightMul[i];
            fdSX3DetBackMul[i] = dSX3DetBackMul[i];
        }
        // ----------------------------------------------------------------------------------------

		// Finally uSX3s
        // ----------------------------------------------------------------------------------------
        fuSX3LeftMul = uSX3LeftMul;
        for(int i=0; i<uSX3LeftMul; i++) {
            fuSX3DetLeft[i] = uSX3DetLeft[i];
            fuSX3LeftStrip[i] = uSX3LeftStrip[i];
            fuSX3LeftChannel[i] = uSX3LeftChannel[i];
            fuSX3LeftADC[i] = uSX3LeftADC[i];
        }
        fuSX3RightMul = uSX3RightMul;
        for(int i=0; i<uSX3RightMul; i++) {
            fuSX3DetRight[i] = uSX3DetRight[i];
            fuSX3RightStrip[i] = uSX3RightStrip[i];
            fuSX3RightChannel[i] = uSX3RightChannel[i];
            fuSX3RightADC[i] = uSX3RightADC[i];
        }
        fuSX3BackMul = uSX3BackMul;
        for(int i=0; i<uSX3BackMul; i++) {
            fuSX3DetBack[i] = uSX3DetBack[i];
            fuSX3BackSector[i] = uSX3BackSector[i];
            fuSX3BackChannel[i] = uSX3BackChannel[i];
            fuSX3BackADC[i] = uSX3BackADC[i];
        }
        for(int i=0; i<12; i++) {
            fuSX3DetLeftMul[i] = uSX3DetLeftMul[i];
            fuSX3DetRightMul[i] = uSX3DetRightMul[i];
            fuSX3DetBackMul[i] = uSX3DetBackMul[i];
        }
        // ----------------------------------------------------------------------------------------

        fTDCSilicon = TDCSilicon;
        fTDCSiliconDivTrig = TDCSiliconDivTrig;
        fTDCSiliconGRETINATrig = TDCSiliconGRETINATrig;
        fTDCRF = TDCRF;
        fTDCGRETINA = TDCGRETINA;
        fTDCSiliconAlt = TDCSiliconAlt;
        fTDCSiliconUpstream = TDCSiliconUpstream;

        fTimeStamp = TimeStamp;
		fGRETINATimeStamp = matchedEvent.gretinaTimeStamp;

        // Handle GRETINA
        xtalsMul = 0;
        gammasMul = 0;

        if(matchedEvent.gretinaTimeStamp > 1) {
            foundGRETINA = true;
            tree_GRETINA->GetEntry(matchedEvent.gretinaNumber);
            for(auto g2Event: g2->xtals) {
                xtals_xlab[xtalsMul] = g2Event.maxIntPtXYZLab().X();
                xtals_ylab[xtalsMul] = g2Event.maxIntPtXYZLab().Y();
                xtals_zlab[xtalsMul] = g2Event.maxIntPtXYZLab().Z();
                xtals_cc[xtalsMul] = g2Event.cc;
                xtals_edop[xtalsMul] = g2Event.edop;
                xtals_edopMaxInt[xtalsMul] = g2Event.edop_maxInt;
                xtals_edopSeg[xtalsMul] = g2Event.edopSeg;
                xtals_edopXtal[xtalsMul] = g2Event.edopXtal;
                xtals_crystalNum[xtalsMul] = g2Event.crystalNum;
                xtals_quadNum[xtalsMul] = g2Event.quadNum;
                xtals_t0[xtalsMul] = g2Event.t0;
                xtals_timestamp[xtalsMul] = g2Event.timestamp;
                xtalsMul++;
            }

            if (run.withTracked) {
                for(auto g1Event: g1->gammas) {
                    gammas_cc[gammasMul] = g1Event.cc;
                    gammas_xlab[gammasMul] = g1Event.xyzLab1.X();
                    gammas_ylab[gammasMul] = g1Event.xyzLab1.Y();
                    gammas_zlab[gammasMul] = g1Event.xyzLab1.Z();
                    gammas_timestamp[gammasMul] = g1Event.timestamp;
                    gammasMul++;
                }
            }

        }
        else {
            foundGRETINA = false;
        }

        tree_Combined->Fill();
        if(matchedEvent.orrubaNumber % 10000==0) std::cout << "Progress :" << static_cast<int>(matchedEvent.orrubaNumber*100.0/nentriesORRUBA) << " %\r\a";
    }
    std::cout << std::endl;
    tree_Combined->Write();
    f_Combined->Close();

    f_ORRUBA->Close();
    f_GRETINA->Close();

    std::cout << PrintOutput("\t\tFinished combining ORRUBA and GRETINA Trees based on time stamps", "blue") << std::endl;
    std::cout << PrintOutput("\t\tCombined TTree 'data' written to file: ", "blue") << run.combinedPath << std::endl;


    std::ofstream statFile("../LogFiles/unpack.log",std::ofstream::app);
    statFile << "Run Number " << fRunNumber << std::endl;
    statFile << "EB_DIFF_TIME:" << '\t' << '\t' << EB_DIFF_TIME << std::endl;
    statFile << "timeThreshold:" << '\t' << '\t' << timeThreshold << std::endl;
    statFile << "timeFoundBreak" << '\t' << '\t' << timeFoundBreak << std::endl;
    statFile << "timeNotFoundBreak" << '\t' << '\t' << timeFoundBreak << std::endl;
    statFile << "ORRUBA Entries" << '\t' << '\t' << nentriesORRUBA << std::endl;
    statFile << "GRETINA Entries" << '\t' << '\t' << nentriesGRETINA << std::endl;
    statFile << "Matched Entries" << '\t' << '\t' << nentriesMatched << std::endl;
    statFile << "Time to match" << (duration.count()/1000000.0) << std::endl;
    statFile << std::endl;
    statFile.close();

}
