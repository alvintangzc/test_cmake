cmake_minimum_required(VERSION 3.0)
project (test_cmake)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE DEBUG)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(Boost REQUIRED)
find_package(Spdlog REQUIRED)

# check if boost was found
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

if(Spdlog_FOUND)
    message ("spdlog found")
else()
    message (FATAL_ERROR "Cannot find spdlog")
endif()


include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Spdlog_INCLUDE_DIRS})

aux_source_directory(. DIR_SRCS)
add_executable(test_cmake ${DIR_SRCS})
target_link_libraries(test_cmake
    PRIVATE
    ${Boost_LIBRARIES}
    ${Spdlog_LIBRARIES})

