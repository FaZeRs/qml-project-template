#set(BUILD_DOCS FALSE CACHE BOOL "Build documentation using Doxygen")
#if (BUILD_DOCS)
#    find_package(Doxygen)
#    # check if Doxygen is installed
#    if(NOT DOXYGEN_FOUND)
#        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
#    endif()
#    # set input and output files
#    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
#    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#
#    # request to configure the file
#    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#    message("Doxygen build started")
#
#    # note the option ALL which allows to build the docs together with the application
#    add_custom_target(docs ALL
#            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#            COMMENT "Generating API documentation with Doxygen"
#            VERBATIM )
#endif()

# Enable doxygen doc builds of source
function(enable_doxygen DOXYGEN_THEME)
    # If not specified, use the top readme file as the first page
    if((NOT DOXYGEN_USE_MDFILE_AS_MAINPAGE) AND EXISTS "${PROJECT_SOURCE_DIR}/README.md")
        set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/README.md")
    endif()

    # set better defaults for doxygen
    set(DOXYGEN_CALLER_GRAPH YES)
    set(DOXYGEN_CALL_GRAPH YES)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    # svg files are much smaller than jpeg and png, and yet they have higher quality
    set(DOXYGEN_DOT_IMAGE_FORMAT svg)
    set(DOXYGEN_DOT_TRANSPARENT YES)

    # If not specified, exclude the vcpkg files and the files CMake downloads under _deps (like project_options)
    if(NOT DOXYGEN_EXCLUDE_PATTERNS)
        set(DOXYGEN_EXCLUDE_PATTERNS "${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed/*" "${CMAKE_CURRENT_BINARY_DIR}/_deps/*")
    endif()

    if("${DOXYGEN_THEME}" STREQUAL "")
        set(DOXYGEN_THEME "awesome-sidebar")
    endif()

    if("${DOXYGEN_THEME}" STREQUAL "awesome" OR "${DOXYGEN_THEME}" STREQUAL "awesome-sidebar")
        # use a modern doxygen theme
        # https://github.com/jothepro/doxygen-awesome-css v1.6.1
        FetchContent_Declare(_doxygen_theme
                URL https://github.com/jothepro/doxygen-awesome-css/archive/refs/tags/v2.2.0.zip)
        FetchContent_MakeAvailable(_doxygen_theme)
        if("${DOXYGEN_THEME}" STREQUAL "awesome" OR "${DOXYGEN_THEME}" STREQUAL "awesome-sidebar")
            set(DOXYGEN_HTML_EXTRA_STYLESHEET "${_doxygen_theme_SOURCE_DIR}/doxygen-awesome.css")
        endif()
        if("${DOXYGEN_THEME}" STREQUAL "awesome-sidebar")
            set(DOXYGEN_HTML_EXTRA_STYLESHEET ${DOXYGEN_HTML_EXTRA_STYLESHEET}
                    "${_doxygen_theme_SOURCE_DIR}/doxygen-awesome-sidebar-only.css")
        endif()
    else()
        # use the original doxygen theme
    endif()

    # find doxygen and dot if available
    find_package(Doxygen REQUIRED OPTIONAL_COMPONENTS dot)

    # add doxygen-docs target
    message(STATUS "Adding `doxygen-docs` target that builds the documentation.")
    doxygen_add_docs(doxygen-docs ALL ${PROJECT_SOURCE_DIR}
            COMMENT "Generating documentation - entry file: ${CMAKE_CURRENT_BINARY_DIR}/html/index.html")
endfunction()
