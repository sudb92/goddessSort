#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(GoddessSort)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -D_FILE_OFFSET_64")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")

#Find ROOT
find_package(ROOT REQUIRED)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")
include_directories(${ROOT_INCLUDE_DIR})
link_directories(${ROOT_LIBRARY_DIR})

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB json_source ${PROJECT_SOURCE_DIR}/src/jsoncpp.cpp)
file(GLOB orruba_sources src/UnpackORRUBA.cpp src/Calibrations.cpp src/ProcessBB10.cpp src/ProcessIC.cpp src/ProcessQQQ5.cpp src/ProcessSX3.cpp src/RunList.cpp src/Utilities.cpp)

# Building GRETINADict and libGRETINA
ROOT_GENERATE_DICTIONARY(GRETINADict ${CMAKE_CURRENT_SOURCE_DIR}/include/GRETINA.h ${CMAKE_CURRENT_SOURCE_DIR}/include/SortingStructures.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/GRETINAWavefunction.h ${CMAKE_CURRENT_SOURCE_DIR}/include/INLCorrection.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Histos.h ${CMAKE_CURRENT_SOURCE_DIR}/include/Track.h LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/include/LinkDefGRETINA.h)
add_library(GRETINA SHARED GRETINADict ${CMAKE_CURRENT_SOURCE_DIR}/src/GRETINA.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/SortingStructures.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/SuperPulse.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/INLCorrection.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/G3Waveform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Histos.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Track.cpp)
target_link_libraries(GRETINA ${ROOT_LIBRARIES})

file(GLOB gretina_sources src/UnpackGRETINARaw.cpp src/Globals.cpp src/UnpackUtilities.cpp src/S800Functions.cpp)

#----------------------------------------------------------------------------
# Add the executable, and link it to the libraries
#
add_executable(goddessSort src/Unpack.cpp ${orruba_sources} ${json_source} src/UnpackGRETINA.cpp)
target_link_libraries(goddessSort ${ROOT_LIBRARIES})

add_executable(goddessSortGRETINA ${gretina_sources})
target_link_libraries(goddessSortGRETINA ${ROOT_LIBRARIES} GRETINA)

add_executable(GEB_HFC ${CMAKE_CURRENT_SOURCE_DIR}/src/hfc/GEB_HFC.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/hfc/HFC.cpp)

#
# Copy over files to the build directory
#
set(_SCRIPTS
    config.json
    QQQ5Angles.dat
    QQQ5DownCalibrations.dat
    QQQ5DownPedestals.dat
    QQQ5UpCalibrations.dat
    QQQ5UpPedestals.dat
    SuperX3UpCalibrations.dat
    SuperX3UpPedestals.dat

    crmat.dat
    gretina.set
    track.chat
    gretinaCalibrations/gCalibration.dat
    gretinaCalibrations/segmentCenters.dat
)
foreach(_script ${_SCRIPTS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY
)
endforeach()
