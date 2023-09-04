cmake_minimum_required (VERSION 3.8)


project(UI)

include(LoadQtConfig)

set(INC_LIST 
	 "include/ui_global.h"
	 "include/singleapplication.h"
	 
	 )


set(SRC_LIST 
	"src/singleapplication.cpp"
 
 
 )

set(RES_LIST 
	
)

#find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Network)


#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Gui Network)

#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Gui Network)

message(STATUS "[${PROJECT_NAME}:] [INC_LIST:] ${INC_LIST}")

message(STATUS "[${PROJECT_NAME}:] [SRC_LIST:] ${SRC_LIST}")

message(STATUS "[${PROJECT_NAME}:] [RES_LIST:] ${RES_LIST}")

#include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Network_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)


add_library(${PROJECT_NAME} SHARED ${INC_LIST} ${SRC_LIST} ${RES_LIST})

include(OutPutDirConfig)


target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/include)

#target_include_directories(${PROJECT_NAME} PRIVATE ${QtCore_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS}
#						${Qt5Gui_INCLUDE_DIRS} ${Qt5Network_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)

message(STATUS "${PROJECT_NAME}:[CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}/include]")


target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets 
												Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Network)

												
target_compile_definitions(${PROJECT_NAME} PRIVATE UI_LIB)