cmake_minimum_required(VERSION 3.28)

project(strugglers_descent VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third_party/SDL3)

# define imgui lib target in third_party
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui)
add_library(imgui STATIC
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp    
    ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdlrenderer3.cpp
)

target_include_directories(imgui PUBLIC
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

# link sdl3 to imgui so imgui_impl_sdl3.cpp can find sdl3 headers
target_link_libraries(imgui PUBLIC SDL3::SDL3)

# source files
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/World.cpp
    src/WorldRenderer.cpp
    src/Debug.cpp
)

# include directories for header files and third parties
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    imgui 
    SDL3::SDL3
)