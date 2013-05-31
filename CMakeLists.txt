cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED QtCore)
find_package(OpenCV REQUIRED)

include_directories(${QT_INCLUDES} ${OPENCV_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
add_definitions(${QT_DEFINITIONS})

set(PresenningExG_SRCS presenningExg.cpp)

qt4_automoc(${PresenningExG_SRCS})

ADD_LIBRARY(PresenningExG STATIC ${PresenningExG_SRCS})
	   
TARGET_LINK_LIBRARIES(PresenningExG ${QT_QTCORE_LIBRARY} ${OpenCV_LIBS})
