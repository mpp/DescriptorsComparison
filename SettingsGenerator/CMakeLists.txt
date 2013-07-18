cmake_minimum_required(VERSION 2.8)
project(settingsgenerator)

cmake_policy(SET CMP0015 NEW)

set(CMAKE_BUILD_TYPE "Debug")

message("Project ${PROJECT_NAME} build Type: ${CMAKE_BUILD_TYPE}")

FIND_PACKAGE( Boost REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

find_package( OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIR})
link_directories ( ${OpenCV_LIBS})

add_executable(settingsgenerator settingsgenerator.cpp main.cpp)

target_link_libraries(settingsgenerator  ${OpenCV_LIBS} ${Boost_LIBRARIES} )

install(TARGETS settingsgenerator RUNTIME DESTINATION bin)