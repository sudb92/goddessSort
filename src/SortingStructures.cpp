/**********************************************************************/
/* File: SortingStructures.C                                          */
/* Description: Functions for GRETINA/Aux control variables and       */
/*              counting variables in analysis                        */
/* Author: H. Crawford                                                */
/* Date: January 2013                                                 */
/**********************************************************************/

#include "SortingStructures.h"

ClassImp(controlVariables);
ClassImp(counterVariables);

/****************************************************/
/* Control variable functions...                    */
/****************************************************/

controlVariables::controlVariables() {
  doTRACK = 0;
  withWAVE = 0;
  withSEG = 1;
  withHISTOS = 1;
  withTREE = 1;
  dopplerSimple = 0;

  specifyCalibration = 0;
  calibrationFile = "";

  startRun = 0;
  fileType = "";
  directory = "";
  outputSuffix = "";
  outputON = 0;
  outputName = 0;
  outfileName = "";
  outputFileName = "";
  compressedFile = 0;
  compressedFileB = 0;
  noHFC = 0;
  suppressTS = 0;
  pgh = 0;
  noEB = 0;
  calibration = 0;
  superPulse = 0;
  xtalkAnalysis = 0;

  INLcorrection = 0;
  INLCConly = 0;
  digMapFileName = "";

  gateTree = 0;

  mode2Old = 0;

  analyze2AND3 = 0;
  fileName = "";

  WITH_TRACETREE = 0;
  CHECK_PILEUP = 0;
  FALLON_TIME = 0;
  LEDCROSSING = 0;
  FIT_BASELINE = 0;
  PZ_BASELINE = 0;
  PZ_ZERO_BASELINE = 0;
  RADFORD_BASELINE = 0;
  RADFORD_ENERGY = 0;
  GREGORICH_ENERGY = 0;
  POLEZERO_TRACE = 0;
  FPGA_ENERGY = 0;
  BASIC_ENERGY = 0;
  INL_CORRECT = 0;

  //#ifdef WITH_S800
  s800File = 0;
  s800ControlFile = "";

  S800_DIAG=0;
  E1_RAW=1; E1_CAL=0; E2_RAW=1; E2_CAL=0; E3_RAW=1; E3_CAL=0;
  IC_RAW=0; IC_CAL=0; IC_SUMS=0;
  CRDC1_RAW_PADS=0; CRDC1_RAW_CALC=0; CRDC1_CALC=0;
  CRDC2_RAW_PADS=0; CRDC2_RAW_CALC=0; CRDC2_CALC=0;
  FP_TRACK_RAW=0; FP_TRACK_COR=0;
  HODO_RAW=0; HODO_CAL=0;
  TARGET_PPAC_RAW=0; TARGET_PPAC_CALC=0;
  TARGET_PIN1_RAW=0; TARGET_PIN1_CAL=0;
  TARGET_PIN2_RAW=0; TARGET_PIN2_CAL=0;
  TARGET_TOTAL=0;
  IMAGE_CALC=0;
  IMAGE_TPPAC1_RAW=0; IMAGE_TPPAC1_CALC=0;
  IMAGE_TPPAC2_RAW=0; IMAGE_TPPAC2_CALC=0;
  IMAGE_TRACK=0;
  IMAGE_PPAC1_RAW=0; IMAGE_PPAC1_CALC=0;
  IMAGE_PPAC2_RAW=0; IMAGE_PPAC2_CALC=0;
  OBJECT_PIN_RAW=0; OBJECT_PIN_CAL=0;
  TRIGGER=0; S800_TIMESTAMP=0;
  TOF=0;
  //#endif
}

/****************************************************/

