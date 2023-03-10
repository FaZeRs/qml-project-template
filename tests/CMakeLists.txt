cmake_minimum_required(VERSION 3.5)

project(unit_tests LANGUAGES CXX)

add_executable(unit_tests tst_mytest.cpp)

CPMAddPackage("gh:catchorg/Catch2@3.3.2")
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
add_test(unit_tests unit_tests)