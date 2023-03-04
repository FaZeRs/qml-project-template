project(gui_tests LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(gui_tests main.cpp tst_mytest.cpp)
add_test(NAME gui_tests COMMAND gui_tests)

target_link_libraries(gui_tests PRIVATE Catch2::Catch2 Qt::Core Qt::Gui Qt::Widgets)