void controlVariables::Initialize() {
  doTRACK = 0;
  withWAVE = 0;
  withSEG = 1;
  withHISTOS = 0;
  withTREE = 1;
  dopplerSimple = 0;

  specifyCalibration = 0;
  calibrationFile = "";

  startRun = 0;
  fileType = "";
  directory = "";
  outputON = 0;
  outputName = 0;
  outputFileName = "";
  outputSuffix = "";
  outfileName = "";
  compressedFile = 0;
  compressedFileB = 0;
  noHFC = 0;
  suppressTS = 0;
  pgh = 0;
  noEB = 0;
  calibration = 0;

  INLcorrection = 0;
  digMapFileName = "";

  gateTree = 0;

  mode2Old = 0;

  analyze2AND3 = 0;
  fileName2 = "";

  WITH_TRACETREE = 0;
  CHECK_PILEUP = 0;
  FALLON_TIME = 0;
  LEDCROSSING = 0;
  FIT_BASELINE = 0;
  PZ_BASELINE = 0;
  PZ_ZERO_BASELINE = 0;
  RADFORD_BASELINE = 0;
  RADFORD_ENERGY = 0;
  GREGORICH_ENERGY = 0;
  POLEZERO_TRACE = 0;
  FPGA_ENERGY = 0;
  BASIC_ENERGY = 0;
  INL_CORRECT = 0;

  //#ifdef WITH_S800
  s800File = 0;
  s800ControlFile = "";
  S800_DIAG=0;
  E1_RAW=1; E1_CAL=0; E2_RAW=1; E2_CAL=0; E3_RAW=1; E3_CAL=0;
  IC_RAW=0; IC_CAL=0; IC_SUMS=0;
  CRDC1_RAW_PADS=0; CRDC1_RAW_CALC=0; CRDC1_CALC=0;
  CRDC2_RAW_PADS=0; CRDC2_RAW_CALC=0; CRDC2_CALC=0;
  FP_TRACK_RAW=0; FP_TRACK_COR=0;
  HODO_RAW=0; HODO_CAL=0;
  TARGET_PPAC_RAW=0; TARGET_PPAC_CALC=0;
  TARGET_PIN1_RAW=0; TARGET_PIN1_CAL=0;
  TARGET_PIN2_RAW=0; TARGET_PIN2_CAL=0;
  TARGET_TOTAL=0;
  IMAGE_CALC=0;
  IMAGE_TPPAC1_RAW=0; IMAGE_TPPAC1_CALC=0;
  IMAGE_TPPAC2_RAW=0; IMAGE_TPPAC2_CALC=0;
  IMAGE_TRACK=0;
  IMAGE_PPAC1_RAW=0; IMAGE_PPAC1_CALC=0;
  IMAGE_PPAC2_RAW=0; IMAGE_PPAC2_CALC=0;
  OBJECT_PIN_RAW=0; OBJECT_PIN_CAL=0;
  TRIGGER=0; S800_TIMESTAMP=0;
  TOF=0;
  //#endif

}

/****************************************************/

Int_t controlVariables::InterpretCommandLine(int argc, char *argv[]) {
  Int_t i=1;
  while (i < argc && startRun == 0) {
    if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "-gr") == 0 ||
	strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "-m2") == 0 ||
	strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "-f2") == 0 ||
	strcmp(argv[i], "-f1") == 0) {
      fileType = argv[i];
      fileType.ReplaceAll("-","");
      if (fileType == "f" || fileType == "f1") {
	fileName = argv[i+1];
	i++;
      }
      if (fileType == "f2") {
	fileName2 = argv[i+1];
	i++;
      }
      i++;
    }
    else if (strcmp(argv[i], "-track") == 0) {
      doTRACK = 1;
      std::cout << "\t\t" << PrintOutput("Tracking enabled.", "blue") << std::endl;
      i++;
    }
    else if (strcmp(argv[i], "-wf") == 0) {
      withWAVE = 1;
      WITH_TRACETREE = 1;
      std::cout << "Waveform analysis enabled. " << std::endl;
      i++;
    }
    else if (strcmp(argv[i], "-noSeg") == 0) {
      withSEG = 0;
      std::cout << "Segment analysis disabled. " << std::endl;
      i++;
    }
    else if (strcmp(argv[i], "-outputON") == 0) {
      outputON = 1;
      std::cout << "Will write S800Physics + GRETINA output according to gate conditions. " << std::endl;
      i++;
    }
    else if (strcmp(argv[i], "-outputName") == 0) {
      outputName = 1; outputON = 1;
      std::cout << "Will write output called ";
      i++;
      outputFileName = argv[i]; i++;
      std::cout << outputFileName <<std::endl;
    }
    else if (strcmp(argv[i], "-outputSuffix") == 0) {
      i++;
      outputSuffix = argv[i];
      std::cout << "Will include " << outputSuffix.Data()
	   << " on ROOT files." << std::endl;
    }
    else if (strcmp(argv[i], "-rootName") == 0) {
      i++;
      outfileName = argv[i]; i++;
    }
    else if (strcmp(argv[i], "-analyze2and3") == 0) {
      i++;
      analyze2AND3 = 1;
      withWAVE = 1;
    }
    else if (strcmp(argv[i], "-gateTree") == 0) {
      gateTree = 1;
      i++;
    }
    else if (strcmp(argv[i], "-zip") == 0) {
      compressedFile = 1;
      i++;
    }
    else if (strcmp(argv[i], "-bzip") == 0) {
      compressedFileB = 1;
      i++;
    }
    else if (strcmp(argv[i], "-withHistos") == 0) {
      withHISTOS = 1;
      i++;
    }
    else if (strcmp(argv[i], "-noTree") == 0) {
      withTREE = 0;
      i++;
    }
    else if (strcmp(argv[i], "-d") == 0) {
      directory = argv[i+1];
      i += 2;
    }
    else if (strcmp(argv[i], "-run") == 0) {
      startRun = i+1;
    }
    else if (strcmp(argv[i], "-noHFC") == 0) {
      noHFC = 1;
      i++;
    }
    else if (strcmp(argv[i], "-dopplerSimple") == 0) {
      dopplerSimple = 1;
      i++;
    }
    else if (strcmp(argv[i], "-suppressTS") == 0) {
      suppressTS = 1;
      i++;
    }
    else if (strcmp(argv[i], "-s800File") == 0) {
      s800File = 1;
      s800ControlFile = argv[i+1];
      i+=2;
    }
    else if (strcmp(argv[i], "-preGH2") == 0) {
      pgh = 2;
      noHFC = 1;
      i++;
    }
    else if (strcmp(argv[i], "-preGH3") == 0) {
      pgh = 3;
      noHFC = 1;
      i++;
    }
    else if (strcmp(argv[i], "-noEB") == 0) {
      noEB = 1;
      std::cout << "Event building turned off." << std::endl;
      i++;
    }
    else if (strcmp(argv[i], "-calibrationRun") == 0) {
      calibration = 1; noEB = 1; withHISTOS = 1; withTREE = 0;
      std::cout << "Calibration run. Disabled event building too. " << std::endl;
      i++;
    }
    else if (strcmp(argv[i], "-readCal") == 0) {
      specifyCalibration = 1; calibrationFile = argv[i+1];
      i+=2;
    }
    else if (strcmp(argv[i], "-superPulse") == 0) {
      superPulse = 1; i++;
      withWAVE = 1;
      spLowE = atoi(argv[i]); i++;
      spHighE = atoi(argv[i]); i++;
      spCalibDirectory = argv[i]; i++;
      spXtalkFile = argv[i]; i++;
      withHISTOS = 0; withTREE = 0;
    }
    else if (strcmp(argv[i], "-xtalkAnalysis") == 0) {
      xtalkAnalysis = 1; i++;
      xtalkID = atoi(argv[i]); i++;
      xtLowE = atoi(argv[i]); i++;
      xtHighE = atoi(argv[i]); i++;
      withTREE = 0;
    } else if (strcmp(argv[i], "-INLcorrect") == 0) {
      INLcorrection = 1; i++;
      INLCConly = atoi(argv[i]); i++;
      digMapFileName = argv[i]; i++;
      withWAVE = 1;
      WITH_TRACETREE = 1;
    } else {
      std::cout << "Error -- unrecognized input flag: " << argv[i] << std::endl;
      return -1;
    }
  }
  return 1;
}

