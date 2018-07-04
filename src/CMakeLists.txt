cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

project( main  )
include_directories(./)
file(GLOB SOURCES "main.cpp" 
					"app/cvplayer/impl/player/*.cpp"
					"app/fundamental/impl/number/*.cpp"
					"app/fundamental/impl/statemachine/*.cpp"
					"app/fundamental/impl/test/*.cpp"
					"app/util/*.cpp" )

add_executable( main ${SOURCES} )