cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

project( main  )
include_directories(./)
file(GLOB SOURCES "main.cpp" 
					)

file(GLOB STATICLIBS "dynsocc/cvplayer/impl/player/*.cpp"
					"dynsocc/fundamental/impl/number/*.cpp"
					"dynsocc/fundamental/impl/statemachine/*.cpp"
					"dynsocc/fundamental/impl/soccer/*.cpp"
					"dynsocc/fundamental/impl/test/*.cpp"
					"dynsocc/util/*.cpp"
					"dynsocc/test/state_machine/switcher/*.cpp"
					"dynsocc/test/state_machine/*.cpp" )					

add_executable( main ${SOURCES} )
add_library(libdynsocc STATIC ${STATICLIBS})

TARGET_LINK_LIBRARIES(main libdynsocc)