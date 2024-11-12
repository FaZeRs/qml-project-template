cmake_minimum_required(VERSION 3.27)

project(unit-tests LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Test)

add_executable(unit-tests tst_settings.cpp)

cpmaddpackage(
  NAME
  Catch2
  VERSION
  3.6.0
  GITHUB_REPOSITORY
  catchorg/Catch2
  SYSTEM
  YES)

target_link_libraries(unit-tests PRIVATE libs::project_warnings libs::project_options libs::core)

target_link_system_libraries(
  unit-tests
  PRIVATE
  Qt::Core
  Qt::Test
  Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(unit-tests)
