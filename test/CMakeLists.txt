set(Language_Prototyping_Server_SRCS ../src/Author.cxx ../src/Example.cxx AuthorTest.cxx)
qt4_automoc(${Language_Prototyping_Server_SRCS})
add_executable(lps_test ${Language_Prototyping_Server_SRCS})
target_link_libraries(lps_test ${QT_LIBRARIES} ${Boost_LIBRARIES})

