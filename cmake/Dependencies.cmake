function(setup_dependencies)
    find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)

    if(USE_SENTRY AND NOT TARGET sentry::sentry)
        CPMAddPackage(
            NAME sentry
            VERSION 0.7.6
            GITHUB_REPOSITORY getsentry/sentry-native
            GIT_TAG "0.7.6"
            OPTIONS "SENTRY_INTEGRATION_QT ON" "SENTRY_BUILD_TESTS OFF" "SENTRY_BUILD_EXAMPLES OFF"
            SYSTEM YES
        )
    endif()

    if(USE_SPDLOG AND NOT TARGET spdlog::spdlog)
        CPMAddPackage(
            NAME spdlog
            VERSION 1.14.1
            GITHUB_REPOSITORY gabime/spdlog
            SYSTEM YES
        )
    endif()
endfunction()
