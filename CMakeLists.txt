cmake_minimum_required(VERSION 3.25)
project(TimeMeter)

set(CMAKE_CXX_STANDARD 17)

add_executable(TimeMeter main.cpp TimeMeter.h TimeMeter.cpp MembersLin.h MembersWin.h)
