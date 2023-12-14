# Based on guide here: https://stackoverflow.com/questions/30573481/how-to-write-a-makefile-with-separate-source-and-header-directories
# run it as `make -f Makefile PROF_FLAG=-pg to profile using gprof

CXX=g++

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := lib
BIN_DIR := .

CXXFLAGS := -g -fPIC -I$(INC_DIR) -MMD -MP
ROOTCFLAGS :=  `root-config --cflags`
LDFLAGS := `root-config --ldflags`
LDLIBS := `root-config --libs`

CXXFLAGS += $(ROOTCFLAGS)

# Headers explicitly passed to generate dictionary
DICT_H := $(INC_DIR)/GRETINA.h $(INC_DIR)/SortingStructures.h $(INC_DIR)/GRETINAWavefunction.h $(INC_DIR)/INLCorrection.h $(INC_DIR)/Histos.h $(INC_DIR)/Track.h $(INC_DIR)/Utilities.h

# Sources and objects for library
LIB_SRC := $(SRC_DIR)/GRETINA.cpp $(SRC_DIR)/SortingStructures.cpp $(SRC_DIR)/SuperPulse.cpp $(SRC_DIR)/INLCorrection.cpp $(SRC_DIR)/G3Waveform.cpp $(SRC_DIR)/Histos.cpp $(SRC_DIR)/Track.cpp $(SRC_DIR)/Utilities.cpp

# Sources for unpackGRETINA
GRET_SRC := $(SRC_DIR)/UnpackGRETINARaw.cpp $(SRC_DIR)/Globals.cpp $(SRC_DIR)/UnpackUtilities.cpp

GRET_EXE := $(BIN_DIR)/unpackGRETINA

GRETINA_LIB = $(BIN_DIR)/libGRETINA.so

GRETINA_LD_FLAG = -L$(BIN_DIR)/ -lGRETINA -Wl,-rpath $(BIN_DIR)/

HFC_EXE := $(BIN_DIR)/GEB_HFC

SORT_EXE := $(BIN_DIR)/goddessSort

SORT_SRC := $(SRC_DIR)/Calibrations.cpp $(SRC_DIR)/ProcessBB10.cpp $(SRC_DIR)/ProcessIC.cpp $(SRC_DIR)/ProcessQQQ5.cpp $(SRC_DIR)/ProcessSX3.cpp $(SRC_DIR)/RunList.cpp $(SRC_DIR)/UnpackORRUBA.cpp $(SRC_DIR)/Utilities.cpp $(SRC_DIR)/jsoncpp.cpp $(SRC_DIR)/UnpackGRETINA.cpp $(SRC_DIR)/Unpack.cpp

JSON_INC = $(INC_DIR)/json

.PHONY: all clean

all: $(GRET_EXE) $(HFC_EXE) $(SORT_OBJ) $(SORT_EXE)

Debug: $(GRETINA_LIB) $(GRET_EXE) $(HFC_EXE) $(SORT_OBJ) $(SORT_EXE)

#The main unpack executable should be built by the library and the extra files
$(GRET_EXE): $(GRET_SRC)  $(GRETINA_LIB)
	@echo "Linking main executable"
	$(CXX)  $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS) $(PROF_FLAG)

# Create library
$(GRETINA_LIB): GRETINADict.cxx $(LIB_SRC)
	@echo "Linking GRETINA Library"
	$(CXX) -shared -o $@ $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) $(PROF_FLAG)

# Create dictionary
$(BIN_DIR)/GRETINADict.cxx: $(DICT_H) $(INC_DIR)/LinkDefGRETINA.h
	@echo "Generating dictionary $@"
	@rootcling -f $@ -rml $(GRETINA_LIB) -rmf libGRETINADict.rootmap $^ $(PROF_FLAG)

# Call Makefile from hfc directory
$(HFC_EXE):
	cd src/hfc && $(MAKE)

$(SORT_EXE): $(SORT_SRC)
	@echo "Building goddessSort executable"
	$(CXX) -o $@ $(CXXFLAGS) -I$(JSON_INC) $(LDFLAGS) $(GRETINA_LD_FLAG) $^ $(GRETINA_LIB) $(LDLIBS) $(PROF_FLAG)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) -I$(JSON_INC) $^ -o $@ $(PROF_FLAG)

(OBJ_DIR):
	mkdir -p $@

cleanDebug: clean

clean:
	@$(RM) *.o *.d *.so *.pcm *.d *.rootmap GRETINADict.cxx $(GRET_EXE) $(HFC_EXE) $(SORT_EXE)
	cd src/hfc && make clean


