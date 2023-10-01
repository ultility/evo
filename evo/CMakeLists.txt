# CMakeList.txt : CMake project for evo, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (evo "evo.cpp" "evo.h"  "DNA.h" "DNA.cpp" "codon.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET evo PROPERTY CXX_STANDARD 20)
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_custom_command(TARGET evo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/libs"
        ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET evo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/images"
        ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(evo SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)

# TODO: Add tests and install targets if needed.
