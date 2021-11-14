cmake_minimum_required(VERSION 3.16)
project(Lesson_32_1)


set(CMAKE_CXX_STANDARD 20)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Lesson_32_1 main.cpp)
target_link_libraries(Lesson_32_1 PRIVATE nlohmann_json::nlohmann_json)