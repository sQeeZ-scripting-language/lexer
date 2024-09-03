cmake_minimum_required(VERSION 3.20)
project(lexer VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

add_executable(sQeeZ src/main.cpp)

target_link_libraries(sQeeZ src)
add_subdirectory(test)

add_library(sQeeZ-lexer STATIC
    src/main.cpp
)

target_include_directories(sQeeZ-lexer PUBLIC include)

install(TARGETS sQeeZ-lexer DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/sQeeZLexerConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/sQeeZLexerConfigVersion.cmake"
    DESTINATION lib/cmake/sQeeZ-lexer
)

include(CPack)
set(CPACK_GENERATOR "ZIP;TGZ")

set(CPACK_PACKAGE_NAME "sQeeZ-Lexer")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
set(CPACK_SOURCE_GENERATOR "TGZ")
