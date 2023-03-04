SET(COMPILE_TESTS TRUE CACHE BOOL "Compile tests")

if(COMPILE_TESTS)
    add_subdirectory(tests)
endif()