/****************************************************/

Int_t controlVariables::ReportRunFlags() {
  std::cout << "\t\t" << PrintOutput("", "blue") << std::endl;
  std::cout << "\t\t" << PrintOutput("  Analysis conditions: ", "blue") << std::endl;
  std::cout << "\t\t" << PrintOutput("     Expecting ", "blue") << std::endl;
  if (compressedFile) {
    std::cout << "\t\t" << PrintOutput(" compressed ", "blue") << std::endl;
  }
  if (fileType == "g" && !pgh) {
    std::cout << "\t\t" << PrintOutput("GRETINA + auxiliary file WITH global headers -- Global.dat", "blue") << std::endl;
  } else if (fileType == "g" && pgh == 2) {
    std::cout << "\t\t" << PrintOutput("old GRETINA mode2 only file WITHOUT global headers -- Global.dat", "blue") << std::endl;
  } else if (fileType == "g" && pgh == 3) {
    std::cout << "\t\t" << PrintOutput("old GRETINA mode3 only file WITHOUT global headers -- Global.dat", "blue") << std::endl;
  } else if (fileType == "gr" && !pgh) {
    std::cout << "\t\t" << PrintOutput("GRETINA mode3 file WITH global headers -- GlobalRaw.dat", "blue") << std::endl;
  } else if (fileType == "m") {
    std::cout << "\t\t" << PrintOutput("merged GRETINA mode3 + auxiliary WITH global headers -- Merged.dat", "blue") << std::endl;
  } else if (fileType == "m2") {
    std::cout << "\t\t" << PrintOutput("merged GRETINA mode2 + auxiliary WITH global headers -- Merged.Mode2.dat", "blue") << std::endl;
  }
  if (compressedFile) {
    std::cout << "\t\t" << PrintOutput(".gz ", "blue") << std::endl;
  }  else {
    std::cout << std::endl;
  }
  if (withTREE && withHISTOS ) {
    std::cout << "\t\t" << PrintOutput("     Will write out a ROOT tree and defined histograms.", "blue") << std::endl;
  }
  if (withTREE && !withHISTOS) {
    std::cout << "\t\t" << PrintOutput("     Will write out a ROOT tree, but no histograms. ", "blue") << std::endl;
  }
  if (!withTREE && withHISTOS) {
    std::cout << "\t\t" << PrintOutput("     Will write out defined histograms, but no ROOT tree. ", "blue") << std::endl;
  }
  if (!withTREE && !withHISTOS && !superPulse) {
    std::cout << "\t\t" << PrintOutput("     You aren't planning on writing histograms or a tree...are you sure you want to proceed? ('yes' or 'no')", "blue") << std::endl;
    char answer[50];
    std::cin >> answer;
    if (strcmp(answer, "yes") != 0) {
      std::cout << "\t\t" << PrintOutput("Aborting now. ", "blue") << std::endl;
      return(-1);
    }
  }
  if (noHFC && suppressTS) {
    std::cout << "\t\t" << PrintOutput("     Will NOT use Dirk's GEB_HFC resorter code, and will ignore TS order errors. ", "blue") << std::endl;
  }
  if (noHFC && !suppressTS) {
    std::cout << "\t\t" << PrintOutput("     Will NOT use Dirk's GEB_HFC resorter code, and will print any observed TS order errors. ", "blue") << std::endl;
  }
  if (!noHFC && suppressTS) {
    std::cout << "\t\t" << PrintOutput("     Will use Dirk's GEB_HFC resorter code, and will print any observed TS order errors. ", "blue") << std::endl;
  }
  if (!noHFC && !suppressTS) {
    std::cout << "\t\t" << PrintOutput("     Will use Dirk's GEB_HFC resorter code, and will ignore TS order errors. ", "blue") << std::endl;
  }
  if (doTRACK) {
    std::cout << "\t\t" << PrintOutput("     Will try really hard to do tracking, using Torben's code. ", "blue") << std::endl;
  }
  if (withWAVE) {
    std::cout << "\t\t" << PrintOutput("     Will do some waveform analysis on GRETINA waveforms, as specified with flags in Unpack.h. ", "blue") << std::endl;
  }
  if (outputON) {
    std::cout << "\t\t" << PrintOutput("     Will generate combined output data file with processed aux data where appropriate (i.e. mode9 S800Physics) ", "blue") << std::endl;
  }
  return(1);
}

