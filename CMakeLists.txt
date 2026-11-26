
cmake_minimum_required(VERSION 3.16)

project(Niro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# GoogleTest
include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
    GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.18.0
)

FetchContent_MakeAvailable(GoogleTest)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Core library
add_library(NiroCore
    src/core/IdGenerator.cpp
    src/items/ItemInstance.cpp
    src/items/ItemDefinition.cpp
    src/items/ItemLoader.cpp
    src/items/ItemRegistry.cpp
    src/inventory/Inventory.cpp
)

target_include_directories(NiroCore PUBLIC include)
target_link_libraries(NiroCore
    PUBLIC
        nlohmann_json::nlohmann_json
)

# Main application
add_executable(Niro
    main.cpp
)
target_link_libraries(Niro
    PRIVATE
        NiroCore
        nlohmann_json::nlohmann_json
)

# Unit tests
add_executable(NiroTests
    tests/core/TypesTests.cpp
    tests/items/ItemDefinitionTest.cpp
    tests/items/ItemInstanceTest.cpp
    tests/inventory/InventoryTest.cpp
)

target_link_libraries(NiroTests
    PRIVATE
        NiroCore
        GTest::gtest_main
    PUBLIC
    nlohmann_json::nlohmann_json
)
# SFML
add_executable(NiroClient
    apps/client/main.cpp
)
target_compile_features(NiroClient PRIVATE cxx_std_17)
target_link_libraries(NiroClient 
    PRIVATE 
        NiroCore
        SFML::Graphics
)

# Warnings
if(MSVC)
    target_compile_options(NiroCore PRIVATE /W4)
    target_compile_options(Niro PRIVATE /W4)
    target_compile_options(NiroClient PRIVATE /W4)
    target_compile_options(NiroTests PRIVATE /W4)
else()
    target_compile_options(NiroCore PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(Niro PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(NiroClient PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(NiroTests PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Testing
enable_testing()

include(GoogleTest)
gtest_discover_tests(NiroTests)
