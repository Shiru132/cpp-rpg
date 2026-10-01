cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
project(Niro LANGUAGES CXX)
add_executable(Niro
    main.cpp
    src/Character.cpp
    src/MonsterDatabase.cpp
    src/Monster.cpp
    src/CombatSystem.cpp
    src/Items.cpp
    src/Archer.cpp
    src/Mage.cpp
    src/Warrior.cpp



)

target_include_directories(Niro PRIVATE include)

include(FetchContent)
FetchContent_Declare(
    GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.18.0
)
FetchContent_MakeAvailable(GoogleTest)
add_executable(NiroTests
    tests/ItemsTests.cpp
    src/Items.cpp
)
target_include_directories(NiroTests PRIVATE include)
target_link_libraries(NiroTests gtest_main)
