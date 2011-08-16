cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Language_Prototyping_Server)
set(QT_USE_IMPORTED_TARGETS TRUE)
find_package(Qt4 REQUIRED QtCore QtNetwork)
find_package(Boost 1.46.1 REQUIRED)

include(${QT_USE_FILE})

include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR} src)

#add_subdirectory(src)
add_subdirectory(test)