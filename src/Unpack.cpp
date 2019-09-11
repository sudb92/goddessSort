#include "Unpack.h"

#define BUFFER_LENGTH 8194
#define BUFFER_LENGTHB 32776

#define MAXCHANNEL 1024
#define MAXVALUE 4096

//std::vector<std::string> RunList = {
//												   /*  "0023","0024","0025","0026","0027","0028","0029",
//								"0030","0031","0032","0033","0034","0035","0036","0037","0038","0039",
//								"0040","0041","0042","0043","0044","0045","0046","0047","0048","0049",
//								"0050","0051","0052","0053","0054","0055","0056","0057","0058","0059",
//								"0060","0061","0062","0063","0064","0065","0066","0067","0068","0069",
//								"0070","0071","0072",*/
//													 "0073","0074","0075","0076","0077","0078","0079",
//								"0080","0081","0082","0083","0084","0085","0086","0087","0088","0089",
//								"0090","0091","0092","0093","0094","0095","0096","0097","0098","0099",
//								"0100","0101","0102","0103","0104","0105","0106","0107","0108","0109",
//								"0110","0111","0112","0113","0114","0115","0116","0117","0118","0119",
//								"0120","0121","0122","0123","0124","0125","0126","0127","0128","0129",
//								"0130","0131","0132","0133","0134","0135","0136","0137","0138","0139",
//								"0140","0141","0142","0143","0144","0145","0146","0147","0148","0149",
//								"0150","0151","0152","0153","0154","0155","0156","0157","0158","0159",
//								"0160","0161","0162","0163","0164","0165","0166","0167","0168","0169",
//								"0170","0171","0172","0173","0174","0175","0176","0177","0178","0179",
//								"0180","0181","0182","0183","0184","0185","0186","0187","0188","0189",
//								"0190","0191","0192","0193","0194","0195","0196","0197","0198","0199",
//								"0200","0201","0202","0203","0204","0205","0206","0207","0208","0209",
//								"0210","0211","0212","0213","0214","0215","0216","0217","0218","0219",
//								"0220","0221","0222","0223","0224","0225","0226","0227","0228","0229",
//								"0230","0231","0232","0233","0234","0235","0236","0237","02389","0239",
//								"0240","0241","0242","0243","0244","0245","0246","0247","0248","0249",
//								"0250","0251","0252","0253","0254","0255","0256","0257","0258","0259",
//								"0260","0261","0262","0263","0264","0265","0266","0267","0268","0269",
//								"0270","0271","0272","0273","0274","0275","0276","0277","0278","0279",
//								"0280","0281","0282","0283","0284","0285","0286","0287","0288","0289",
//								"0290","0291","0292","0293","0294","0295","0296","0297","0298","0299",
//								"0300","0301","0302","0303","0304","0205","0306","0307","0308","0309",
//								"0310","0311","0312","0313","0314","0315","0326","0317","0318","0319",
//								"0320","0321","0322","0323","0324","0325","0326","0327","0328","0329",
//								"0330","0331","0332","0333","0334","0335","0336","0337","0338","0339",
//								"0340","0341","0342","0343","0344","0345","0346","0347","0348","0349",
//								"0350","0351","0352","0353","0354","0355","0356","0357","0358","0359",
//								"0360","0361","0362","0363","0364","0365","0366","0367","0368","0369",
//								"0370","0371","0372","0373","0374","0375","0376","0377","0378","0379",
//								"0380","0381","0382","0383","0384","0385","0386","0387","0388","0389",
//								"0390","0391","0392","0393","0394","0395","0396","0397","0398","0399",
//								"0400","0401","0402","0403","0404","0405","0406","0407","0408","0409",
//								"0410","0411","0412","0413","0414","0415","0416","0417","0418","0419",
//								"0420","0421","0422","0423","0424","0425","0426","0427","0428","0429",
//								"0430","0431","0432","0433","0434","0435","0436","0437","0438","0439"
//
//							   };

int RunClock;

