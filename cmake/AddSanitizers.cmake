set(SANITIZE_MEMORY "FALSE" CACHE BOOL "Enable sanitizer for memory - cannot be used with thread sanitizer")
set(SANITIZE_THREAD "FALSE" CACHE BOOL "Enable sanitizer for thread - cannot be used with memory saniziter")

if(SANITIZE_MEMORY)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fsanitize=leak -fsanitize=undefined")
endif()

if(SANITIZE_THREAD)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=thread")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -ltsan")
endif()

if(SANITIZE_THREAD AND SANITIZE_MEMORY)
    message(FATAL_ERROR "Cannot enable both SANITIZE_THREAD and SANITIZE_MEMORY!")
endif()
