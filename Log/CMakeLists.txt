cmake_minimum_required(VERSION  3.8)



project(Log)



include(LoadQtConfig)

set(INC_LIST
	"include/log_global.h" 
	"include/log.h"

			  
)
set(SRC_LIST 
	"src/log.cpp"
 
 
 )




#add_definitions(-DCOMMON_LIB)

#find_package(Qt5 REQUIRED COMPONENTS Core)



add_library(${PROJECT_NAME} SHARED ${INC_LIST} ${SRC_LIST})

include(OutPutDirConfig)


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/log4cpp/include)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/log4cpp/lib/Debug/log4cpp)
else()
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/log4cpp/lib/RelWithDebInfo/log4cpp)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)



target_compile_definitions(${PROJECT_NAME} PRIVATE LOG_LIB)