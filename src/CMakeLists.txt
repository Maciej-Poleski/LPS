set(Language_Prototyping_Server_SRCS Author.cxx Example.cxx)
qt4_automoc(${Language_Prototyping_Server_SRCS})
add_executable(lps ${Language_Prototyping_Server_SRCS})
target_link_libraries(lps ${QT_LIBRARIES})
