cmake_minimum_required(VERSION 3.2)
project(pilot-usboard)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -pthread")

file(GLOB GENERATED_SOURCE_FILES generated/src/*.cpp)

add_library(pilot_usboard SHARED
	${GENERATED_SOURCE_FILES}
	src/USBoardModule.cpp
	src/USBoardConfig.cpp
)

target_include_directories(pilot_usboard
	PUBLIC include generated/include
)

target_link_libraries(pilot_usboard pilot_base vnx_base)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY generated/include/ DESTINATION include)
install(DIRECTORY modules/ DESTINATION interface/pilot/usboard)
install(DIRECTORY interface/ DESTINATION interface/pilot/usboard)

install(TARGETS pilot_usboard DESTINATION lib)
