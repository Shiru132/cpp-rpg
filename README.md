# Niro

Prosta gra RPG w C++17, którą robię, żeby nauczyć się C++, OOP i tego, jak się układa większy projekt. Rozbudowuję ją po trochu, razem z tym, czego się uczę.

A simple text-based RPG in C++17. I'm making it to learn C++, OOP and how to put together a bigger project. I keep adding stuff as I learn new things.

---

## Co się teraz dzieje / What's going on right now

### Polski

Przebudowuję cały projekt na osobne moduły (`Core`, `Items`, `Inventory`, `Characters`, `Combat`, `Game`, `Database`), bo w starej wersji wszystko było trochę wrzucone do jednego worka. Stary kod (klasy `Warrior`, `Mage`, `Archer`, walka, potwory, wstępny system przedmiotów i ekwipunku) dalej jest w repo i przenoszę go po kawałku, więc część plików leży jeszcze w starych miejscach. Puste pliki w nowych folderach to tylko szkielet, który dopiero zapełniam.

Co chcę osiągnąć:

- żeby logika gry nie była mieszana z `cin`/`cout`, bazą ani siecią
- żeby przedmiot (np. "miecz") i konkretny egzemplarz tego przedmiotu (mój miecz +5) były osobno, połączone przez `ItemId`
- żeby statystyki postaci się wyliczały z bazowych statów i założonych przedmiotów, a nie były dopisywane na sztywno
- żeby baza danych była w osobnej warstwie `Repository` (najpierw wersja w pamięci, potem PostgreSQL)
- na końcu proste klient-serwer, gdzie serwer decyduje o tym, co się naprawdę stało

### English

I'm splitting the whole project into separate modules (`Core`, `Items`, `Inventory`, `Characters`, `Combat`, `Game`, `Database`), because in the old version everything was kind of thrown into one pile. The old code (`Warrior`, `Mage` and `Archer` classes, combat, monsters, an early items and inventory system) is still in the repo and I'm moving it over piece by piece, so some files are still in their old places. The empty files in the new folders are just a skeleton that I'm slowly filling in.

What I'm aiming for:

- game logic that isn't mixed with `cin`/`cout`, the database or the network
- items (like "sword") kept separate from a specific copy of that item (my sword +5), linked by `ItemId`
- character stats calculated from base stats and equipped items, instead of being hardcoded
- the database in its own `Repository` layer (in-memory first, PostgreSQL later)
- a simple client-server setup at the end, where the server decides what really happened

---

## Plan / Roadmap

- [x] Pierwsza wersja: klasy postaci, walka, potwory, proste przedmioty i ekwipunek, testy / First version: character classes, combat, monsters, simple items and inventory, tests
- [ ] Core (ID, staty, losowość)
- [ ] Items (definicje, egzemplarze, rejestr)
- [ ] Inventory i ekwipunek (przedmioty stackowane i unikalne)
- [ ] Characters (staty liczone z założonych przedmiotów)
- [ ] Combat (walka oddzielona od konsoli)
- [ ] Repository (najpierw w pamięci, potem PostgreSQL)
- [ ] Prosty klient-serwer

---

## Czego używam / What I use

- C++17
- OOP
- STL
- `std::vector`
- `std::unique_ptr`
- References
- Exceptions
- Git / GitHub
- CMake
- GoogleTest
- PostgreSQL (jeszcze nie / not yet)

---

## Jak odpalić / How to build

Jeszcze nie opisałem, wpiszę jak będzie działać po przebudowie. / Not written yet, I'll add it once the rebuild works.
