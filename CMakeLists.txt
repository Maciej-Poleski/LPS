project(Language_Prototyping_Server CXX)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(Language_Prototyping_Server_SRCS Author.cxx Prototype.cxx)
qt4_automoc(${Language Prototyping Server_SRCS})
add_executable(lps ${Language_Prototyping_Server_SRCS})
target_link_libraries(lps ${QT_QTCORE_LIBRARY})
