add_executable(tests test_gcd_of_strings.cpp)
target_link_libraries(tests gcd_of_strings)
include(CTest)
add_test(NSME GcdOfStrings COMMAND tests)
