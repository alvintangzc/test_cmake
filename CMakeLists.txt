cmake_minimum_required(VERSION 3.0)
project (test_cmake)

# set the C++ standard
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE DEBUG)

aux_source_directory(. DIR_SRCS)
add_executable(test_cmake ${DIR_SRCS})

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

add_subdirectory(thirdparty/cpr)

find_package(Boost REQUIRED)

# check if boost was found
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

target_link_libraries(test_cmake PRIVATE ${CPR_LIBRARIES} ${Boost_LIBRARIES})

target_include_directories(test_cmake PRIVATE
  thirdparty
  thirdparty/spdlog/include
  thirdparty/rapidjson/include
  ${CPR_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

