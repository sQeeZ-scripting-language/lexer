# CMake Configuration for sQeeZ-Lexer
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the project name
project(sQeeZ-Lexer)

# OS specific configurations
if(MSVC)
  add_definitions(-D_SQEEZ_WIN)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif(APPLE)
  add_definitions(-D_SQEEZ_MAC)
  set(CMAKE_OSX_ARCHITECTURES "arm64")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -arch arm64")
else()
  add_definitions(-D_SQEEZ_LINUX)
endif()

# Include the header directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include NodeJS
include(./node_modules/node-cmake/NodeJS.cmake)
nodejs_init()

# After init, we will have headers required at the following folder:
# ${CMAKE_CURRENT_BINARY_DIR}/node/${NODEJS_VERSION}/include
include_directories(
  ${CMAKE_JS_INC} 
  "${CMAKE_CURRENT_BINARY_DIR}/node/${NODEJS_VERSION}/include" 
  "${CMAKE_HOME_DIRECTORY}/node_modules/node-addon-api"
)

# Include Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Configure Google Test
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

# Include the source files
file(GLOB_RECURSE SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lexer/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lexer/token_recognizers/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/lexer/node/*.cpp
)

# Include the header files
file(GLOB_RECURSE HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/lexer/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/lexer/token_recognizers/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/lexer/tokens/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/lexer/node/*.hpp
)

# Create the Library
add_library(
  sQeeZ-Lexer-Lib 
  STATIC 
  ${SOURCES} 
  ${HEADERS}
)

# Create the Executable
add_executable(
  sQeeZ-Lexer-Exe
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
target_link_libraries(
  sQeeZ-Lexer-Exe 
  sQeeZ-Lexer-Lib
)

# Create the NodeJS module
add_library(
  sQeeZ-Lexer-Node 
  SHARED 
  ${SOURCES} 
  ${HEADERS}
)
set_target_properties(
  sQeeZ-Lexer-Node 
  PROPERTIES PREFIX "" SUFFIX ".node"
)
target_link_libraries(
  sQeeZ-Lexer-Node 
  ${CMAKE_JS_LIB}
  sQeeZ-Lexer-Lib
)

# Lexer Test
add_executable(
  lexer_test 
  ${CMAKE_CURRENT_SOURCE_DIR}/test/lexer_test.cc
)
target_link_libraries(
  lexer_test
  GTest::gtest_main
  sQeeZ-Lexer-Lib
)
gtest_discover_tests(lexer_test)
