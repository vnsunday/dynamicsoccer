cmake_minimum_required(VERSION 2.8.9)
project (dynamic_soccer)

include_directories(src)
file(GLOB SOURCES "src/*.cpp" 
            "src/app/application/*.cpp"
            "src/app/cvplayer/impl/player/*.cpp"
            "src/app/fundamental/impl/number/*.cpp"
            "src/app/fundamental/impl/statemachine/*.cpp"
            "src/app/fundamental/impl/test/*.cpp"
            "src/app/test/*.cpp"
            "src/app/util/*.cpp" )

add_executable(hello ${SOURCES})
