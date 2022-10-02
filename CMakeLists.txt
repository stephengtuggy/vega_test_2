cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(vega_test_2)

set(CMAKE_CXX_STANDARD 11)

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_definitions("BOOST_ALL_DYN_LINK"
        "$<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>"
        "$<$<CXX_COMPILER_ID:MSVC>:_CRT_NONSTDC_NO_DEPRECATE>")

FIND_PACKAGE(Boost REQUIRED)

add_executable(vega_test_2 main.cpp unit.cpp unit.hpp unit_collection.hpp flightgroup.cpp flightgroup.hpp)

target_include_directories(vega_test_2 PRIVATE ${Boost_INCLUDE_DIRS})
