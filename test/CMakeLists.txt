include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(LEXER_SOURCES
    ${CMAKE_SOURCE_DIR}/src/lexer/lexer.cpp
    ${CMAKE_SOURCE_DIR}/src/lexer/token_recognizers/syntax_recognizers.cpp
    ${CMAKE_SOURCE_DIR}/src/lexer/token_recognizers/keyword_recognizers.cpp
    ${CMAKE_SOURCE_DIR}/src/lexer/token_recognizers/operator_recognizers.cpp
    ${CMAKE_SOURCE_DIR}/src/lexer/token_recognizers/logical_recognizers.cpp
    ${CMAKE_SOURCE_DIR}/src/lexer/token_recognizers/log_recognizers.cpp
)

add_library(test_lexer ${LEXER_SOURCES})

add_executable(
    main_test
    main_test.cc
)

add_executable(
    lexer_test
    lexer_test.cc
)

target_link_libraries(
    main_test
    GTest::gtest_main
)

target_link_libraries(
    lexer_test
    GTest::gtest_main
    test_lexer
)

include(GoogleTest)
gtest_discover_tests(main_test)
gtest_discover_tests(lexer_test)
