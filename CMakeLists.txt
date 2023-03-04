cmake_minimum_required(VERSION 3.22)

project(RoomSketcher
  VERSION 1.0.0
  DESCRIPTION "Floor Plan Editor"
  HOMEPAGE_URL "https://giraffe360.com"
  LANGUAGES CXX)

include(cmake/AddCompilationFlags.cmake)
include(cmake/AddSanitizers.cmake)
include(cmake/AddCodeCoverage.cmake)
include(cmake/AddCcache.cmake)
include(cmake/AddDependencies.cmake)
include(cmake/AddSourceFiles.cmake)
include(cmake/AddQtFiles.cmake)
include(cmake/AddExecutable.cmake)
include(cmake/AddInstallTargets.cmake)
include(cmake/AddCPack.cmake)
include(cmake/AddTests.cmake)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Release cxx: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "Debug cxx: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS " ")

if(BUILD_TYPE STREQUAL "release")
  message(STATUS "Complete cxx: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
  message(STATUS "Complete ld: ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
else()
  message(STATUS "Complete cxx: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
  message(STATUS "Complete ld: ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_DEBUG}")
endif()
