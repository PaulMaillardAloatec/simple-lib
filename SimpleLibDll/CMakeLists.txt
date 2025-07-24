set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_library (SimpleLibDll SHARED 
    "src/SimpleLibDll.cpp" 
    "include/SimpleLibDll.h"
    "include/export.h")

target_include_directories(SimpleLibDll PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SimpleLibDll PROPERTY CXX_STANDARD 20)
endif()

if(WIN32)
    target_compile_definitions(SimpleLibDll PRIVATE SIMPLELIBDLL_EXPORTS)
endif()
target_include_directories(SimpleLibDll
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Corriger les chemins dans l'export
set_target_properties(SimpleLibDll PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "$<INSTALL_INTERFACE:include>"
)

install(TARGETS SimpleLibDll
    EXPORT SimpleLibTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT SimpleLibTargets
    FILE SimpleLibTargets.cmake
    NAMESPACE SimpleLib::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SimpleLib
)