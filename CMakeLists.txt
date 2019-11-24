cmake_minimum_required(VERSION 3.14)
project(PO)

set(CMAKE_CXX_STANDARD 14)

add_executable(PO main.cpp Transport.cpp Transport.hpp AllTypes.hpp node.cpp node.hpp transit.cpp transit.hpp internal.cpp internal.hpp international.cpp international.hpp river.cpp river.hpp sea.cpp sea.hpp nodeKeeper.cpp nodeKeeper.hpp)