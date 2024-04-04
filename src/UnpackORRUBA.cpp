/*
 This is the GODDESS code that unpacks and merges the raw data files from ORRUBA and GRETINA.
 The original code was written by Josh Hooker and can be found at:
 https://github.com/joshhooker/goddessSort/blob/master/src/UnpackORRUBA.cpp
 It has been altered for normal kinematics GODDESS runs by Scott Carmichael, starting 8/12/21.
 The sections of code that are related to the IC have been commented out since the IC will not be used in normal kinematic runs.
 */

#include "UnpackORRUBA.h"

#define BUFFER_LENGTH 8194
#define BUFFER_LENGTHB 32776

// SC: Adding a function to sort the structures by detector number before writing to branches, writing the smallest detector number first

bool CompareBB10Hit(const BB10Hit &BB10A, const BB10Hit &BB10B) {
	return BB10A.detector < BB10B.detector;
}

bool CompareQQQ5Ring(const QQQ5Ring &QQQ5A, const QQQ5Ring &QQQ5B) {
	return QQQ5A.detector < QQQ5B.detector;
}

bool CompareQQQ5Sector(const QQQ5Sector &QQQ5A, const QQQ5Sector &QQQ5B) {
	return QQQ5A.detector < QQQ5B.detector;
}

bool CompareSX3Front(const SuperX3Front &SX3A, const SuperX3Front &SX3B) {
	return SX3A.detector < SX3B.detector;
}

bool CompareSX3Back(const SuperX3Back &SX3A, const SuperX3Back &SX3B) {
	return SX3A.detector < SX3B.detector;
}


