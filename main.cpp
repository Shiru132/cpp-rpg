

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "include/Character.h"
#include "include/Monster.h"
#include "include/MonsterDatabase.h"
#include "include/Warrior.h"
#include "include/Mage.h"
#include "include/Archer.h"
#include "include/CombatSystem.h"

int main()
{
    MonsterDatabase database;
    Monster &monster = database.getMonster(0);
    std::unique_ptr<Character> hero = nullptr;
  

    bool x = false;
    
    CreateHero(hero);
    std::cout << "===Wybierz opcje od (1 do 9)===" << std::endl;
    std::cout << "1. pokaz info swojej postaci: " << std::endl;
    std::cout << "2. wykonaj podstawowy atak: " << std::endl;
    std::cout << "3. ulecz sie: " << std::endl;
    std::cout << "4. wykonaj uderzenie skillem: " << std::endl;
    std::cout << "5. budowa: " << std::endl;
    std::cout << "6. Pokaz staty przeciwnika: " << std::endl;
    std::cout << "7. budowa: " << std::endl;
    std::cout << "8. budowa: " << std::endl;
    std::cout << "9. koniec programu: " << std::endl;

    while (x != true)
    {
        int chosenOption;

        std::cin >> chosenOption;
        switch (chosenOption)
        {
        case 1:
        {
            hero->showInfo();
        }
        break;
        case 2:
        {

            BattleTurn(hero.get(), monster, chosenOption);
        }
        break;
        case 3:
        {
            hero->heal();
        }
        break;
        case 4:

        {
            BattleTurn(hero.get(), monster, chosenOption);
        }
        break;
        case 5:
        {
            std::cout << "xd";
        }
        break;
        case 6:
        {
            monster.showMonsterInfo();
        }
        break;
        case 7:
        {
            hero->showInfo();
        }
        break;
        case 8:
        {
            hero->showInfo();
        }
        break;
        case 9:
        {
            x = true;
        }
        break;
        }
    }
}
