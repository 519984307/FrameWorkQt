cmake_minimum_required(VERSION  3.8)



project(Common)



include(LoadQtConfig)

set(INC_LIST
	"include/common_global.h" 
    "include/commonstruct.h"
	"include/singleton.h"

			  
)
set(SRC_LIST 

 
 
 )

set(RES_LIST 
	
)


#add_definitions(-DCOMMON_LIB)

#find_package(Qt5 REQUIRED COMPONENTS Core)


add_library(${PROJECT_NAME} SHARED ${INC_LIST} ${SRC_LIST} ${RES_LIST})

include(OutPutDirConfig)

target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)


target_compile_definitions(${PROJECT_NAME} PRIVATE COMMON_LIB)