void controlVariables::SetS800Controls(TString fileName) {
  FILE *controlINPUT;
  if ( (controlINPUT = fopen(fileName.Data(), "r")) == NULL ) {
    std::cerr << "S800 control file " << fileName.Data() << " could not be opened." << std::endl;
  }
  std::cout << "Setting S800 controls based on " << fileName.Data() << std::endl;

  char line[300];
  char junk[300];
  char filename[300];
  int value;

  while ( !feof(controlINPUT) ) {
    fgets(line, 300, controlINPUT);
    if (strlen(line) == 1) { continue; }
    if (strncmp(line, "#", 1) == 0) { continue; }
    if (strncmp(line, "VariableFile", 12) == 0) {
      sscanf(line, "%s %s", junk, filename);
      s800VariableFile = filename;
    }
    if (strncmp(line, "S800_DIAG", 9) == 0) {
      sscanf(line, "%s %d", junk, &value);
      S800_DIAG = value;
    }
    if (strncmp(line, "E1_RAW", 6) == 0) {
      sscanf(line, "%s %d", junk, &value);
      E1_RAW = value;
    }
    if (strncmp(line, "E1_CAL", 6) == 0) {
      sscanf(line, "%s %d", junk, &value);
      E1_CAL = value;
    }
    if (strncmp(line, "E2_RAW", 6) == 0) {
      sscanf(line, "%s %d", junk, &value);
      E2_RAW = value;
    }
    if (strncmp(line, "E2_CAL", 6) == 0) {
      sscanf(line, "%s %d", junk, &value);
      E2_CAL = value;
    }
    if (strncmp(line, "E3_RAW", 6) == 0) {
      sscanf(line, "%s %d", junk, &value);
      E3_RAW = value;
    }
    if (strncmp(line, "E3_CAL", 6) == 0) {
      sscanf(line, "%s %d", junk, &value);
      E3_CAL = value;
    }
    if (strncmp(line, "IC_RAW", 6) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IC_RAW = value;
    }
    if (strncmp(line, "IC_CAL", 6) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IC_CAL = value;
    }
    if (strncmp(line, "CRDC1_RAW_PADS", 14) == 0) {
      sscanf(line, "%s %d", junk, &value);
      CRDC1_RAW_PADS = value;
    }
    if (strncmp(line, "CRDC1_RAW_CALC", 14) == 0) {
      sscanf(line, "%s %d", junk, &value);
      CRDC1_RAW_CALC = value;
    }
    if (strncmp(line, "CRDC1_CALC", 10) == 0) {
      sscanf(line, "%s %d", junk, &value);
      CRDC1_CALC = value;
    }
    if (strncmp(line, "CRDC2_RAW_PADS", 14) == 0) {
      sscanf(line, "%s %d", junk, &value);
      CRDC2_RAW_PADS = value;
    }
    if (strncmp(line, "CRDC2_RAW_CALC", 14) == 0) {
      sscanf(line, "%s %d", junk, &value);
      CRDC2_RAW_CALC = value;
    }
    if (strncmp(line, "CRDC2_CALC", 10) == 0) {
      sscanf(line, "%s %d", junk, &value);
      CRDC2_CALC = value;
    }
    if (strncmp(line, "S800_TIMESTAMP", 14) == 0) {
      sscanf(line, "%s %d", junk, &value);
      S800_TIMESTAMP = value;
    }
    if (strncmp(line, "FP_TRACK_RAW", 12) == 0) {
      sscanf(line, "%s %d", junk, &value);
      FP_TRACK_RAW = value;
    }
    if (strncmp(line, "FP_TRACK_COR", 12) == 0) {
      sscanf(line, "%s %d", junk, &value);
      FP_TRACK_COR = value;
    }
    if (strncmp(line, "HODO_RAW", 8) == 0) {
      sscanf(line, "%s %d", junk, &value);
      HODO_RAW = value;
    }
    if (strncmp(line, "HODO_CAL", 8) == 0) {
      sscanf(line, "%s %d", junk, &value);
      HODO_CAL = value;
    }
    if (strncmp(line, "TARGET_PPAC_RAW", 15) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TARGET_PPAC_RAW = value;
    }
    if (strncmp(line, "TARGET_PPAC_CALC", 16) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TARGET_PPAC_CALC = value;
    }
    if (strncmp(line, "TARGET_PIN1_RAW", 15) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TARGET_PIN1_RAW = value;
    }
    if (strncmp(line, "TARGET_PIN1_CAL", 15) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TARGET_PIN1_CAL = value;
    }
    if (strncmp(line, "TARGET_PIN2_RAW", 15) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TARGET_PIN2_RAW = value;
    }
    if (strncmp(line, "TARGET_PIN2_CAL", 15) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TARGET_PIN2_CAL = value;
    }
    if (strncmp(line, "TARGET_TOTAL", 12) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TARGET_TOTAL = value;
    }
    if (strncmp(line, "IMAGE_CALC", 10) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_CALC = value;
    }
    if (strncmp(line, "IMAGE_TPPAC1_RAW", 16) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_TPPAC1_RAW = value;
    }
    if (strncmp(line, "IMAGE_TPPAC1_CALC", 17) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_TPPAC1_CALC = value;
    }
    if (strncmp(line, "IMAGE_TPPAC2_RAW", 16) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_TPPAC2_RAW = value;
    }
    if (strncmp(line, "IMAGE_TPPAC2_CALC", 17) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_TPPAC2_CALC = value;
    }
    if (strncmp(line, "IMAGE_TRACK", 11) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_TRACK = value;
    }
    if (strncmp(line, "IMAGE_PPAC1_RAW", 15) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_PPAC1_RAW = value;
    }
    if (strncmp(line, "IMAGE_PPAC1_CALC", 16) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_PPAC1_CALC = value;
    }
    if (strncmp(line, "IMAGE_PPAC2_RAW", 15) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_PPAC2_RAW = value;
    }
    if (strncmp(line, "IMAGE_PPAC2_CALC", 16) == 0) {
      sscanf(line, "%s %d", junk, &value);
      IMAGE_PPAC2_CALC = value;
    }
    if (strncmp(line, "OBJECT_PIN_RAW", 14) == 0) {
      sscanf(line, "%s %d", junk, &value);
      OBJECT_PIN_RAW = value;
    }
    if (strncmp(line, "OBJECT_PIN_CAL", 14) == 0) {
      sscanf(line, "%s %d", junk, &value);
      OBJECT_PIN_CAL = value;
    }
    if (strncmp(line, "TRIGGER", 7) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TRIGGER = value;
    }
    if (strncmp(line, "TOF", 3) == 0) {
      sscanf(line, "%s %d", junk, &value);
      TOF = value;
    }
  }
  fclose(controlINPUT);
}

