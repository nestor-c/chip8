cmake_minimum_required(VERSION 3.14)
# if (APPLE)
#     set (CMAKE_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk")
# endif()
project("chip8 Emulator")

add_executable(myEmulator "src/chip8.cpp" "src/cpu.cpp" "src/keyboard.cpp" "src/Renderer.cpp" "src/Speaker.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
#set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -v")

if(APPLE)
    find_package(SDL2 REQUIRED COMPONENTS SDL2)
    target_link_libraries(myEmulator PRIVATE SDL2::SDL2)
endif()

target_link_libraries(myEmulator PUBLIC SDL2::SDL2)