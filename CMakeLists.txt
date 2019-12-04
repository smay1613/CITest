cmake_minimum_required(VERSION 3.0)

project(HomeworkProject VERSION 1.0.0)

set(sources
    "src/impl.cpp"
)

set(headers
    "src/impl.h")

set(BUILDDIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(TEST true)

add_library(HomeworkProject SHARED ${sources})

set_target_properties(HomeworkProject PROPERTIES
                        C_STANDARD 11
                        CXX_STANDARD 11
                        PUBLIC_HEADER "${headers}"
)

target_compile_options(HomeworkProject PRIVATE -Wall -Wextra)

target_include_directories(HomeworkProject
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILDDIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILDDIR}/bin)

if (TEST)
    message("TESTING ENABLED")
    add_subdirectory(tests)
endif()