/****************************************************/
/* Counter variable functions...                    */
/****************************************************/

void counterVariables::Initialize() {
  event = 0x0000;

  TSFirst = 0; TSLast = 0;

  for (Int_t i=0; i<100; i++) { headerType[i] = 0; }

  TSerrors = 0;

  bytes_read = 0; bytes_read_since_last_time = 0;
  MBread = 0;

  eoBuffer = 0; eofInBuffer = 0; eofPosInBuffer = 0;
  mode3i = 0; old3Bytes = 0;
  b88i = 0;

  treeWrites = 0;

  badEvent = 0; badSegment = 0; badCC1 = 0; badCC2 = 0;
  for (Int_t i=0; i<(MAXCHANNELS); i++) {
    goodTraceE_PU[i] = 0; goodTraceE[i] = 0;
    badFPGA_zero_PU[i] = 0; badFPGA_zero[i] = 0;
    badFPGA_neg_PU[i] = 0; badFPGA_neg[i] = 0;
  }
  crystalBuildEvent = 0; totalCrystalEvent = 0;
  for (Int_t i=0; i<MAXCRYSTALS; i++) {
    crystalBuildEventXtal[i] = 0; totalCrystalEventXtal[i] = 0;
  }
  tossed4Time = 0;

  for (Int_t i=0; i<4*MAXCRYSTALS; i++) { /* 4 boards/crystal */
    lastBdTS[i] = 0;
  }

  nGammasRead = 0; nGammasThisHeader = 0;

  for (Int_t i=0; i<MAXCRYSTALS; i++) {
    for (Int_t j=0; j<41; j++) {
      nMode3Skipped[i][j] = 0;
      nMode3SkippedAtEnd[i][j] = 0;
    }
    nMode2NoTraces[i] = 0;
    nMode3NoMode2[i] = 0;
  }

}

/****************************************************/

