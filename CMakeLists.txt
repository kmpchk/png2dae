cmake_minimum_required(VERSION 3.10)
project(png2dae)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.58.0 COMPONENTS system filesystem REQUIRED)
find_package(ImageMagick COMPONENTS Magick++)
find_package(OpenCV REQUIRED)

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

add_executable(png2dae src/main.cpp)


if(Boost_FOUND)

    target_link_libraries(png2dae ${Boost_LIBRARIES})

endif()

if(ImageMagick_FOUND)

    target_link_libraries(png2dae ${ImageMagick_LIBRARIES})

endif()

if(OpenCV_FOUND)

    target_link_libraries(png2dae ${OpenCV_LIBRARIES})

endif()