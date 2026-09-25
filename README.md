# C++ RPG

Prosta gra RPG tworzona w C++. Projekt zacząłem jako sposób na naukę C++ i OOP, a z czasem rozbudowuję go o kolejne elementy.

Simple RPG game written in C++. I started this project to learn C++ and OOP, and I am gradually adding new features and improving the code as I learn.

---

## Aktualny stan projektu / Current project status

### Polski

Aktualnie projekt posiada:

- kilka klas postaci: `Warrior`, `Mage` i `Archer`
- bazową, abstrakcyjną klasę `Character`
- dziedziczenie i polimorfizm
- system walki
- system potworów
- `MonsterDatabase` przechowujący potwory w `std::vector`
- obsługę wyjątków przy pobieraniu potworów
- `std::unique_ptr` do zarządzania obiektem gracza
- podstawową enkapsulację danych
- gettery i metody odpowiedzialne za zmianę stanu obiektów
- rozdzielenie klas na pliki `.h` i `.cpp`

Projekt jest nadal w trakcie rozwoju i część kodu będzie jeszcze refaktoryzowana.

### English

The project currently includes:

- several character classes: `Warrior`, `Mage`, and `Archer`
- an abstract base `Character` class
- inheritance and polymorphism
- a combat system
- a monster system
- `MonsterDatabase` using `std::vector`
- exception handling when retrieving monsters
- `std::unique_ptr` for managing the player object
- basic data encapsulation
- getters and methods responsible for modifying object state
- classes separated into `.h` and `.cpp` files

The project is still in development, and some parts of the code will be refactored as I continue learning.

---

## Czego używam / What I use

- C++
- OOP
- STL
- `std::vector`
- `std::unique_ptr`
- References
- Exceptions
- Git / GitHub

---

## Struktura projektu / Project structure

```text
C++-RPG/
├── include/
│   ├── Character.h
│   ├── Monster.h
│   ├── MonsterDatabase.h
│   ├── Warrior.h
│   ├── Mage.h
│   └── Archer.h
│
├── src/
│   ├── Character.cpp
│   ├── Monster.cpp
│   ├── MonsterDatabase.cpp
│   ├── Warrior.cpp
│   ├── Mage.cpp
│   └── Archer.cpp
│
├── data/
│   └── Monsters.json
│
├── main.cpp
├── .gitignore
└── README.md