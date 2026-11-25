cmake_minimum_required(VERSION 3.28)

project(strugglers_descent VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui)

# source files
add_executable(${PROJECT_NAME} 
    src/main.cpp
)

# include directories for header files and third parties
target_include_directories(${PROJECT_NAME} PRIVATE
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(imgui PUBLIC SDL3::SDL3)

add_subdirectory(third_party/SDL3)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3) 