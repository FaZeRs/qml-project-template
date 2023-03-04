include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "IFW")
set(CPACK_PACKAGE_NAME "RoomSketcher")
set(CPACK_PACKAGE_FILE_NAME "installer")
set(CPACK_PACKAGE_VENDOR "Giraffe360")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Room Sketcher - Floor Plan Editor")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_VERBATIM_VARIABLES ON)
set(CPACK_PACKAGE_INSTALL_DIRECTORY "RoomSketcher")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Nauris Linde <naurislinde@gmail.com>")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libstdc++6, libgcc-s1")

set (CPACK_IFW_PACKAGE_NAME "RoomSketcher")
set (CPACK_IFW_PACKAGE_TITLE "RoomSketcher Installer")
set (CPACK_IFW_PACKAGE_PUBLISHER "Giraffe360")
set (CPACK_IFW_PACKAGE_WIZARD_STYLE "Modern")
set (CPACK_IFW_PACKAGE_WIZARD_SHOW_PAGE_LIST OFF)

include(CPack)
include(CPackIFW)
