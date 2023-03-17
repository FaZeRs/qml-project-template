cmake_minimum_required(VERSION 3.16...3.22)

include(cmake/AddCcache.cmake)
include(cmake/AddVersion.cmake)

project(RoomSketcher
  VERSION ${VERSION_SHORT}
  DESCRIPTION "Floor Plan Editor"
  HOMEPAGE_URL "https://giraffe360.com"
  LANGUAGES CXX)

include(cmake/AddCompilationFlags.cmake)
include(cmake/AddSanitizers.cmake)
include(cmake/AddCodeCoverage.cmake)
include(cmake/AddClangTidy.cmake)
include(cmake/AddDependencies.cmake)
include(cmake/AddSourceFiles.cmake)
include(cmake/AddQtFiles.cmake)
include(cmake/AddExecutable.cmake)
include(cmake/AddInstallTargets.cmake)
include(cmake/AddCPack.cmake)
include(cmake/AddTests.cmake)

message(STATUS "Version: ${PROJECT_VERSION}")
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
