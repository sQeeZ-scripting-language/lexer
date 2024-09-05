cmake_minimum_required(VERSION 3.20)
project(sQeeZ-Lexer VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Cross-platform definitions
if(MSVC)
  # Windows specific settings
  add_definitions(-D_SQEEZ_WIN)
elseif(APPLE)
  # macOS specific settings
  add_definitions(-D_SQEEZ_MAC)
else()
  # Linux specific settings
  add_definitions(-D_SQEEZ_LINUX)
endif()

# Set shared library
add_library(sQeeZ-lexer SHARED
    src/main.cpp
)

target_include_directories(sQeeZ-lexer PUBLIC include)

# Installation steps
install(TARGETS sQeeZ-lexer DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# CMake configuration files for packaging
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

# Packaging configurations
include(CPack)
set(CPACK_GENERATOR "ZIP;TGZ")
set(CPACK_PACKAGE_NAME "sQeeZ-Lexer")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
set(CPACK_SOURCE_GENERATOR "TGZ")
