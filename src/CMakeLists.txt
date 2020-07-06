# src dir CMakeLists
cmake_minimum_required(VERSION 3.1...3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Building our utils library
set(UTIL_SRC Utilities.cpp)
set(UTIL_HDR ${PROJECT_INCLUDE_DIR}/Utilities.hpp)

add_library(ExampleLib SHARED ${UTIL_SRC} ${UTIL_HDR})
target_compile_features(ExampleLib PUBLIC cxx_std_17)
target_include_directories(
    ExampleLib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_INCLUDE_DIR}>
)

# Export / Install
# Ensure that the install dirs are as expected for GNU sys
include(GNUInstallDirs)

# Generate the cmake exports that will make client importing easy
install(
    TARGETS ExampleLib
    EXPORT  ExampleLib-export
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install the targets and use namespace
install(
    EXPORT  ExampleLib-export
    FILE    ExampleLibTargets.cmake
    NAMESPACE   ExampleLib::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ExampleLib
)

# Install our cmake config for client importing
install(
    FILES   ${CMAKE_MODULE_PATH}/ExampleLibConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ExampleLib
)

# Install the public header files for the library
install(
    FILES   ${UTIL_HDR}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
