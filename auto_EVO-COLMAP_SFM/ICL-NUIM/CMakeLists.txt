cmake_minimum_required(VERSION 3.0.2)
Project(Evoluation)

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

MESSAGE("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall  -O3 -march=native ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O3 -march=native")

# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    add_definitions(-DCOMPILEDWITHC11)
    message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    add_definitions(-DCOMPILEDWITHC0X)
    message(STATUS "Using flag -std=c++0x.")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
# Check C++11 or C++0x support




find_package(OpenCV 4.0)
if(NOT OpenCV_FOUND)
  find_package(OpenCV 3.0)
  if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV > 3.0 not found.")
  endif()
endif()

MESSAGE("OPENCV VERSION:")
MESSAGE(${OpenCV_VERSION})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/)

find_package(COLMAP REQUIRED)

link_directories(${COLMAP_LINK_DIRS})

include_directories(
${PROJECT_SOURCE_DIR}
${COLMAP_INCLUDE_DIRS}
)


add_executable(convertor
${PROJECT_SOURCE_DIR}/src/convertor.cc
)
target_link_libraries(convertor
${COLMAP_LIBRARIES}
colmap
)

add_executable(prepare
${PROJECT_SOURCE_DIR}/src/prepare.cc
)

add_executable(sfm
${PROJECT_SOURCE_DIR}/src/sfm.cc
)
target_link_libraries(sfm
${COLMAP_LIBRARIES}
colmap
)



add_executable(sort
${PROJECT_SOURCE_DIR}/src/sort.cc
)


add_executable(tracking_Rate
${PROJECT_SOURCE_DIR}/src/tracking_Rate.cc
)

