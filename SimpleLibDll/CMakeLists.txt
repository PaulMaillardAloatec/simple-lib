include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(SimpleLibDll SHARED
    "src/SimpleLibDll.cpp"
    "include/SimpleLibDll.h"
    "include/export.h"
)

target_include_directories(SimpleLibDll
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET SimpleLibDll PROPERTY CXX_STANDARD 20)
endif()

if (WIN32)
    target_compile_definitions(SimpleLibDll PRIVATE SIMPLELIBDLL_EXPORTS)
endif()


configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/SimpleLibConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/alib-simple-lib
)

install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/SimpleLibConfig.cmake"
    DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/alib-simple-lib"
)

# Installation de la DLL + .lib
install(TARGETS SimpleLibDll
    EXPORT SimpleLibTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Installation des headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Export du package CMake
install(EXPORT SimpleLibTargets
    FILE SimpleLibTargets.cmake
    NAMESPACE SimpleLib::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/alib-simple-lib
)