project("chip8 Emulator")

add_executable(chip8 "src/Renderer.cpp" "src/Renderer.h" "src/test.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

if(APPLE)
    find_library(SDL2_LIBS SDL2 SDL2main "dependencies/OS X/SDL2.framework/Versions/A/Lib")
elseif(WIN32)
    find_library(SDL2_LIBS SDL2 SDL2main "dependencies/WIN32/SDL2.framework/Versions/A/Lib")
endif()

target_link_libraries(chip8 PUBLIC ${SDL2_LIBS})

if(APPLE)
    target_include_directories(chip8 PUBLIC "dependencies/OS X/SDL2.framework/Versions/A/Headers")
elseif(WIN32)
    target_include_directories(chip8 PUBLIC "dependencies/WIN32/SDL2.framework/Versions/A/Headers")
endif()