void counterVariables::ResetRunCounters() {
  event = 0x0000;
  for (Int_t i=0; i<100; i++) { headerType[i] = 0; }

  TSFirst = 0; TSLast = 0;

  TSerrors = 0;

  bytes_read = 0; bytes_read_since_last_time = 0;
  MBread = 0;

  treeWrites = 0;

  eoBuffer = 0; eofInBuffer = 0; eofPosInBuffer = 0;
  mode3i = 0; old3Bytes = 0;
  b88i = 0;

  badEvent = 0; badSegment = 0; badCC1 = 0; badCC2 = 0;
  for (Int_t i=0; i<(MAXCHANNELS); i++) {
    goodTraceE_PU[i] = 0; goodTraceE[i] = 0;
    badFPGA_zero_PU[i] = 0; badFPGA_zero[i] = 0;
    badFPGA_neg_PU[i] = 0; badFPGA_neg[i] = 0;
  }
  crystalBuildEvent = 0; totalCrystalEvent = 0;
  for (Int_t i=0; i<MAXCRYSTALS; i++) {
    crystalBuildEventXtal[i] = 0; totalCrystalEventXtal[i] = 0;
  }
  tossed4Time = 0;

  for (Int_t i=0; i<(MAXCRYSTALS*4); i++) {
    lastBdTS[i] = 0;
  }

  nGammasRead = 0; nGammasThisHeader = 0;

  for (Int_t i=0; i<MAXCRYSTALS; i++) {
    for (Int_t j=0; j<41; j++) {
      nMode3Skipped[i][j] = 0;
      nMode3SkippedAtEnd[i][j] = 0;
    }
    nMode2NoTraces[i] = 0;
    nMode3NoMode2[i] = 0;
  }

}

/****************************************************/

