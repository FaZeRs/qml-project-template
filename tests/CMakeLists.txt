cmake_minimum_required(VERSION 3.5)

project(unit_tests LANGUAGES CXX)

add_executable(unit_tests tst_mytest.cpp)
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