//Set thresholds in channel number
int SX3backThreshold = 500;
int QQQThreshold = 400;
int BB10Threshold = 500;

// Timestamps
// 1001
// 1002
// 1003

int main(int argc, char *argv[]) {
    auto* unpacker = new Unpack();

    return 0;
}

Unpack::Unpack() {
    int StartClock = clock();
    std::cout << PrintOutput("Running GODDESS sort", "yellow") << std::endl;

    std::string DataFileName, RootFileName;

    std::cout << PrintOutput("Reading RunList", "green") << std::endl;

    auto* runList = new RunList();
    auto fileList = runList->GetListOfRuns();

    std::cout << PrintOutput("Number of files to be sort = ", "yellow") << fileList.size() << std::endl;

    Calibrations* calibrations = Calibrations::Instance();

    std::cout << PrintOutput("Begin data processing loop", "yellow") << std::endl;

    // Loop through all files in the run list
    int numRuns = 0;
    for(auto run: fileList) {
        // Open the file. Check whether file opened successfully
        std::ifstream file(run.ldfPath.c_str(), std::ios::binary);
        ASSERT_WITH_MESSAGE(file.is_open(), Form("File not found: %s", run.ldfPath.c_str()));

        //Create and Open Root file to store data in. Check for success.
        TFile *outputFile = new TFile(run.rootPath.c_str(), "RECREATE");
        ASSERT_WITH_MESSAGE(outputFile->IsOpen(), Form("Root output file did not open: %s", run.rootPath.c_str()));

        std::cout << PrintOutput(Form("Unpacking data file [%d/%ld]", ++numRuns, fileList.size()), "green") << std::endl;
        std::cout << PrintOutput("Reading .ldf file: ", "cyan") << run.ldfPath << std::endl;

        //Setup Tree
        TTree *tree = new TTree("data", "Data Tree");
        tree->Branch("QQQ5Mul", &fQQQ5Mul, "QQQ5Mul/I");
        tree->Branch("QQQ5Upstream", &fQQQ5Upstream, "QQQ5Upstream[QQQ5Mul]/B");
        tree->Branch("QQQ5Det", &fQQQ5Det, "QQQ5Det[QQQ5Mul]/I");
        tree->Branch("QQQ5Ring", &fQQQ5Ring, "QQQ5Ring[QQQ5Mul]/I");
        tree->Branch("QQQ5RingChannel", &fQQQ5RingChannel, "QQQ5RingChannel[QQQ5Mul]/I");
        tree->Branch("QQQ5Sector", &fQQQ5Sector, "QQQ5Sector[QQQ5Mul]/I");
        tree->Branch("QQQ5SectorChannel", &fQQQ5SectorChannel, "QQQ5SectorChannel[QQQ5Mul]/I");
        tree->Branch("QQQ5RingADC", &fQQQ5RingADC, "QQQ5RingADC[QQQ5Mul]/I");
        tree->Branch("QQQ5RingEnergy", &fQQQ5RingEnergy, "QQQ5RingEnergy[QQQ5Mul]/F");
        tree->Branch("QQQ5SectorADC", &fQQQ5SectorADC, "QQQ5SectorADC[QQQ5Mul]/I");
        tree->Branch("QQQ5SectorEnergy", &fQQQ5SectorEnergy, "QQQ5SectorEnergy[QQQ5Mul]/F");
        tree->Branch("QQQ5Angle", &fQQQ5Angle, "QQQ5Angle[QQQ5Mul]/F");

        tree->Branch("icdE", &fICdE, "icdE/I");
        tree->Branch("icE", &fICE, "icE/I");
        tree->Branch("tdc", &fTDC, "tdc/I");

        //Declare some variables
        int NumberBuffer = 0;
        unsigned long int numberEvents = 0;
        int Counter = 0 ;
        unsigned int Buffer[BUFFER_LENGTH];
        unsigned int word;
        unsigned short halfWord[2];

        //Declare some ROOT structures
        TH2F *hMap = new TH2F("Map", "Map", MAXCHANNEL, 0, MAXCHANNEL, MAXVALUE, 0,MAXVALUE);
        TH1F *hEventMult = new TH1F("EventMult", "EventMult", 1024, 0, 1024);

        std::vector<int> readChannel;
        std::vector<int> readValue;

        //This is the main loop over the ldf file
        while(!file.eof()){

            //Get Buffer
            file.read((char*)Buffer, BUFFER_LENGTHB);

            //std::cout << "**** Reading Buffer : " << std::dec << NumberBuffer << " ****" << std::endl;

            if(Buffer[0] == 0x41544144) { //This buffer is physics data type
                for(int i = 0; i < BUFFER_LENGTH; i++) {

                    word = Buffer[i];
                    // Reverse the byte order. Switching between big and little endian
                    halfWord[0] = 0x0000ffff & word;
                    halfWord[1] = word >> 16;
                    word = (halfWord[0] << 16) | (halfWord[1]);

                    //Check for the end of the event
                    if (word != 0xffffffff) {

                        int channel = ExtractBits(word, 16, 12);
                        int value = ExtractBits(word, 0, 12);
                        hMap->Fill(channel, value);

                        //Add values to Read Arrays
                        readChannel.push_back(channel);
                        readValue.push_back(value);

                        Counter++;

                    } else { //End of the Event
                        std::vector<BB10Hit> BB10Hit_;
                        std::vector<QQQ5Ring> QdRing_;
                        std::vector<QQQ5Sector> QdSector_;
                        std::vector<QQQ5Ring> QuRing_;
                        std::vector<QQQ5Sector> QuSector_;
                        std::vector<SuperX3Back> SX3dBack_;
                        std::vector<SuperX3Front> SX3dFront_;
                        std::vector<SuperX3Back> SX3uBack_;
                        std::vector<SuperX3Front> SX3uFront_;

                        int tdc = 0;
                        int icdE = 0;
                        int icE = 0;

                        for(int k = 0; k < readChannel.size(); k++) {
                            int channel = readChannel[k];
                            int adc = readValue[k];

                            if(channel <= 128 && adc > QQQThreshold) { // QQQ5 upstream front (rings)
                                int detector = static_cast<int>((channel - 1)/32);
                                QQQ5Ring hit = {channel, detector, channel - 1 - detector*32, adc};
                                QuRing_.push_back(hit);
                            } else if(channel > 128 && channel <= 144 && adc > QQQThreshold) { // QQQ5 upstream back (sectors)
                                int detector = static_cast<int>((channel - 129)/4);
                                QQQ5Sector hit = {channel, detector, channel - 129 - detector*4, adc};
                                QuSector_.push_back(hit);
                            } else if(channel > 144 && channel <= 160 && adc > SX3backThreshold) { // SuperX3 Upstream Detectors 0-3 (back sides)
                                int detector = static_cast<int>((channel - 145)/4);
                                SuperX3Back hit = {channel, detector, channel - 145 - detector*4, adc};
                                SX3uBack_.push_back(hit);
                            } else if(channel > 160 && channel <= 176 && adc > SX3backThreshold) { // SuperX3 Upstream Detectors 6-9 (back sides)
                                int detector = static_cast<int>((channel - 161)/4) + 6;
                                SuperX3Back hit = {channel, detector, channel - 161 - (detector - 6)*4, adc};
                                SX3uBack_.push_back(hit);
                            } else if(channel > 176 && channel <= 184 && adc > SX3backThreshold) { // SuperX3 Upstream Detectors 4-5 (back sides)
                                int detector = static_cast<int>((channel - 177)/4) + 4;
                                SuperX3Back hit = {channel, detector, channel - 177 - (detector - 4)*4, adc};
                                SX3uBack_.push_back(hit);
                            } else if(channel > 184 && channel <= 192 && adc > SX3backThreshold) { // SuperX3 Upstream Detectors 10-11 (back sides)
                                int detector = static_cast<int>((channel - 185)/4) + 10;
                                SuperX3Back hit = {channel, detector, channel - 185 - (detector - 10)*4, adc};
                                SX3uBack_.push_back(hit);
                            } else if(channel > 192 && channel <= 288 && adc > SX3backThreshold) { // SuperX3 Upstream (front sides)
                                int detector = static_cast<int>((channel - 193)/8);
                                int strip = static_cast<int>((channel - 193 - detector*8)/2);
                                bool leftSide = channel % 2 == 0;
                                SuperX3Front hit = {channel, detector, strip, leftSide, adc};
                                SX3uFront_.push_back(hit);
                            } else if(channel > 288 && channel <= 384 && adc > SX3backThreshold) { // SuperX3 Downstream (front sides)
                                int detector = static_cast<int>((channel - 289)/8);
                                int strip = static_cast<int>((channel - 289 - detector*8)/2);
                                bool leftSide = channel % 2 == 0;
                                SuperX3Front hit = {channel, detector, strip, leftSide, adc};
                                SX3dFront_.push_back(hit);
                            } else if(channel > 384 && channel <= 404 && adc > SX3backThreshold) { // SuperX3 Downstream Detectors 0-4 (back sides)
                                int detector = static_cast<int>((channel - 385)/4);
                                SuperX3Back hit = {channel, detector, channel - 385 - detector*4, adc};
                                SX3dBack_.push_back(hit);
                            } else if(channel > 404 && channel <= 416 && adc > SX3backThreshold) { // SuperX3 Downstream Detectors 7-9 (back sides)
                                int detector = static_cast<int>((channel - 405)/4) + 7;
                                SuperX3Back hit = {channel, detector, channel - 405 - (detector - 7)*4, adc};
                                SX3dBack_.push_back(hit);
                            } else if(channel > 416 && channel <= 424 && adc > SX3backThreshold) { // SuperX3 Downstream Detectors 5-6 (back sides)
                                int detector = static_cast<int>((channel - 417)/4) + 5;
                                SuperX3Back hit = {channel, detector, channel - 405 - (detector - 5)*4, adc};
                                SX3dBack_.push_back(hit);
                            } else if(channel > 424 && channel <= 432 && adc > SX3backThreshold) { // SuperX3 Downstream Detectors 10-11 (back sides)
                                int detector = static_cast<int>((channel - 425)/4) + 10;
                                SuperX3Back hit = {channel, detector, channel - 425 - (detector - 10)*4, adc};
                                SX3dBack_.push_back(hit);
                            } else if(channel > 432 && channel <= 496 && adc > BB10Threshold) { // BB10 Downstream
                                int detector = static_cast<int>((channel - 433)/8);
                                BB10Hit hit = {channel, detector, channel - 433 - detector*8, adc};
                                BB10Hit_.push_back(hit);
                            } else if(channel > 496 && channel <= 508 && adc > QQQThreshold) { // QQQ5 downstream back (sectors)
                                int detector = static_cast<int>((channel - 497)/4);
                                QQQ5Sector hit = {channel, detector, channel - 497 - detector*4, adc};
                                QdSector_.push_back(hit);
                            } else if(channel > 512 && channel <= 608 && adc > QQQThreshold) { // QQQ5 downstream front (rings)
                                int detector = static_cast<int>((channel - 513)/32);
                                QQQ5Ring hit = {channel, detector, channel - 513 - detector*32, adc};
                                QdRing_.push_back(hit);
                            } else if(channel > 672 && channel <= 704) { // IC x

                            } else if(channel > 704 && channel <= 736) { // IC y

                            } else if(channel == 739) { //IC dE
                                 icdE = adc;
                            } else if(channel == 740) { //IC E
                                 icE = adc;
                            } else if(channel == 818) { // TDC
                                 tdc = adc;
                            }
                        }
                        ///////////////////////////
                        // End of Sub-event loop //
                        ///////////////////////////

                        readChannel.clear();
                        readValue.clear();

                        numberEvents++;

                        // BB10
                        std::vector<BB10Detector> BB10Detect_;
                        if(!BB10Hit_.empty()) BB10Detect_ = ProcessBB10(BB10Hit_);

                        // QQQ5 Downstream
                        std::vector<QQQ5Detector> QdDetect_;
                        if(!QdRing_.empty() && !QdSector_.empty()) QdDetect_ = ProcessQQQ5(QdRing_, QdSector_, false);

                        // QQQ5 Upstream
                        std::vector<QQQ5Detector> QuDetect_;
                        if(!QuRing_.empty() && !QuSector_.empty()) QuDetect_ = ProcessQQQ5(QuRing_, QuSector_, true);

                        // Super X3 Downstream
                        std::vector<SuperX3Detector> SX3dDetect_;
                        if(!SX3dBack_.empty() && !SX3dFront_.empty()) SX3dDetect_ = ProcessSX3(SX3dBack_, SX3dFront_, false);

                        // Super X3 Upstream
                        std::vector<SuperX3Detector> SX3uDetect_;
                        if(!SX3uBack_.empty() && !SX3uFront_.empty()) SX3uDetect_ = ProcessSX3(SX3uBack_, SX3uFront_, true);

                        bool BB10DetectEmpty = BB10Detect_.empty();
                        bool QQQDetectEmpty = (QuDetect_.empty() && QdDetect_.empty());
                        bool SX3DetectEmpty = (SX3dDetect_.empty() && SX3uDetect_.empty());
                        bool icEmpty = ((icE == 0) && (icdE == 0));

                        if(BB10DetectEmpty && QQQDetectEmpty && SX3DetectEmpty && icEmpty) continue;

                        // BB10 Detectors
                        fBB10Mul = 0;
                        for(auto BB10Detect: BB10Detect_) {
                            fBB10Mul++;
                        }

                        // QQQ5 Detectors
                        fQQQ5Mul = 0;
                        for(auto QDetect: QdDetect_) {
                            fQQQ5Upstream[fQQQ5Mul] = QDetect.upstream;
                            fQQQ5Det[fQQQ5Mul] = QDetect.detector;
                            fQQQ5Ring[fQQQ5Mul] = QDetect.ring;
                            fQQQ5RingChannel[fQQQ5Mul] = QDetect.ringChannel;
                            fQQQ5Sector[fQQQ5Mul] = QDetect.sector;
                            fQQQ5SectorChannel[fQQQ5Mul] = QDetect.sectorChannel;
                            fQQQ5RingADC[fQQQ5Mul] = QDetect.ringEnergyADC;
                            fQQQ5RingEnergy[fQQQ5Mul] = QDetect.ringEnergy;
                            fQQQ5SectorADC[fQQQ5Mul] = QDetect.sectorEnergyADC;
                            fQQQ5SectorEnergy[fQQQ5Mul] = QDetect.sectorEnergy;
                            fQQQ5Angle[fQQQ5Mul] = QDetect.angle;
                            fQQQ5Mul++;
                        }
                        for(auto QDetect: QuDetect_) {
                            fQQQ5Upstream[fQQQ5Mul] = QDetect.upstream;
                            fQQQ5Det[fQQQ5Mul] = QDetect.detector;
                            fQQQ5Ring[fQQQ5Mul] = QDetect.ring;
                            fQQQ5RingChannel[fQQQ5Mul] = QDetect.ringChannel;
                            fQQQ5Sector[fQQQ5Mul] = QDetect.sector;
                            fQQQ5SectorChannel[fQQQ5Mul] = QDetect.sectorChannel;
                            fQQQ5RingADC[fQQQ5Mul] = QDetect.ringEnergyADC;
                            fQQQ5RingEnergy[fQQQ5Mul] = QDetect.ringEnergy;
                            fQQQ5SectorADC[fQQQ5Mul] = QDetect.sectorEnergyADC;
                            fQQQ5SectorEnergy[fQQQ5Mul] = QDetect.sectorEnergy;
                            fQQQ5Angle[fQQQ5Mul] = QDetect.angle;
                            fQQQ5Mul++;
                        }

                        // Super X3 Detectors
                        fSX3Mul = 0;
                        for(auto SX3Detect: SX3dDetect_) {
                            fSX3Upstream[fSX3Mul] = SX3Detect.upstream;
                            fSX3Det[fSX3Mul] = SX3Detect.detector;
                            fSX3Sector[fSX3Mul] = SX3Detect.sector;
                            fSX3SectorChannel[fSX3Mul] = SX3Detect.sectorChannel;
                            fSX3SectorADC[fSX3Mul] = SX3Detect.sectorADC;
                            fSX3SectorEnergy[fSX3Mul] = SX3Detect.sectorEnergy;
                            fSX3Strip[fSX3Mul] = SX3Detect.strip;
                            fSX3StripLeftChannel[fSX3Mul] = SX3Detect.stripLeftChannel;
                            fSX3StripRightChannel[fSX3Mul] = SX3Detect.stripRightChannel;
                            fSX3StripLeftADC[fSX3Mul] = SX3Detect.stripLeftADC;
                            fSX3StripRightADC[fSX3Mul] = SX3Detect.stripRightADC;
                            fSX3StripEnergy[fSX3Mul] = SX3Detect.stripEnergy;
                            fSX3Mul++;
                        }
                        for(auto SX3Detect: SX3uDetect_) {
                            fSX3Upstream[fSX3Mul] = SX3Detect.upstream;
                            fSX3Det[fSX3Mul] = SX3Detect.detector;
                            fSX3Sector[fSX3Mul] = SX3Detect.sector;
                            fSX3SectorChannel[fSX3Mul] = SX3Detect.sectorChannel;
                            fSX3SectorADC[fSX3Mul] = SX3Detect.sectorADC;
                            fSX3SectorEnergy[fSX3Mul] = SX3Detect.sectorEnergy;
                            fSX3Strip[fSX3Mul] = SX3Detect.strip;
                            fSX3StripLeftChannel[fSX3Mul] = SX3Detect.stripLeftChannel;
                            fSX3StripRightChannel[fSX3Mul] = SX3Detect.stripRightChannel;
                            fSX3StripLeftADC[fSX3Mul] = SX3Detect.stripLeftADC;
                            fSX3StripRightADC[fSX3Mul] = SX3Detect.stripRightADC;
                            fSX3StripEnergy[fSX3Mul] = SX3Detect.stripEnergy;
                            fSX3Mul++;
                        }

                        fICdE = icdE;
                        fICE = icE;
                        fTDC = tdc;

                        tree->Fill();

                        hEventMult->Fill(Counter);
                        Counter = 0;
                    }
                }
            }
            NumberBuffer++;
        } //End of main loop over file

        tree->Write();
        outputFile->Close();

        file.close();
        RunClock = clock();

        std::cout << PrintOutput("Finished Unpacking Run: ", "cyan") << run.runNumber << '\t';
        std::cout << PrintOutput("Time", "cyan") << " = " << Form("%.02f", (RunClock-StartClock)/double(CLOCKS_PER_SEC)) << " seconds" << std::flush << std::endl;
        std::cout << PrintOutput("Created ROOT file : ", "cyan") << outputFile->GetName() << std::endl;

        if(run.copyCuts) {
            std::ifstream src(run.preCutPath, std::ios::binary);
            std::ofstream dst(run.cutPath,   std::ios::binary);
            try {
                dst << src.rdbuf();
                std::cout << PrintOutput("Copied cut file from run: ", "cyan") << run.runNumber.c_str() << std::endl;
            }
            catch(int e) {
                std::cout << PrintOutput(Form("Did not copy cut from run %s", run.runNumber.c_str()), "red") << std::endl;
            }
        }
    }
    std::cout << PrintOutput("************************************************", "yellow") << std::endl;
    std::cout << PrintOutput("Finished Unpacking ", "yellow") << fileList.size() << PrintOutput(" files!", "yellow") <<  std::endl;
}
