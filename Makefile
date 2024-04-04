# Based on guide here: https://stackoverflow.com/questions/30573481/how-to-write-a-makefile-with-separate-source-and-header-directories
# run it as `make -f Makefile PROF_FLAG=-pg to profile using gprof

CXX=g++

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := lib
BIN_DIR := .

CXXFLAGS := -g -fPIC -I$(INC_DIR) -MMD -MP -O2
ROOTCFLAGS :=  `root-config --cflags`
LDFLAGS := `root-config --ldflags`
LDLIBS := `root-config --libs`

CXXFLAGS += $(ROOTCFLAGS)

# Headers explicitly passed to generate dictionary
DICT_H := $(INC_DIR)/GRETINA.h $(INC_DIR)/SortingStructures.h $(INC_DIR)/GRETINAWavefunction.h $(INC_DIR)/INLCorrection.h $(INC_DIR)/Histos.h $(INC_DIR)/Track.h $(INC_DIR)/Utilities.h

# Sources and objects for library
LIB_SRC := $(SRC_DIR)/GRETINA.cpp $(SRC_DIR)/SortingStructures.cpp $(SRC_DIR)/SuperPulse.cpp $(SRC_DIR)/INLCorrection.cpp $(SRC_DIR)/G3Waveform.cpp $(SRC_DIR)/Histos.cpp $(SRC_DIR)/Track.cpp $(SRC_DIR)/Utilities.cpp

# Sources for unpackGRETINA
GRET_SRC := $(SRC_DIR)/UnpackGRETINARaw.cpp $(SRC_DIR)/Globals.cpp $(SRC_DIR)/UnpackUtilities.cpp $(SRC_DIR)/S800Functions.cpp

GRET_EXE := $(BIN_DIR)/unpackGRETINA

S800_LIB := $(BIN_DIR)/libS800.so

S800_LIB_SRC := $(SRC_DIR)/S800Parameters.cpp $(SRC_DIR)/S800Functions.cpp $(BIN_DIR)/S800Dict.cxx

GRETINA_LIB = $(BIN_DIR)/libGRETINA.so

GRETINA_LD_FLAG = -L$(BIN_DIR)/ -Wl,-rpath $(BIN_DIR)/ -lGRETINA

S800_LD_FLAG = -L$(BIN_DIR)/ -Wl,-rpath $(BIN_DIR)/ -lS800

HFC_EXE := $(BIN_DIR)/GEB_HFC

SORT_EXE := $(BIN_DIR)/goddessSort

SORT_SRC := $(SRC_DIR)/Calibrations.cpp $(SRC_DIR)/ProcessBB10.cpp $(SRC_DIR)/ProcessIC.cpp $(SRC_DIR)/ProcessQQQ5.cpp $(SRC_DIR)/ProcessSX3.cpp $(SRC_DIR)/RunList.cpp $(SRC_DIR)/UnpackORRUBA.cpp $(SRC_DIR)/Utilities.cpp $(SRC_DIR)/jsoncpp.cpp $(SRC_DIR)/UnpackGRETINA.cpp $(SRC_DIR)/Unpack.cpp

JSON_INC = $(INC_DIR)/json

.PHONY: all clean

all: $(GRETINA_LIB) $(S800_LIB) $(GRET_EXE) $(HFC_EXE) $(SORT_OBJ) $(SORT_EXE) 

Debug: $(GRETINA_LIB) $(S800_LIB) $(GRET_EXE) $(HFC_EXE) $(SORT_OBJ) $(SORT_EXE)

#The main unpack executable should be built by the library and the extra files
$(GRET_EXE): $(GRET_SRC)
	@printf "\nLinking unpackGRETINA\n"
	$(CXX)  $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS) $(PROF_FLAG) $(GRETINA_LD_FLAG) $(S800_LD_FLAG)

# Create library
$(GRETINA_LIB): GRETINADict.cxx $(LIB_SRC)
	@printf "\nLinking GRETINA Library\n"
	$(CXX) -shared -o $@ $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) $(PROF_FLAG)

# Create dictionary
$(BIN_DIR)/GRETINADict.cxx: $(DICT_H) $(INC_DIR)/LinkDefGRETINA.h
	@printf "\nGenerating GRETINA dictionary $@\n"
#	rootcling -f $@ -rml $(GRETINA_LIB) -rmf libGRETINADict.rootmap $^ $(PROF_FLAG)
	rootcling -f $@ -rmf libGRETINADict.rootmap $^ $(PROF_FLAG)

# Call Makefile from hfc directory
$(HFC_EXE):
	cd src/hfc && $(MAKE)

$(S800_LIB): $(S800_LIB_SRC)
	@printf "\nLinking S800 Library\n"
	$(CXX) -shared -o $@ $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) $(PROF_FLAG)

$(BIN_DIR)/S800Dict.cxx : $(INC_DIR)/S800Parameters.h $(INC_DIR)/LinkDefS800.h
	@printf "\nGenerating s800 dictionary $@\n"
#	rootcling -f $@ -rml $(S800_LIB) -rmf libGRETINADict.rootmap $^ $(PROF_FLAG)
	rootcling -f $@ -rmf libGRETINADict.rootmap $^ $(PROF_FLAG)


$(SORT_EXE): $(SORT_SRC)
	@printf "\nBuilding goddessSort executable\n"
	$(CXX) -o $@ $(CXXFLAGS) -I$(JSON_INC) $(LDFLAGS) $^ $(LDLIBS) $(PROF_FLAG) $(GRETINA_LD_FLAG)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) -I$(JSON_INC) $^ -o $@ $(PROF_FLAG)

(OBJ_DIR):
	mkdir -p $@

cleanDebug: clean

clean:
	@$(RM) *.o *.d *.so *.pcm *.d *.rootmap GRETINADict.cxx $(GRET_EXE) $(HFC_EXE) $(SORT_EXE) $(S800_LIB) $(BIN_DIR)/GRETINADict.cxx $(BIN_DIR)/S800Dict.cxx
	cd src/hfc && make clean


