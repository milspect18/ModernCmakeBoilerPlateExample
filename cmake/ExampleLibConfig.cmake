get_filename_component(ExampleLib_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

if(NOT TARGET ExampleLib::ExampleLib)
    include("${ExampleLib_CMAKE_DIR}/ExampleLibTargets.cmake")
endif()