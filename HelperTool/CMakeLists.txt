cmake_minimum_required (VERSION 3.8)

project(HelperTool)

include(LoadQtConfig)
set(INC_LIST 
	 "include/helper_tool_global.h"
	 "include/notifyeventhelper.h"
	 "include/impfilehelper.h"
	 
	 
	 )


set(SRC_LIST 

	"src/notifyeventhelper.cpp"
	"src/impfileheper.cpp"
 )

set(RES_LIST 
	
)



add_library(${PROJECT_NAME} SHARED ${INC_LIST} ${SRC_LIST} ${RES_LIST} )

include(OutPutDirConfig)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


message(STATUS "Qt5::Core:  ${Qt6Core_INCLUDE_DIRS}")
#target_include_directories(${PROJECT_NAME} PRIVATE ${OUTPUT_DIR} ${Qt5Core_INCLUDE_DIRS})


target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(${PROJECT_NAME} PRIVATE HELPER_TOOL_LIB)