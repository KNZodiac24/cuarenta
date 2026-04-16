cmake_minimum_required(VERSION 3.15)

project(cuarenta VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(WIN_EXE)
set(WIN_LIBS)

if(WIN32)
    set(WIN_EXE WIN32)
    set(WIN_LIBS winmm)
endif()

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${WIN_EXE} ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -O2
)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib glfw ${WIN_LIBS})

target_include_directories(${PROJECT_NAME} PUBLIC include)
