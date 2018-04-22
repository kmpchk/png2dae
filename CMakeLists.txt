cmake_minimum_required(VERSION 3.10)
project(png2dae)

set(CMAKE_CXX_STANDARD 11)

find_package(Assimp REQUIRED)

if(Assimp_FOUND)

    include_directories(${Assimp_INCLUDE_DIRS})

endif()

add_executable(png2dae src/main.cpp src/png2stl.cpp src/png2stl.h src/heightmap.cpp src/heightmap.h src/libtrix.cpp src/libtrix.h src/stb_image.cpp src/stb_image.h src/types.h src/utils.cpp src/utils.h src/png2dae.cpp src/png2dae.h src/stl2dae.h src/stl2dae.cpp)

target_link_libraries(png2dae ${ASSIMP_LIBRARIES})

if(Assimp_FOUND)

    target_link_libraries(png2dae ${Assimp_LIBRARIES})

endif()