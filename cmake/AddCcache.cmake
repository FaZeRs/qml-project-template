set(ENABLE_CCACHE TRUE CACHE BOOL "Enable Ccache")

if(ENABLE_CCACHE)
  find_program(CCACHE_EXECUTABLE NAMES ccache)

  if(CCACHE_EXECUTABLE)
    message(STATUS "ccache found: will be used for compilation and linkage")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_EXECUTABLE})
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_EXECUTABLE})
  endif()
endif()