UnpackORRUBA::UnpackORRUBA(fileListStruct run) {
    int startClock = clock();
    std::cout << PrintOutput("\tRunning ORRUBA sort:", "yellow") << std::endl;

    std::string DataFileName, RootFileName;

    // SC: Creates new calibration instance and read in silicon detector thresholds
    Calibrations* calibrations = Calibrations::Instance();
    int BB10Threshold = calibrations->GetBB10Threshold();
    int QQQThreshold = calibrations->GetQQQThreshold();
    int SX3Threshold = calibrations->GetSX3Threshold();
    // int ICTrackingThreshold = calibrations->GetICTrackingThreshold();

    std::cout << PrintOutput("\t\tBegin data processing loop", "yellow") << std::endl;

    // Open the file. Check whether file opened successfully
    std::ifstream file(run.ldfPath.c_str(), std::ios::binary);
    ASSERT_WITH_MESSAGE(file.is_open(), Form("File not found: %s", run.ldfPath.c_str()));

    std::cout << PrintOutput("\t\tReading .ldf file: ", "cyan") << run.ldfPath << std::endl;
    signal(2,UnpackORRUBA::handle_sigint);
    received_sigint=false;
    //Create and open Root file to store raw data in. Check for success.
    TFile *outputFileRaw = new TFile(run.rootPathRaw.c_str(), "recreate");
    //outputFileRaw->SetCompressionLevel(ROOT::RCompressionSetting::ELevel::kUncompressed);

    ASSERT_WITH_MESSAGE(outputFileRaw->IsOpen(), Form("Root output file did not open: %s", run.rootPathRaw.c_str()));

    //Setup Trees
    TTree *treeRaw = new TTree("dataRaw", "Raw Data Tree");
    //treeRaw->SetAutoFlush(500'000'000LL); //Negative = autoflush at N number of bytes, Positive= autoflush after N entries
    //treeRaw->SetAutoSave(500'000'000LL); //Negative = autoflush at N number of bytes, Positive= autoflush after N entries

    // Set all branch addresses for
    // General variables
    treeRaw->Branch("RunNumber", &fRunNumber, "RunNumber/I");

    // QQQ5 dE Detectors
    // ----------------------------------------------------------------------------------------
	treeRaw->Branch("dQQQ5RingMul_dE",	 	 &fdQQQ5RingMul_dE,	 	 "dQQQ5RingMul_dE/I"); // Total number of rings hit in an event
	treeRaw->Branch("dQQQ5DetRingMul_dE",	 &fdQQQ5DetRingMul_dE,	 "dQQQ5DetRingMul_dE[2]/I"); // The number of rings hit in each detector for an event
	treeRaw->Branch("dQQQ5DetRing_dE",       &fdQQQ5DetRing_dE,       "dQQQ5DetRing_dE[dQQQ5RingMul_dE]/I"); // Detector number for each hit, sorted in order of detector number
    treeRaw->Branch("dQQQ5Ring_dE",          &fdQQQ5Ring_dE,          "dQQQ5Ring_dE[dQQQ5RingMul_dE]/I"); // Ring number for each hit
    treeRaw->Branch("dQQQ5RingChannel_dE",   &fdQQQ5RingChannel_dE,   "dQQQ5RingChannel_dE[dQQQ5RingMul_dE]/I"); // Channel number for each hit
	treeRaw->Branch("dQQQ5RingADC_dE",       &fdQQQ5RingADC_dE,       "dQQQ5RingADC_dE[dQQQ5RingMul_dE]/I"); // ADC value for each hit

	treeRaw->Branch("dQQQ5SectorMul_dE",	 &fdQQQ5SectorMul_dE,	 "dQQQ5SectorMul_dE/I");
	treeRaw->Branch("dQQQ5DetSectorMul_dE",	 &fdQQQ5DetSectorMul_dE,	 "dQQQ5DetSectorMul_dE[2]/I");
    treeRaw->Branch("dQQQ5DetSector_dE",     &fdQQQ5DetSector_dE,     "dQQQ5DetSector_dE[dQQQ5SectorMul_dE]/I");
    treeRaw->Branch("dQQQ5Sector_dE",        &fdQQQ5Sector_dE,        "dQQQ5Sector_dE[dQQQ5SectorMul_dE]/I");
    treeRaw->Branch("dQQQ5SectorChannel_dE", &fdQQQ5SectorChannel_dE, "dQQQ5SectorChannel_dE[dQQQ5SectorMul_dE]/I");
    treeRaw->Branch("dQQQ5SectorADC_dE",     &fdQQQ5SectorADC_dE,     "dQQQ5SectorADC_dE[dQQQ5SectorMul_dE]/I");
    // ----------------------------------------------------------------------------------------

    // dQQQ5 E Detectors
    // ----------------------------------------------------------------------------------------
	treeRaw->Branch("dQQQ5RingMul_E",	 	 &fdQQQ5RingMul_E,	 	 "dQQQ5RingMul_E/I");
	treeRaw->Branch("dQQQ5DetRingMul_E",	 &fdQQQ5DetRingMul_E,	 "dQQQ5DetRingMul_E[4]/I");
	treeRaw->Branch("dQQQ5DetRing_E",       &fdQQQ5DetRing_E,       "dQQQ5DetRing_E[dQQQ5RingMul_E]/I");
    treeRaw->Branch("dQQQ5Ring_E",          &fdQQQ5Ring_E,          "dQQQ5Ring_E[dQQQ5RingMul_E]/I");
    treeRaw->Branch("dQQQ5RingChannel_E",   &fdQQQ5RingChannel_E,   "dQQQ5RingChannel_E[dQQQ5RingMul_E]/I");
	treeRaw->Branch("dQQQ5RingADC_E",       &fdQQQ5RingADC_E,       "dQQQ5RingADC_E[dQQQ5RingMul_E]/I");

	treeRaw->Branch("dQQQ5SectorMul_E",	 	&fdQQQ5SectorMul_E,	 "dQQQ5SectorMul_E/I");
	treeRaw->Branch("dQQQ5DetSectorMul_E",	 &fdQQQ5DetSectorMul_E,	 "dQQQ5DetSectorMul_E[4]/I");
    treeRaw->Branch("dQQQ5DetSector_E",     &fdQQQ5DetSector_E,     "dQQQ5DetSector_E[dQQQ5SectorMul_E]/I");
    treeRaw->Branch("dQQQ5Sector_E",        &fdQQQ5Sector_E,        "dQQQ5Sector_E[dQQQ5SectorMul_E]/I");
    treeRaw->Branch("dQQQ5SectorChannel_E", &fdQQQ5SectorChannel_E, "dQQQ5SectorChannel_E[dQQQ5SectorMul_E]/I");
    treeRaw->Branch("dQQQ5SectorADC_E",     &fdQQQ5SectorADC_E,     "dQQQ5SectorADC_E[dQQQ5SectorMul_E]/I");
    // ----------------------------------------------------------------------------------------


    // QQQ5 Upstream Detectors
    // ----------------------------------------------------------------------------------------
	treeRaw->Branch("uQQQ5RingMul",	 	 &fuQQQ5RingMul,	 	 "uQQQ5RingMul/I");
	treeRaw->Branch("uQQQ5DetRingMul",	 &fuQQQ5DetRingMul,	 "uQQQ5DetRingMul[4]/I");
	treeRaw->Branch("uQQQ5DetRing",       &fuQQQ5DetRing,       "uQQQ5DetRing[uQQQ5RingMul]/I");
    treeRaw->Branch("uQQQ5Ring",          &fuQQQ5Ring,          "uQQQ5Ring[uQQQ5RingMul]/I");
    treeRaw->Branch("uQQQ5RingChannel",   &fuQQQ5RingChannel,   "uQQQ5RingChannel[uQQQ5RingMul]/I");
	treeRaw->Branch("uQQQ5RingADC",       &fuQQQ5RingADC,       "uQQQ5RingADC[uQQQ5RingMul]/I");

	treeRaw->Branch("uQQQ5SectorMul",	 	&fuQQQ5SectorMul,	 "uQQQ5SectorMul/I");
	treeRaw->Branch("uQQQ5DetSectorMul",	 &fuQQQ5DetSectorMul,	 "uQQQ5DetSectorMul[4]/I");
    treeRaw->Branch("uQQQ5DetSector",     &fuQQQ5DetSector,     "uQQQ5DetSector[uQQQ5SectorMul]/I");
    treeRaw->Branch("uQQQ5Sector",        &fuQQQ5Sector,        "uQQQ5Sector[uQQQ5SectorMul]/I");
    treeRaw->Branch("uQQQ5SectorChannel", &fuQQQ5SectorChannel, "uQQQ5SectorChannel[uQQQ5SectorMul]/I");
    treeRaw->Branch("uQQQ5SectorADC",     &fuQQQ5SectorADC,     "uQQQ5SectorADC[uQQQ5SectorMul]/I");
    // ----------------------------------------------------------------------------------------

    // BB10 Detectors
    // ----------------------------------------------------------------------------------------
    treeRaw->Branch("BB10Mul",     &fBB10Mul,     "BB10Mul/I");
    treeRaw->Branch("BB10DetMul",  &fBB10DetMul,  "BB10DetMul[8]/I");
    treeRaw->Branch("BB10Det",     &fBB10Det,     "BB10Det[BB10Mul]/I");
    treeRaw->Branch("BB10Strip",   &fBB10Strip,   "BB10Strip[BB10Mul]/I");
    treeRaw->Branch("BB10Channel", &fBB10Channel, "BB10Channel[BB10Mul]/I");
    treeRaw->Branch("BB10ADC",     &fBB10ADC,     "BB10ADC[BB10Mul]/I");
    // ----------------------------------------------------------------------------------------

    // Super X3 Downstream Detectors
    // ----------------------------------------------------------------------------------------
    treeRaw->Branch("dSX3LeftMul",             &fdSX3LeftMul,            "dSX3LeftMul/I");
    treeRaw->Branch("dSX3RightMul",            &fdSX3RightMul,            "dSX3RightMul/I");
    treeRaw->Branch("dSX3DetLeftMul",            &fdSX3DetLeftMul,        "dSX3DetLeftMul[12]/I");
    treeRaw->Branch("dSX3DetRightMul",            &fdSX3DetRightMul,        "dSX3DetRightMul[12]/I");
    treeRaw->Branch("dSX3DetLeft",                &fdSX3DetLeft,            "dSX3DetLeft[dSX3LeftMul]/I");
    treeRaw->Branch("dSX3DetRight",            &fdSX3DetRight,            "dSX3DetRight[dSX3RightMul]/I");
    treeRaw->Branch("dSX3LeftStrip",            &fdSX3LeftStrip,        "dSX3DLeftStrip[dSX3LeftMul]/I");
    treeRaw->Branch("dSX3RightStrip",            &fdSX3RightStrip,        "dSX3RightStrip[dSX3RightMul]/I");
    treeRaw->Branch("dSX3LeftChannel",            &fdSX3LeftChannel,        "dSX3LeftChannel[dSX3LeftMul]/I");
    treeRaw->Branch("dSX3RightChannel",        &fdSX3RightChannel,        "dSX3RightChannel[dSX3RightMul]/I");
    treeRaw->Branch("dSX3LeftADC",                &fdSX3LeftADC,            "dSX3LeftADC[dSX3LeftMul]/I");
    treeRaw->Branch("dSX3RightADC",            &fdSX3RightADC,            "dSX3RightADC[dSX3RightMul]/I");

    treeRaw->Branch("dSX3BackMul",             &fdSX3BackMul,          "dSX3BackMul/I");
    treeRaw->Branch("dSX3DetBackMul",              &fdSX3DetBackMul,        "dSX3DetBackMul[12]/I");
    treeRaw->Branch("dSX3DetBack",               &fdSX3DetBack,          "dSX3DetBack[dSX3BackMul]/I");
    treeRaw->Branch("dSX3BackSector",            &fdSX3BackSector,       "dSX3BackSector[dSX3BackMul]/I");
    treeRaw->Branch("dSX3BackChannel",         &fdSX3BackChannel,      "dSX3BackChannel[dSX3BackMul]/I");
    treeRaw->Branch("dSX3BackADC",             &fdSX3BackADC,             "dSX3BackADC[dSX3BackMul]/I");
    // ----------------------------------------------------------------------------------------

    // Super X3 Upstream Detectors
    // ----------------------------------------------------------------------------------------
	treeRaw->Branch("uSX3LeftMul", 			&fuSX3LeftMul,			"uSX3LeftMul/I");
    treeRaw->Branch("uSX3RightMul",			&fuSX3RightMul,			"uSX3RightMul/I");
	treeRaw->Branch("uSX3DetLeftMul",			&fuSX3DetLeftMul,		"uSX3DetLeftMul[12]/I");
	treeRaw->Branch("uSX3DetRightMul",			&fuSX3DetRightMul,		"uSX3DetRightMul[12]/I");
	treeRaw->Branch("uSX3DetLeft",				&fuSX3DetLeft,			"uSX3DetLeft[uSX3LeftMul]/I");
	treeRaw->Branch("uSX3DetRight",			&fuSX3DetRight,			"uSX3DetRight[uSX3RightMul]/I");
	treeRaw->Branch("uSX3LeftStrip",			&fuSX3LeftStrip,		"uSX3DLeftStrip[uSX3LeftMul]/I");
	treeRaw->Branch("uSX3RightStrip",			&fuSX3RightStrip,		"uSX3RightStrip[uSX3RightMul]/I");
	treeRaw->Branch("uSX3LeftChannel",			&fuSX3LeftChannel,		"uSX3LeftChannel[uSX3LeftMul]/I");
	treeRaw->Branch("uSX3RightChannel",		&fuSX3RightChannel,		"uSX3RightChannel[uSX3RightMul]/I");
	treeRaw->Branch("uSX3LeftADC",				&fuSX3LeftADC,			"uSX3LeftADC[uSX3LeftMul]/I");
	treeRaw->Branch("uSX3RightADC",			&fuSX3RightADC,			"uSX3RightADC[uSX3RightMul]/I");

    treeRaw->Branch("uSX3BackMul",             &fuSX3BackMul,          "uSX3BackMul/I");
    treeRaw->Branch("uSX3DetBackMul",		  	&fuSX3DetBackMul,		"uSX3DetBackMul[12]/I");
    treeRaw->Branch("uSX3DetBack",           	&fuSX3DetBack,          "uSX3DetBack[uSX3BackMul]/I");
    treeRaw->Branch("uSX3BackSector",        	&fuSX3BackSector,       "uSX3BackSector[uSX3BackMul]/I");
    treeRaw->Branch("uSX3BackChannel", 	    &fuSX3BackChannel,      "uSX3BackChannel[uSX3BackMul]/I");
    treeRaw->Branch("uSX3BackADC",     	    &fuSX3BackADC,         	"uSX3BackADC[uSX3BackMul]/I");
    // ----------------------------------------------------------------------------------------

    // TDCs
    // ----------------------------------------------------------------------------------------
    treeRaw->Branch("tdcSilicon", &fTDCSilicon, "tdcSilicon/I");
    treeRaw->Branch("tdcSiliconDivTrig", &fTDCSiliconDivTrig, "tdcSiliconDivTrig/I");
    treeRaw->Branch("tdcSiliconGRETINATrig", &fTDCSiliconGRETINATrig, "tdcSiliconGRETINATrig/I");
    treeRaw->Branch("tdcRF",      &fTDCRF,      "tdcRF/I");
    treeRaw->Branch("tdcGRETINA", &fTDCGRETINA, "tdcGRETINA/I");
    treeRaw->Branch("tdcSiliconAlt", &fTDCSiliconAlt, "tdcSiliconAlt/I");
    treeRaw->Branch("tdcSiliconUpstream", &fTDCSiliconUpstream, "tdcSiliconUpstream/I");
    // ----------------------------------------------------------------------------------------

    // Timestamp
    // ----------------------------------------------------------------------------------------
    treeRaw->Branch("timeStamp", &fTimeStamp);
    // ----------------------------------------------------------------------------------------

    //Declare variables to be used while parsing .ldf
    int NumberBuffer = 0;
    unsigned long int numberEvents = 0;
    unsigned int buffer[BUFFER_LENGTH];
    unsigned int word;
    unsigned short halfWord[2];

    std::vector<int> readChannel;
    std::vector<int> readValue;

    // Sectors were reversed for dSX3 5,6,11, so use this to correct
	Int_t sectorSwap[4] = {3,2,1,0};
    //This is the main loop over the ldf file
    while(!file.eof() and !received_sigint){

        //Get Buffer
        file.read((char*)buffer, BUFFER_LENGTHB);

        if(buffer[0] == 0x41544144) { //This buffer is physics data type
            bool processLDF = false;
            for(int i = 0; i < BUFFER_LENGTH; i++) {

                word = buffer[i];
                // Reverse the byte order. Switching between big and little endian
                halfWord[0] = 0x0000ffff & word;
                halfWord[1] = word >> 16;
                word = (halfWord[0] << 16) | (halfWord[1]);


                //Check for the end of the event
                if (word != 0xffffffff) {

                    int channel = ExtractBits(word, 16, 12);
                    int value = ExtractBits(word, 0, 16);

                    //Add values to Read Arrays
                    readChannel.push_back(channel);
                    readValue.push_back(value);
                    processLDF = true;

                } else { //End of the event, so start processing data

                    if (processLDF==false) continue; //is set to false at the end of this block so as to not repeat it
                    // Vectors for data from each detector type, front and back
                    std::vector<BB10Hit> BB10Hit_;
                    std::vector<QQQ5Ring> QdERing_;
                    std::vector<QQQ5Sector> QdESector_;
                    std::vector<QQQ5Ring> QERing_;
                    std::vector<QQQ5Sector> QESector_;
                    std::vector<QQQ5Ring> QuRing_;
                    std::vector<QQQ5Sector> QuSector_;
                    std::vector<SuperX3Back> SX3dBack_;
                    std::vector<SuperX3Front> SX3dFront_;
                    std::vector<SuperX3Back> SX3uBack_;
                    std::vector<SuperX3Front> SX3uFront_;

                    int tdcSilicon = 0;
                    int tdcSiliconDivTrig = 0;
                    int tdcSiliconGRETINATrig = 0;
                    int tdcRF = 0;
                    int tdcGRETINA = 0;
                    int tdcSiliconAlt = 0;
                    int tdcSiliconUpstream = 0;

                    unsigned long long timeStamp = 0;
                    for(int k = 0; k < readChannel.size(); k++)
                    {
                        int channel = readChannel[k];
                        int adc = readValue[k];

                        if(channel <= 128 && adc > QQQThreshold) { // QQQ5 upstream front (rings)
                            int detector = static_cast<int>((channel - 1)/32);
                            QQQ5Ring hit = {channel, detector, channel - 1 - detector*32, adc};
                            QuRing_.push_back(hit);
                        } else if(channel > 128 && channel <= 144 && adc > QQQThreshold ) { // QQQ5 upstream back (sectors)
                            int detector = static_cast<int>((channel - 129)/4);
                            QQQ5Sector hit = {channel, detector, channel - 129 - detector*4, adc};
                            QuSector_.push_back(hit);
                        } else if(channel > 144 && channel <= 160 && adc > SX3Threshold) { // SuperX3 Upstream Detectors 1-4 (back sides)
                            int detector = static_cast<int>((channel - 145)/4) + 1;
                            SuperX3Back hit = {channel, detector, channel - 145 - (detector - 1)*4, adc};
                            SX3uBack_.push_back(hit);
                        } else if(channel > 160 && channel <= 176 && adc > SX3Threshold) { // SuperX3 Upstream Detectors 7-10 (back sides)
                            int detector = static_cast<int>((channel - 161)/4) + 7;
                            SuperX3Back hit = {channel, detector, channel - 161 - (detector - 7)*4, adc};
                            SX3uBack_.push_back(hit);
                        } else if(channel > 176 && channel <= 184 && adc > SX3Threshold) { // SuperX3 Upstream Detectors 5-6 (back sides)
                            int detector = static_cast<int>((channel - 177)/4) + 5;
                            SuperX3Back hit = {channel, detector, 184 - channel - (6 - detector)*4, adc};
                            SX3uBack_.push_back(hit);
                        } else if(channel > 184 && channel <= 188 && adc > SX3Threshold) { // SuperX3 Upstream Detector 11 (back sides)
                            int detector = 11;
                            SuperX3Back hit = {channel, detector, 188 - channel, adc};
                            SX3uBack_.push_back(hit);
                        } else if(channel > 188 && channel <= 192 && adc > SX3Threshold) { // SuperX3 Upstream Detector 0 (back sides)
                            int detector = 0;
                            SuperX3Back hit = {channel, detector, 192 - channel, adc};
                            SX3uBack_.push_back(hit);
                        } else if(channel > 192 && channel <= 280 && adc > SX3Threshold) { // SuperX3 Upstream Detectors 1-11 (front sides)
                            int detector = static_cast<int>((channel - 193)/8) + 1;
                            int strip = static_cast<int>((channel - 193 - (detector - 1)*8)/2);
                            bool leftSide = channel % 2 == 0;
                            //SuperX3Front hit = {channel, detector, strip, leftSide, rightSide, adc};
                            SuperX3Front hit = {channel, detector, strip, leftSide, adc};
                            SX3uFront_.push_back(hit);
						} else if(channel > 280 && channel <= 288 && adc > SX3Threshold) { // SuperX3 Upstream Detector 0 (front sides)
                            int detector = 0;
                            int strip = static_cast<int>((channel - 281)/2);
                            bool leftSide = channel % 2 == 0;
                            //SuperX3Front hit = {channel, detector, strip, leftSide, rightSide, adc};
                            SuperX3Front hit = {channel, detector, strip, leftSide, adc};
                            SX3uFront_.push_back(hit);
                        } else if(channel > 288 && channel <= 376 && adc > SX3Threshold) { // SuperX3 Downstream Detectors 1-11 (front sides)
                            int detector = static_cast<int>((channel - 289)/8) + 1;
                            int strip = static_cast<int>((channel - 289 - (detector - 1)*8)/2);
                            bool leftSide = channel % 2 == 0;
                            SuperX3Front hit = {channel, detector, strip, leftSide, adc};
                            SX3dFront_.push_back(hit);
                        } else if(channel > 376 && channel <= 384 && adc > SX3Threshold) { // SuperX3 Downstream Detector 0 (front sides)
                            int detector = 0;
                            int strip = static_cast<int>((channel - 377)/2);
                            bool leftSide = channel % 2 == 0;
                            SuperX3Front hit = {channel, detector, strip, leftSide, adc};
                            SX3dFront_.push_back(hit);
                        } else if(channel > 384 && channel <= 400 && adc > SX3Threshold) { // SuperX3 Downstream Detectors 1-4 (back sides)
                            int detector = static_cast<int>((channel - 385)/4) + 1;
                            SuperX3Back hit = {channel, detector, channel - 385 - (detector - 1)*4, adc};
                            SX3dBack_.push_back(hit);
                        } else if(channel > 400 && channel <= 416 && adc > SX3Threshold) { // SuperX3 Downstream Detectors 7-10 (back sides)
                            int detector = static_cast<int>((channel - 401)/4) + 7;
                            SuperX3Back hit = {channel, detector, channel - 401 - (detector - 7)*4, adc};
                            SX3dBack_.push_back(hit);
                        } else if(channel > 416 && channel <= 424 && adc > SX3Threshold) { // SuperX3 Downstream Detectors 5-6 (back sides)
                            int detector = static_cast<int>((channel - 417)/4) + 5;
                            SuperX3Back hit = {channel, detector, sectorSwap[channel - 417 - (detector - 5)*4], adc};
                            SX3dBack_.push_back(hit);
                        } else if(channel > 424 && channel <= 428 && adc > SX3Threshold) { // SuperX3 Downstream Detector 11 (back sides)
                            int detector = 11;
                            SuperX3Back hit = {channel, detector, sectorSwap[channel - 425], adc};
                            SX3dBack_.push_back(hit);
                        } else if(channel > 428 && channel <= 432 && adc > SX3Threshold) { // SuperX3 Downstream Detector 0 (back sides)
                            int detector = 0;
                            SuperX3Back hit = {channel, detector, channel - 429, adc};
                            SX3dBack_.push_back(hit);
                        } else if(channel > 432 && channel <= 464 && adc > BB10Threshold) { // BB10 Downstream Detectors 2-5
                            int detector = static_cast<int>((channel - 433)/8) + 2;
                            BB10Hit hit = {channel, detector, channel - 433 - (detector - 2)*8, adc};
                            BB10Hit_.push_back(hit);
						} else if(channel > 464 && channel <= 496 && adc > BB10Threshold) { // BB10 Downstream Detectors 8-11
                            int detector = static_cast<int>((channel - 465)/8) + 8;
                            BB10Hit hit = {channel, detector, channel - 465 - (detector - 8)*8, adc};
                            BB10Hit_.push_back(hit);
						} else if(channel > 496 && channel <= 560 && adc > QQQThreshold) { // QQQ5 downstream dE front (rings)
							int detector = static_cast<int>((channel - 497)/32);
							QQQ5Ring hit = {channel, detector, channel - 497 - detector*32, adc};
							QdERing_.push_back(hit);
						} else if(channel > 560 && channel <= 564 && adc > QQQThreshold) { // QQQ5 downstream A dE back (sector)
							int detector = 0;
							QQQ5Sector hit = {channel, detector, channel - 561, adc};
							QdESector_.push_back(hit);
						} else if(channel > 568 && channel <= 572 && adc > QQQThreshold) { // QQQ5 downstream B dE back (sector)
							int detector = 1;
							QQQ5Sector hit = {channel, detector, channel - 569, adc};
							QdESector_.push_back(hit);
                        } else if(channel > 576 && channel <= 672 && adc > QQQThreshold) { // QQQ5 downstream E1 and E2 A front (rings)
                            int detector = static_cast<int>((channel - 577)/32);
                            QQQ5Ring hit = {channel, detector, channel - 577 - detector*32, adc};
                            QERing_.push_back(hit);
                        } else if(channel > 672 && channel <= 688 && adc > QQQThreshold) { // QQQ5 downstream E1 and E2 back (sectors).  Order seems to be E1A E2A E1B E2B which is why this section is a bit different
                            int detector = static_cast<int>((channel - 673)/4);
                            int sector = channel - 673 - detector*4;
                            // Swap 1 and 2
                            if (sector<0 || sector>3) {std::cout << channel << '\t' << sector << std::endl;}
                            if (detector==1){detector=2;}
                            else if (detector==2){detector=1;}
                            QQQ5Sector hit = {channel, detector, sector, adc};
                            QESector_.push_back(hit);

                        } else if(channel == 833) {
                            tdcSilicon = adc;
                        } else if(channel == 834) {
                            tdcSiliconDivTrig = adc;
                        } else if(channel == 835) {
                            tdcSiliconGRETINATrig = adc;
                        } else if(channel == 836) {
                            tdcRF = adc;
                        } else if(channel == 839) {
                            tdcGRETINA = adc;
                        } else if(channel == 840) {
                            tdcSiliconAlt = adc;
                        } else if(channel == 841) {
                            tdcSiliconUpstream = adc;
                        }


                        if(channel >= 1000 && channel <= 1002) {
                            timeStamp |= (unsigned long long) adc << (16*(channel - 1000));
                        }
                    }

                    ///////////////////////////
                    // End of Sub-event loop //
                    ///////////////////////////
                    processLDF=false;
                    readChannel.clear();
                    readValue.clear();
                    numberEvents++;

                    // ----------------------------------------------------------------------------------------
					// dQQQ5 dE

                    // Sort data vectors into detector order
					std::sort(QdERing_.begin(), QdERing_.end(), CompareQQQ5Ring);
					std::sort(QdESector_.begin(), QdESector_.end(), CompareQQQ5Sector);

                    // Process vectors by converting vector into an output structure
                    QQQ5DetRaw dQQQ5dERawProc;
                    dQQQ5dERawProc = ProcessQQQ5(QdERing_,QdESector_,0,1);

                    // Assign data to root branches
					fdQQQ5RingMul_dE = dQQQ5dERawProc.RingMul;
                    for(int i=0; i<fdQQQ5RingMul_dE; i++) {
                        fdQQQ5DetRing_dE[i] = dQQQ5dERawProc.DetRing[i];
                        fdQQQ5Ring_dE[i] = dQQQ5dERawProc.Ring[i];
                        fdQQQ5RingChannel_dE[i] = dQQQ5dERawProc.RingChannel[i];
                        fdQQQ5RingADC_dE[i] = dQQQ5dERawProc.RingADC[i];
                    }

                    fdQQQ5SectorMul_dE = dQQQ5dERawProc.SectorMul;
                    for(int i=0; i<fdQQQ5SectorMul_dE; i++) {
                        fdQQQ5DetSector_dE[i] = dQQQ5dERawProc.DetSector[i];
                        fdQQQ5Sector_dE[i] = dQQQ5dERawProc.Sector[i];
                        fdQQQ5SectorChannel_dE[i] = dQQQ5dERawProc.SectorChannel[i];
                        fdQQQ5SectorADC_dE[i] = dQQQ5dERawProc.SectorADC[i];
                    }

                    for(int i=0; i<2; i++) {
                        fdQQQ5DetRingMul_dE[i] = dQQQ5dERawProc.DetRingMul[i];
                        fdQQQ5DetSectorMul_dE[i] = dQQQ5dERawProc.DetSectorMul[i];
                    }

                    // Repeat above process for the rest of the detectors
                    // ----------------------------------------------------------------------------------------
					// dQQQ5 E
					std::sort(QERing_.begin(), QERing_.end(), CompareQQQ5Ring);
					std::sort(QESector_.begin(), QESector_.end(), CompareQQQ5Sector);

                    QQQ5DetRaw dQQQ5ERawProc;
                    dQQQ5ERawProc = ProcessQQQ5(QERing_,QESector_,0,0);

                    fdQQQ5RingMul_E = dQQQ5ERawProc.RingMul;
                    for(int i=0; i<fdQQQ5RingMul_E; i++) {
                        fdQQQ5DetRing_E[i] = dQQQ5ERawProc.DetRing[i];
                        fdQQQ5Ring_E[i] = dQQQ5ERawProc.Ring[i];
                        fdQQQ5RingChannel_E[i] = dQQQ5ERawProc.RingChannel[i];
                        fdQQQ5RingADC_E[i] = dQQQ5ERawProc.RingADC[i];
                    }

                    fdQQQ5SectorMul_E = dQQQ5ERawProc.SectorMul;
                    for(int i=0; i<fdQQQ5SectorMul_E; i++) {
                        fdQQQ5DetSector_E[i] = dQQQ5ERawProc.DetSector[i];
                        fdQQQ5Sector_E[i] = dQQQ5ERawProc.Sector[i];
                        fdQQQ5SectorChannel_E[i] = dQQQ5ERawProc.SectorChannel[i];
                        fdQQQ5SectorADC_E[i] = dQQQ5ERawProc.SectorADC[i];
                    }

                    for(int i=0; i<4; i++) {
                        fdQQQ5DetRingMul_E[i] = dQQQ5ERawProc.DetRingMul[i];
                        fdQQQ5DetSectorMul_E[i] = dQQQ5ERawProc.DetSectorMul[i];
                    }

                    // ----------------------------------------------------------------------------------------
					// uQQQ5
					std::sort(QuRing_.begin(), QuRing_.end(), CompareQQQ5Ring);
					std::sort(QuSector_.begin(), QuSector_.end(), CompareQQQ5Sector);

                    QQQ5DetRaw uQQQ5RawProc;
                    uQQQ5RawProc = ProcessQQQ5(QuRing_,QuSector_,1,0);
                    //std::cout << "uQRing Vector Length = " << QuRing_.size() << std::endl;

					fuQQQ5RingMul = uQQQ5RawProc.RingMul;
                    if(fuQQQ5RingMul > 32){std::cout << "uQQQ5RingMul = " << fuQQQ5RingMul << std::endl; };

                    for(int i=0; i<fuQQQ5RingMul; i++) {
                        fuQQQ5DetRing[i] = uQQQ5RawProc.DetRing[i];
                        fuQQQ5Ring[i] = uQQQ5RawProc.Ring[i];
                        fuQQQ5RingChannel[i] = uQQQ5RawProc.RingChannel[i];
                        fuQQQ5RingADC[i] = uQQQ5RawProc.RingADC[i];
                    }

                    fuQQQ5SectorMul = uQQQ5RawProc.SectorMul;
                    if(fuQQQ5SectorMul > 32){std::cout << "uQQQ5SectorMul = " << fuQQQ5SectorMul << std::endl;};
                    for(int i=0; i<fuQQQ5SectorMul; i++) {
                        fuQQQ5DetSector[i] = uQQQ5RawProc.DetSector[i];
                        fuQQQ5Sector[i] = uQQQ5RawProc.Sector[i];
                        fuQQQ5SectorChannel[i] = uQQQ5RawProc.SectorChannel[i];
                        fuQQQ5SectorADC[i] = uQQQ5RawProc.SectorADC[i];
                    }

                    for(int i=0; i<4; i++) {
                        fuQQQ5DetRingMul[i] = uQQQ5RawProc.DetRingMul[i];
                        fuQQQ5DetSectorMul[i] = uQQQ5RawProc.DetSectorMul[i];
                    }

                    // ----------------------------------------------------------------------------------------
                    // BB10
                    std::sort(BB10Hit_.begin(), BB10Hit_.end(), CompareBB10Hit);

                    BB10DetRaw BB10RawProc;
                    BB10RawProc = ProcessBB10(BB10Hit_);

                    fBB10Mul = BB10RawProc.Mul;
                    for(int i=0; i<fBB10Mul; i++) {
                        fBB10Det[i] = BB10RawProc.Det[i];
                        fBB10Strip[i] = BB10RawProc.Strip[i];
                        fBB10Channel[i] = BB10RawProc.Channel[i];
                        fBB10ADC[i] = BB10RawProc.ADC[i];
                    }
                    for(int i=0; i<12; i++) {
                        fBB10DetMul[i] = BB10RawProc.DetMul[i];
                    }

                    //________________________________________________________
                    // dSX3
                    std::sort(SX3dFront_.begin(), SX3dFront_.end(), CompareSX3Front);
                    std::sort(SX3dBack_.begin(), SX3dBack_.end(), CompareSX3Back);

                    SX3DetRaw dSX3RawProc;
                    dSX3RawProc = ProcessSX3(SX3dFront_,SX3dBack_,1);

                    fdSX3LeftMul = dSX3RawProc.LeftMul;
                    for(int i=0; i<fdSX3LeftMul; i++) {
                        fdSX3DetLeft[i] = dSX3RawProc.DetLeft[i];
                        fdSX3LeftStrip[i] = dSX3RawProc.LeftStrip[i];
                        fdSX3LeftChannel[i] = dSX3RawProc.LeftChannel[i];
                        fdSX3LeftADC[i] = dSX3RawProc.LeftADC[i];
                    }

                    fdSX3RightMul = dSX3RawProc.RightMul;
                    for(int i=0; i<fdSX3RightMul; i++) {
                        fdSX3DetRight[i] = dSX3RawProc.DetRight[i];
                        fdSX3RightStrip[i] = dSX3RawProc.RightStrip[i];
                        fdSX3RightChannel[i] = dSX3RawProc.RightChannel[i];
                        fdSX3RightADC[i] = dSX3RawProc.RightADC[i];
                    }

                    fdSX3BackMul = dSX3RawProc.BackMul;
                    for(int i=0; i<fdSX3BackMul; i++) {
                        fdSX3DetBack[i] = dSX3RawProc.DetBack[i];
                        fdSX3BackSector[i] = dSX3RawProc.BackSector[i];
                        fdSX3BackChannel[i] = dSX3RawProc.BackChannel[i];
                        fdSX3BackADC[i] = dSX3RawProc.BackADC[i];
                    }

                    for(int i=0; i<12; i++) {
                        fdSX3DetLeftMul[i] = dSX3RawProc.DetLeftMul[i];
                        fdSX3DetRightMul[i] = dSX3RawProc.DetRightMul[i];
                        fdSX3DetBackMul[i] = dSX3RawProc.DetBackMul[i];
                    }

					//________________________________________________________
					// Upstream SX3
					std::sort(SX3uFront_.begin(), SX3uFront_.end(), CompareSX3Front);
					std::sort(SX3uBack_.begin(), SX3uBack_.end(), CompareSX3Back);

                    SX3DetRaw uSX3RawProc;
                    uSX3RawProc = ProcessSX3(SX3uFront_,SX3uBack_,1);

                    fuSX3LeftMul = uSX3RawProc.LeftMul;
                    for(int i=0; i<fuSX3LeftMul; i++) {
                        fuSX3DetLeft[i] = uSX3RawProc.DetLeft[i];
                        fuSX3LeftStrip[i] = uSX3RawProc.LeftStrip[i];
                        fuSX3LeftChannel[i] = uSX3RawProc.LeftChannel[i];
                        fuSX3LeftADC[i] = uSX3RawProc.LeftADC[i];
                    }

                    fuSX3RightMul = uSX3RawProc.RightMul;
                    for(int i=0; i<fuSX3RightMul; i++) {
                        fuSX3DetRight[i] = uSX3RawProc.DetRight[i];
                        fuSX3RightStrip[i] = uSX3RawProc.RightStrip[i];
                        fuSX3RightChannel[i] = uSX3RawProc.RightChannel[i];
                        fuSX3RightADC[i] = uSX3RawProc.RightADC[i];
                    }

                    fuSX3BackMul = uSX3RawProc.BackMul;
                    for(int i=0; i<fuSX3BackMul; i++) {
                        fuSX3DetBack[i] = uSX3RawProc.DetBack[i];
                        fuSX3BackSector[i] = uSX3RawProc.BackSector[i];
                        fuSX3BackChannel[i] = uSX3RawProc.BackChannel[i];
                        fuSX3BackADC[i] = uSX3RawProc.BackADC[i];
                    }

                    for(int i=0; i<12; i++) {
                        fuSX3DetLeftMul[i] = uSX3RawProc.DetLeftMul[i];
                        fuSX3DetRightMul[i] = uSX3RawProc.DetRightMul[i];
                        fuSX3DetBackMul[i] = uSX3RawProc.DetBackMul[i];
                    }


                    // Timing
                    //________________________________________________________
                    fTDCSilicon = tdcSilicon;;
                    fTDCSiliconDivTrig = tdcSiliconDivTrig;
                    fTDCSiliconGRETINATrig = tdcSiliconGRETINATrig;
                    fTDCRF = tdcRF;
                    fTDCGRETINA = tdcGRETINA;
                    fTDCSiliconAlt = tdcSiliconAlt;
                    fTDCSiliconUpstream = tdcSiliconUpstream;
                    fTimeStamp = timeStamp;
                    fRunNumber = std::stoi(run.runNumber);
                    treeRaw->Fill();

                }
            }
        }
        NumberBuffer++;
        if(NumberBuffer % 1000 == 0) std::cout << PrintOutput("\r Read through ","red") << (NumberBuffer*BUFFER_LENGTHB)/1.e6 << PrintOutput(" MB ","red") << std::flush;
    } //End of main loop over file


    treeRaw->Write();
    outputFileRaw->Close();

    file.close();
    int runClock = clock();

    std::cout << PrintOutput("\t\tFinished Unpacking Run: ", "cyan") << run.runNumber << '\t';
    std::cout << PrintOutput("Time", "cyan") << " = " << Form("%.02f", (runClock - startClock)/double(CLOCKS_PER_SEC)) << " seconds" << std::flush << std::endl;
    std::cout << PrintOutput("\t\tNumber of events: ", "cyan") << numberEvents << std::flush << std::endl;
    std::cout << PrintOutput("\t\tCreated ROOT file : ", "cyan") << outputFileRaw->GetName() << std::endl;

    if(run.copyCuts) {
        std::ifstream src(run.preCutPath, std::ios::binary);
        std::ofstream dst(run.cutPath, std::ios::binary);
        try {
            dst << src.rdbuf();
            std::cout << PrintOutput("\t\tCopied cut file from run: ", "cyan") << run.runNumber.c_str() << std::endl;
        }
        catch(int e) {
            std::cout << PrintOutput(Form("\t\tDid not copy cut from run %s", run.runNumber.c_str()), "red") << std::endl;
        }
        src.close();
        dst.close();
    }

    completed = true;
}
