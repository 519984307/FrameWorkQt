# CMakeList.txt: FrameWork 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)


project(FrameWork)

set(PROJECT_LIST  Common HelperTool UI Main)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/CMake)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(LoadQtConfig)

include(LoadC++Config)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(SYSTEM_NAME Win32)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(SYSTEM_NAME MacOS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(SYSTEM_NAME Linux)
endif()
message(STATUS "[${PROJECT_NAME}] " System:${SYSTEM_NAME})
##################### 操作平台设置
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(BUILD_PLATFORM x64)
else()
    set(BUILD_PLATFORM x86)
endif()


# default RelWithDebInfo
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
##############设置路径变量参数
set(PREFIX_DIR "Build/${SYSTEM_NAME}/${BUILD_PLATFORM}/${CMAKE_BUILD_TYPE}")

message(STATUS "[${PROJECT_NAME}] PREFIX_DIR:${PREFIX_DIR}")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Gui Network)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Gui Network)


foreach(PROJECT ${PROJECT_LIST})
message(STATUS "[****************${PROJECT}****************")
add_subdirectory(${PROJECT})
endforeach()








