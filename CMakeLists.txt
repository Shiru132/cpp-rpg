
cmake_minimum_required(VERSION 3.16)

project(Niro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# GoogleTest
include(FetchContent)

FetchContent_Declare(
    GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.18.0
)

FetchContent_MakeAvailable(GoogleTest)

# Core library
add_library(NiroCore
    src/core/IdGenerator.cpp
    src/items/ItemInstance.cpp
    src/items/ItemDefinition.cpp
)

target_include_directories(NiroCore PUBLIC include)

# Main application
add_executable(Niro
    main.cpp
)

target_link_libraries(Niro PRIVATE NiroCore)

# Unit tests
add_executable(NiroTests
    tests/core/TypesTests.cpp
    tests/items/ItemDefinitionTest.cpp
    tests/items/ItemInstanceTest.cpp
)

target_link_libraries(NiroTests
    PRIVATE
        NiroCore
        GTest::gtest_main
)

# Warnings
if(MSVC)
    target_compile_options(NiroCore PRIVATE /W4)
    target_compile_options(Niro PRIVATE /W4)
    target_compile_options(NiroTests PRIVATE /W4)
else()
    target_compile_options(NiroCore PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(Niro PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(NiroTests PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Testing
enable_testing()

include(GoogleTest)
gtest_discover_tests(NiroTests)
