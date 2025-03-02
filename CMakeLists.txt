cmake_minimum_required(VERSION 3.16)

project(sdl_circle LANGUAGES CXX)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2PP REQUIRED)

set(SDL_LINK_LIBRARIES
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    ${SDL2PP_LIBRARIES}
)

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${SDL2PP_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${SDL_LINK_LIBRARIES})
