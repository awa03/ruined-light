cmake_minimum_required(VERSION 3.10)
project(RuinedLight)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 4.5.0 
)
FetchContent_MakeAvailable(raylib)

add_executable(RuinedLight src/main.cpp)

target_include_directories(RuinedLight PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(RuinedLight PRIVATE raylib)
target_link_libraries(RuinedLight PRIVATE m pthread dl GL)

