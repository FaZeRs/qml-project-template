set(ENABLE_CLANG_TIDY FALSE CACHE BOOL "clang tidy messages")

if(ENABLE_CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=-*,readability-*")
endif()