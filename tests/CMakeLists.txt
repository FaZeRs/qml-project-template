include(CTest)

find_package(Catch2 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_subdirectory(gui)
add_subdirectory(unit)