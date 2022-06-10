cmake_minimum_required(VERSION 3.22)
project(LabProg)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES IniFileManager.cpp IniFileManager.h)
add_executable(LabProg main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LabProg core)