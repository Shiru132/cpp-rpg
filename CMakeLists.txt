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
