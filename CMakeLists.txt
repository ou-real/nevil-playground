cmake_minimum_required(VERSION 2.8.0)

project(nevil)

add_definitions(-g)
add_definitions(-std=c++0x)

add_subdirectory(include/enki)
link_directories (${enki_BINARY_DIR})
include_directories(${enki_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*)
file(GLOB OBJECTS_SOURCES ${CMAKE_SOURCE_DIR}/src/objects/*)

set(QT_USE_QTOPENGL TRUE)
find_package(Qt4)
if (QT4_FOUND)
  find_package(OpenGL REQUIRED)
  include(${QT_USE_FILE})
  add_definitions(${QT_DEFINITIONS})
  add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${OBJECTS_SOURCES})
  target_link_libraries(${CMAKE_PROJECT_NAME} enki enkiviewer ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
endif (QT4_FOUND)

