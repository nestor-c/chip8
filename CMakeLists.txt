cmake_minimum_required(VERSION 3.14)

project("chip8 Emulator")

#add_executable(Test_Speaker "src/Unit Tests/Speaker_Test.cpp" "src/Speaker.cpp")
#add_executable(Test_Keyboard "src/test.cpp" "src/Renderer.cpp" "src/Renderer.h")
add_executable(Test_Renderer "src/Unit Tests/Renderer_Test.cpp" "src/Renderer.cpp" "src/headers/Renderer.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
#set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -v")

if(APPLE)
    find_package(SDL2 REQUIRED COMPONENTS SDL2 PATH "dependencies/OS X/SDL2.framework")
endif()

#target_link_libraries(Test_Speaker PUBLIC SDL2::SDL2)
#target_link_libraries(Test_Keyboard PUBLIC SDL2::SDL2)
target_link_libraries(Test_Renderer PUBLIC SDL2::SDL2)