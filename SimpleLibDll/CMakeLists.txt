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