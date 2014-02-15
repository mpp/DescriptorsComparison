cmake_minimum_required(VERSION 2.8)
project(settingsgenerator)

cmake_policy(SET CMP0015 NEW)

SET(CMAKE_BUILD_TYPE Debug)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    -Wno-deprecated
)

message("Project ${PROJECT_NAME} build Type: ${CMAKE_BUILD_TYPE}")

FIND_PACKAGE( Boost REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

find_package( OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIR})
link_directories ( ${OpenCV_LIBS})

add_executable(settingsgenerator
               src/SettingsGenerator/settingsgenerator.cpp
               src/SettingsGenerator/yamlparameterizedobject.cpp
               src/SettingsGenerator/yamlobjectscreationstrategy.cpp
               src/main.cpp)

target_link_libraries(settingsgenerator  ${OpenCV_LIBS} ${Boost_LIBRARIES} )

install(TARGETS settingsgenerator RUNTIME DESTINATION bin)
