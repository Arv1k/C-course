cmake_minimum_required(VERSION 3.13)
project(game_sfml)

set(CMAKE_CXX_STANDARD 14)

#set(SFML_ROOT "путь_к_sfml")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/Modules)

find_package(SFML REQUIRED COMPONENTS graphics window system)
include_directories(${SFML_INCLUDES})

add_executable(game_sfml main.cpp)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})




