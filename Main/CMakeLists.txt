cmake_minimum_required (VERSION 3.8)


project(Main)


include(LoadQtConfig)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(INC_LIST 
	"../UI/include/singleapplication.h")



set(SRC_LIST 
	"../UI/src/singleapplication.cpp"
	src/main.cpp)



add_executable(${PROJECT_NAME} ${INC_LIST}  ${SRC_LIST})

include(OutPutDirConfig)


message(STATUS "Link libraries:${OUTPUT_DIR}")

message(STATUS "Qt5::Core:  ${Qt5Core_INCLUDE_DIRS}")
target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets 
												Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Network)


target_link_directories(${PROJECT_NAME} PRIVATE ${OUTPUT_DIR})















