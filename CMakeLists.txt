cmake_minimum_required(VERSION 3.9)
project(adminbot)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS system thread)

add_executable(adminbot main.cpp api/discordapi.hpp api/src/discordapi.cpp parser/commandparser.hpp parser/src/commandparser.cpp)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(adminbot ${Boost_LIBRARIES})