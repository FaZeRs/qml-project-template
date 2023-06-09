set(QUICK_FILES
    keysequenceeditor.h
    keysequenceeditor.cpp)

qt_add_library(quick_widgets STATIC)
qt_add_qml_module(quick_widgets
    URI QuickWidgets
    VERSION 1.0
    SOURCES ${QUICK_FILES}
    RESOURCE_PREFIX /
)

target_link_system_libraries(quick_widgets PRIVATE
    spdlog::spdlog
    Qt::Core
    Qt::Quick)

