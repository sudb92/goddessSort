#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(GoddessSort)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")

#Find ROOT
find_package(ROOT REQUIRED)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")
include_directories(${ROOT_INCLUDE_DIR})
link_directories(${ROOT_LIBRARY_DIR})

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
include_directories(include)
file(GLOB json_source ${PROJECT_SOURCE_DIR}/src/jsoncpp.cpp)
#file(GLOB json_headers ${PROJECT_SOURCE_DIR}/include/json/*.h)

file(GLOB orruba_sources src/Unpack.cpp src/Calibrations.cpp src/ProcessBB10.cpp src/ProcessIC.cpp src/ProcessQQQ5.cpp src/ProcessSX3.cpp src/RunList.cpp src/Utilities.cpp)
#file(GLOB orruba_headers ${PROJECT_SOURCE_DIR}/include/Unpack.h ${PROJECT_SOURCE_DIR}/include/Calibrations.h ${PROJECT_SOURCE_DIR}/include/ProcessBB10.h ${PROJECT_SOURCE_DIR}/include/ProcessIC.h ${PROJECT_SOURCE_DIR}/include/ProcessQQQ5.h ${PROJECT_SOURCE_DIR}/include/ProcessSX3.h ${PROJECT_SOURCE_DIR}/include/RunList.h)

#----------------------------------------------------------------------------
# Add the executable, and link it to the libraries
#
#add_executable(goddessSort ${sources} ${headers})
add_executable(goddessSort ${orruba_sources} ${json_source})
target_link_libraries(goddessSort ${ROOT_LIBRARIES})

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
        )
foreach(_script ${_SCRIPTS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY
    )
endforeach()

#
#----------------------------------------------------------------------------
# Add program to the project targets
# (this avoids the need of typing the program name after make)
#
add_custom_target(GoddessSort DEPENDS goddessSort)

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS goddessSort DESTINATION bin)
