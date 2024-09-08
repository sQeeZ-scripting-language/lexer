cmake_minimum_required(VERSION 3.16)
project(sQeeZ-Lexer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
  add_definitions(-D_SQEEZ_WIN)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif(APPLE)
  add_definitions(-D_SQEEZ_MAC)
else()
  add_definitions(-D_SQEEZ_LINUX)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(test)

add_executable(sQeeZ-Lexer src/main.cpp)

file(GLOB_RECURSE TOKEN_RECOGNIZER_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/token_recognizers/*.cpp"
)

add_library(sQeeZLexer STATIC 
    src/lexer/lexer.cpp 
    ${TOKEN_RECOGNIZER_SOURCES}  
)

target_link_libraries(sQeeZ-Lexer src)
target_include_directories(sQeeZLexer PUBLIC ${PROJECT_SOURCE_DIR}/include)