void counterVariables::PrintRunStatistics(Int_t pgh, Int_t withWAVE, Int_t superPulse,
					  Int_t sort2and3) {
  std::cout << PrintOutput("\t\t-----------------------------------------------------------\n", "blue");
  if(!pgh) {
    std::cout << PrintOutput("\t\tRun Statistics:\n", "blue");
    std::cout << PrintOutput("\t\t GRETINA-related data...\n", "blue");
    if (headerType[TRACK] > 0)
      std::cout << PrintOutput("\t\t  Mode1 GRETINA headers: ", "blue") << headerType[TRACK] << std::endl;
    if (headerType[DECOMP] > 0)
      std::cout << PrintOutput("\t\t  Mode2 GRETINA headers: ", "blue") << headerType[DECOMP] << std::endl;
    if (headerType[RAW] > 0)
      std::cout << PrintOutput("\t\t  Mode3 GRETINA headers: ", "blue") << headerType[RAW] << std::endl;
    if (headerType[G4SIM] > 0)
      std::cout << PrintOutput("\t\t  Simulation GRETINA headers: ", "blue") << headerType[G4SIM] << std::endl;
    if (headerType[GRETSCALER] > 0)
      std::cout << PrintOutput("\t\t  Scaler GRETINA headers: ", "blue") << headerType[GRETSCALER] << std::endl;
    if (headerType[BANK88] > 0)
      std::cout << PrintOutput("\t\t  Bank88 GRETINA headers: ", "blue") << headerType[BANK88] << std::endl;

    std::cout << PrintOutput("\n\t\t Auxiliary detectors...\n", "blue");
    if (headerType[BGS] > 0)
      std::cout << PrintOutput("\t\t  BGS headers: ", "blue") << headerType[BGS] << std::endl;
    if (headerType[CHICO] > 0)
      std::cout << PrintOutput("\t\t  CHICO headers: ", "blue") << headerType[CHICO] << std::endl;
    if (headerType[PWALL] > 0)
      std::cout << PrintOutput("\t\t  PhosWall headers: ", "blue") << headerType[PWALL] << std::endl;
    if (headerType[PWALLAUX] > 0)
      std::cout << PrintOutput("\t\t  PhosWall Aux. headers: ", "blue") << headerType[PWALL] << std::endl;
    if (headerType[S800] > 0)
      std::cout << PrintOutput("\t\t  S800 headers: ", "blue") << headerType[S800] << std::endl;
    if (headerType[S800PHYSICS] > 0)
      std::cout << PrintOutput("\t\t  S800Physics headers: ", "blue") << headerType[S800PHYSICS] << std::endl;
    if (headerType[S800AUX] > 0 || headerType[S800AUX_TS] > 0)
      std::cout << PrintOutput("\t\t  S800 Aux. headers: ", "blue") << (headerType[S800AUX]+headerType[S800AUX_TS]) << std::endl;
    if (headerType[LENDA] > 0)
      std::cout << PrintOutput("\t\t  LENDA headers: ", "blue") << headerType[LENDA] << std::endl;
    if (headerType[GODDESS] > 0)
      std::cout << PrintOutput("\t\t  GODDESS headers: ", "blue") << headerType[GODDESS] << std::endl;
  }
  std::cout << PrintOutput("\n\t\t TS errors: ", "blue") << TSerrors << std::endl;
  std::cout << PrintOutput("\n\n\t\t Run time (from TS): ", "blue") << (TSLast - TSFirst)*1e-8 << PrintOutput(" seconds\n", "blue");

  if (sort2and3) {
    std::cout << std::endl << "Mode2 + 3 Analysis concerns..." << std::endl;
    std::cout << std::endl;
    std::cout << "  Mode3 events skipped: " << std::endl;
    for (Int_t j=0; j<41; j++) {
      for (Int_t i=1; i<MAXCRYSTALS; i++) {
	nMode3Skipped[0][j]+=nMode3Skipped[i][j];
      }
      if (nMode3Skipped[0][j] > 0) {
	if (j<10) {
	  std::cout << "      " << j << " channels --> " << nMode3Skipped[0][j] << std::endl;
	} else {
	  std::cout << "     " << j << " channels --> " << nMode3Skipped[0][j] << std::endl;
	}
      }
    }
    std::cout << std::endl;
    std::cout << "  Mode3 events skipped at end of file: " << std::endl;
    for (Int_t j=0; j<41; j++) {
      for (Int_t i=1; i<MAXCRYSTALS; i++) {
	nMode3SkippedAtEnd[0][j]+=nMode3Skipped[i][j];
      }
      if (nMode3SkippedAtEnd[0][j] > 0) {
	if (j<10) {
	  std::cout << "      " << j << " channels --> " << nMode3SkippedAtEnd[0][j] << std::endl;
	} else {
	  std::cout << "     " << j << " channels --> " << nMode3SkippedAtEnd[0][j] << std::endl;
	}
      }
    }
    std::cout << std::endl;

    std::cout <<  "Mode2 without waveforms: ";
    for (Int_t i=1; i<MAXCRYSTALS; i++) {
      nMode2NoTraces[0]+=nMode2NoTraces[i];
    }
    std::cout << nMode2NoTraces[0] << std::endl << std::endl;

    std::cout <<  "Mode3 without Mode2: ";
    for (Int_t i=1; i<MAXCRYSTALS; i++) {
      nMode3NoMode2[0]+=nMode3NoMode2[i];
    }
    std::cout << nMode3NoMode2[0] << std::endl << std::endl;
  }

  /* This is a little antiquated... from the days of missing FPGA energies,
     etc.  I'll keep it around for now, to remember how much the early data sucked. */

  if (withWAVE && !superPulse) {
    std::cout << "Segments tossed from sums due to bad LED timing: " << tossed4Time << "\n" << std::endl;

    std::cout << "Good crystal build events: " << crystalBuildEvent << "/" << totalCrystalEvent
	 << " = " << (float)(100*crystalBuildEvent)/totalCrystalEvent << "%" << std::endl;
    std::cout << "  # with a bad channel: " << badEvent << " ("
	 << (float)(100*badEvent)/crystalBuildEvent << "%)" << std::endl;
    std::cout << "  # with bad segment:   " << badSegment << " ("
	 << (float)(100*badSegment)/crystalBuildEvent << "%)" <<  std::endl;
    std::cout << "  # with bad cc1:       " << badCC1 << " ("
	 << (float)(100*badCC1)/crystalBuildEvent << "%)" << std::endl;
    std::cout << "  # with bad cc2:       " << badCC2 << " ("
	 << (float)(100*badCC2)/crystalBuildEvent << "%)" << std::endl;
    std::cout << std::endl;

    Int_t tempSum1 = 0; Int_t tempSum2 = 0;
    Int_t tempSum1_pu = 0; Int_t tempSum2_pu = 0;
    Int_t tempSum2_neg = 0; Int_t tempSum2_neg_pu = 0;

    for (Int_t i=0; i<(MAXCHANNELS); i++) {
      tempSum1 += goodTraceE[i]; tempSum1_pu += goodTraceE_PU[i];
    }
    std::cout << "  # good channel trace E:  " << tempSum1+tempSum1_pu
	 << " (" << (float)tempSum1_pu/(tempSum1_pu+tempSum1) << "% PU flag)" << std::endl;

    tempSum2 = 0;  tempSum2_pu = 0;
    tempSum2_neg = 0;   tempSum2_neg_pu = 0;
    for (Int_t i=0; i<(MAXCHANNELS); i++) {
      tempSum2 += (badFPGA_zero[i]); tempSum2_pu += (badFPGA_zero_PU[i]);
      tempSum2_neg += (badFPGA_neg[i]); tempSum2_neg_pu += (badFPGA_neg_PU[i]);
    }
    std::cout << "  # bad FPGA energies:     " << tempSum2+tempSum2_pu+tempSum2_neg+tempSum2_neg_pu
	 << " ("
	 << (float)100*(tempSum2+tempSum2_pu+tempSum2_neg+tempSum2_neg_pu)/(tempSum1+tempSum1_pu)
	 << "%)" << std::endl;
    std::cout << "            zero FPGA:     " << tempSum2+tempSum2_pu << " ("
	 << (float)100*(tempSum2+tempSum2_pu)/(tempSum1+tempSum1_pu) << "%)" << std::endl;
    std::cout << "        negative FPGA:     " << tempSum2_neg+tempSum2_neg_pu << " ("
	 << (float)100*(tempSum2_neg+tempSum2_neg_pu)/(tempSum1+tempSum1_pu) << "%)" << std::endl;

    tempSum1 = 0;  tempSum1_pu = 0;
    tempSum2 = 0;  tempSum2_pu = 0;
    tempSum2_neg = 0;   tempSum2_neg_pu = 0;
    for (Int_t i=0; i<(MAXCHANNELS); i++) {
      if (i%40 != 39 && i%40 != 29) {
	tempSum1 += goodTraceE[i]; tempSum1_pu += goodTraceE_PU[i];
      }
      if (i%40 != 39 && i%40 != 29) {
	tempSum2 += badFPGA_zero[i]; tempSum2_pu += badFPGA_zero_PU[i];
	tempSum2_neg += (badFPGA_neg[i]); tempSum2_neg_pu += (badFPGA_neg_PU[i]);
      }
    }
    std::cout << "  ---------------------------" << std::endl;
    std::cout << "  % segments missing: "
	 << (float)100*(tempSum2+tempSum2_pu+tempSum2_neg+tempSum2_neg_pu)/(tempSum1+tempSum1_pu)
	 << "%" << std::endl;
    std::cout << "     without PU flag: " << (float)100*(tempSum2)/(tempSum1) << "% zeros/ "
	 << (float)100*(tempSum2_neg)/(tempSum1) << "% negative" << std::endl;
    std::cout << "        with PU flag: " << (float)100*(tempSum2_pu)/(tempSum1_pu) << "% zeros/ "
	 << (float)100*(tempSum2_neg_pu)/(tempSum1_pu) << "% negative" << std::endl;

    tempSum1 = 0;  tempSum1_pu = 0;
    tempSum2 = 0;  tempSum2_pu = 0;
    tempSum2_neg = 0;   tempSum2_neg_pu = 0;
    for (Int_t i=0; i<(MAXCHANNELS); i++) {
      if (i%40 == 29) {
	tempSum1 += goodTraceE[i]; tempSum1_pu += goodTraceE_PU[i];
      }
      if (i%40 == 29) {
	tempSum2 += badFPGA_zero[i]; tempSum2_pu += badFPGA_zero_PU[i];
	tempSum2_neg += (badFPGA_neg[i]); tempSum2_neg_pu += (badFPGA_neg_PU[i]);
      }
    }
    std::cout << "  ---------------------------" << std::endl;
    std::cout << "       % cc1 missing: "
	 << (float)100*(tempSum2+tempSum2_pu+tempSum2_neg+tempSum2_neg_pu)/(tempSum1+tempSum1_pu)
	 << "%" << std::endl;
    std::cout << "     without PU flag: " << (float)100*(tempSum2)/(tempSum1) << "% zeros/ "
	 << (float)100*(tempSum2_neg)/(tempSum1) << "% negative" << std::endl;
    std::cout << "        with PU flag: " << (float)100*(tempSum2_pu)/(tempSum1_pu) << "% zeros/ "
	 << (float)100*(tempSum2_neg_pu)/(tempSum1_pu) << "% negative" << std::endl;

    tempSum1 = 0;  tempSum1_pu = 0;
    tempSum2 = 0;  tempSum2_pu = 0;
    tempSum2_neg = 0;   tempSum2_neg_pu = 0;
    for (Int_t i=0; i<(MAXCHANNELS); i++) {
      if (i%40 == 39) {
	tempSum1 += goodTraceE[i]; tempSum1_pu += goodTraceE_PU[i];
      }
      if (i%40 == 39) {
	tempSum2 += badFPGA_zero[i]; tempSum2_pu += badFPGA_zero_PU[i];
	tempSum2_neg += (badFPGA_neg[i]); tempSum2_neg_pu += (badFPGA_neg_PU[i]);
      }
    }
    std::cout << "  ---------------------------" << std::endl;
    std::cout << "       % cc2 missing: "
	 << (float)100*(tempSum2+tempSum2_pu+tempSum2_neg+tempSum2_neg_pu)/(tempSum1+tempSum1_pu)
	 << "%" << std::endl;
    std::cout << "     without PU flag: " << (float)100*(tempSum2)/(tempSum1) << "% zeros/ "
	 << (float)100*(tempSum2_neg)/(tempSum1) << "% negative" << std::endl;
    std::cout << "        with PU flag: " << (float)100*(tempSum2_pu)/(tempSum1_pu) << "% zeros/ "
	 << (float)100*(tempSum2_neg_pu)/(tempSum1_pu) << "% negative" << std::endl;
    std::cout << "  ---------------------------" << std::endl;
  }

  std::cout << PrintOutput("\t\t--------------------------------------------------\n", "blue");
}

void counterVariables::Increment(Int_t bytes) {
  bytes_read += bytes;
  bytes_read_since_last_time += bytes;
}

void counterVariables::setEventBit(Int_t bit) {
  event |= (0x1 << bit);
}

Int_t counterVariables::getEventBit(Int_t bit) {
  return ((event >> bit) & 0x1);
}
