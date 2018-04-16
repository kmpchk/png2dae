cmake_minimum_required(VERSION 3.10)
project(png2dae)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.58.0 COMPONENTS system filesystem program_options REQUIRED)
find_package(ImageMagick COMPONENTS Magick++)
find_package(OpenCV REQUIRED)
find_package(Assimp REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

if(Assimp_FOUND)

    include_directories(${Assimp_INCLUDE_DIRS})

endif()

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

if(ImageMagick_FOUND)

    include_directories(${ImageMagick_INCLUDE_DIRS})

endif()

if(OpenCV_FOUND)

    include_directories(${OpenCV_INCLUDE_DIRS})

endif()


add_executable(png2dae src/main.cpp src/texture.h src/MeshLoader.h src/utils.h src/utils.cpp src/types.h src/png2stl.h src/png2stl.cpp src/heightmap.h src/heightmap.cpp src/stb_image.cpp src/stb_image.h src/libtrix.cpp src/libtrix.h src/MeshLoader.cpp)

target_link_libraries(png2dae glfw)

target_link_libraries(png2dae ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

if(Assimp_FOUND)

    target_link_libraries(png2dae ${Assimp_LIBRARIES})

endif()

if(Boost_FOUND)

    target_link_libraries(png2dae ${Boost_LIBRARIES})

endif()

if(ImageMagick_FOUND)

    target_link_libraries(png2dae ${ImageMagick_LIBRARIES})

endif()

if(OpenCV_FOUND)

    target_link_libraries(png2dae ${OpenCV_LIBRARIES})

endif()