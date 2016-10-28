cmake_minimum_required(VERSION 2.6)
project(chechugame)

add_subdirectory(module/alligator/)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -g -ftest-coverage -fprofile-arcs")

file(GLOB_RECURSE CPPs src/core/*.cpp)
file(GLOB_RECURSE HPPs src/core/*.h)

include_directories(module/alligator/src)

set(SOURCES ${CPPs} ${HPPs})

if(WIN32)
	list(APPEND CMAKE_EXE_LINKER_FLAGS "-static-libstdc++ -static-libgcc")
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin/win32)
elseif(UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin/linux)
endif()

# add a new target with allegro, alligator and core sources. uses monolith for win32
function(add_alleg_target EXEC-NAME SRCS)
	add_executable(${EXEC-NAME} ${SOURCES} ${SRCS})
	target_link_libraries(${EXEC-NAME} alligator)
	target_include_directories(${EXEC-NAME} PUBLIC module/alligator/src)
	set_target_properties(${EXEC-NAME} PROPERTIES
		COMPILE_FLAGS "-std=c++11"
		LINK_FLAGS "-g -ftest-coverage -fprofile-arcs"
		)
	if(WIN32)
		target_link_libraries(${EXEC-NAME} allegro_monolith)
	elseif(UNIX)
		target_link_libraries(${EXEC-NAME} allegro)
		target_link_libraries(${EXEC-NAME} allegro_image)
		target_link_libraries(${EXEC-NAME} allegro_primitives)
		target_link_libraries(${EXEC-NAME} allegro_font)
		target_link_libraries(${EXEC-NAME} allegro_ttf)
		target_link_libraries(${EXEC-NAME} allegro_audio)
		target_link_libraries(${EXEC-NAME} allegro_acodec)
	else()
		message(SEND_FATAL "Unknown platform")
	endif()
endfunction(add_alleg_target)

add_alleg_target(game src/game/main.cpp)
