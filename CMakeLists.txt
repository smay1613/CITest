cmake_minimum_required(VERSION 2.8)

project(PlaylistParser)
find_package(Boost REQUIRED COMPONENTS regex filesystem)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "main.cpp"
                               "PlaylistProcessingNodes.cpp"
                               "PlaylistProcessorImpl.h"
                               "PlaylistProcessor.cpp")
set(CMAKE_CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
