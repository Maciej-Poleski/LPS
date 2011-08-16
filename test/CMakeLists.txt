project(Language_Prototyping_Server CXX)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
find_package(Qt4 REQUIRED)
find_package(Boost 1.46.1 REQUIRED)

include_directories(${QT_INCLUDES} ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR} ../src)

set(Language_Prototyping_Server_SRCS ../src/Author.cxx ../src/Prototype.cxx AuthorTest.cxx)
qt4_automoc(${Language Prototyping Server_SRCS})
add_executable(lps_test ${Language_Prototyping_Server_SRCS})
target_link_libraries(lps_test ${QT_QTCORE_LIBRARY})

