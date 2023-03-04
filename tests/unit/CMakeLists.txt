project(unit_tests LANGUAGES CXX)

add_executable(unit_tests main.cpp tst_mytest.cpp)
add_test(NAME unit_tests COMMAND unit_tests)

target_link_libraries(unit_tests PRIVATE Catch2::Catch2)