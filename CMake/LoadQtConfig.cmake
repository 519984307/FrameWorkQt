

if(WIN32)
	set(QT_INSTALL_PATH "C:/Qt-6.0/6.6.0/msvc2019_64")
	message(STATUS "Qt Install Path:${QT_INSTALL_PATH}")
else()
	set(QT_INSTALL_PATH "")
	message(STATUS "Qt Install Path:${QT_INSTALL_PATH}")
endif()



set(CMAKE_AUTOMOC ON)
message(STATUS "CMAKE_AUTOMOC: ${CMAKE_AUTOMOC}")

set(CMAKE_AUTOUIC ON)
message(STATUS "CMAKE_AUTOUIC: ${CMAKE_AUTOUIC}")

set(CMAKE_AUTORCC ON)
message(STATUS "CMAKE_AUTORCC: ${CMAKE_AUTORCC}")

if(NOT QT_DIR AND (NOT IS_DIRECTORY ${QT_DIR}))
	if(WIN32)
		if(CMAKE_SIZEOF_VOID_P EQUAL 8)
				set(CMAKE_PREFIX_PATH "${QT_INSTALL_PATH}_64")
				message(STATUS "Build 64-bit system:${QT_INSTALL_PATH}_64")
		else()
			set(CMAKE_PREFIX_PATH ${QT_INSTALL_PATH})
			message(STATUS "Build 32-bit system:${QT_INSTALL_PATH}")
		endif()
	else()

	endif()
endif()



