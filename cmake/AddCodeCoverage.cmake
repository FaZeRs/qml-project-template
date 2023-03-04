set(CODE_COVERAGE "OFF" CACHE BOOL "Enable compilation of binaries with code coverage instrumentation.")

if(CODE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_C_COMPILER_ID MATCHES "GNU")
        add_compile_options(-fprofile-arcs -ftest-coverage)
        link_libraries(gcov)
    else()
        message(FATAL_ERROR "Code coverage instrumentation is only supported for GNU compilers.")
    endif()
endif()
