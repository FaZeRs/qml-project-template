SET(COMPILE_TESTS TRUE CACHE BOOL "Compile tests")

if(COMPILE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
