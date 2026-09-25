
// Do przepisania na .cpp i .h | character gotowe, monster po części (osobista notatka)

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



int main()
{
    MonsterDatabase database;
    Monster &zombie = database.getMonster(0);

    std::string nick;
    int health;
    int defense;
    int damage;
    std::string klasa_wybor;
    int klasa;
    std::unique_ptr<Character> hero;
    int x = 4;
    int y = 3;

    std::cout << "Podaj nick: ";
    std::cin >> nick;

    while (y != 0)
    {
        std::cout << "Wybierz klasę (Warrior,Mage,Archer): ";
        std::cin >> klasa_wybor;
        if (klasa_wybor == "Warrior" || klasa_wybor == "warrior")
        {
            klasa = 1;
            y = 0;
        }
        else if (klasa_wybor == "Mage" || klasa_wybor == "mage")
        {
            klasa = 2;
            y = 0;
        }
        else if (klasa_wybor == "Archer" || klasa_wybor == "archer")
        {
            klasa = 3;
            y = 0;
        }
        else
        {
            std::cout << "Zla nazwa postaci" << std::endl;
        }
    }
    switch (klasa)
    {
    case 1:
    {
        health = 200;
        defense = 20;
        damage = 30;
        hero = std::make_unique<Warrior>(nick, health, defense, damage);
    }
    break;
    case 2:
    {
        health = 120;
        defense = 10;
        damage = 50;
        hero = std::make_unique<Mage>(nick, health, defense, damage);
    }
    break;
    case 3:
    {
        health = 150;
        defense = 15;
        damage = 40;
        hero = std::make_unique<Archer>(nick, health, defense, damage);
    }
    break;
    default:
        break;
    }

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

    while (x != 0)
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
            if (hero->checkHeroHp() > 0 && zombie.checkMonsterHp() > 0)
            {
                hero->baseAttack(&zombie);
            }
            if (zombie.checkMonsterHp() > 0)
            {
                hero->receiveDamage(zombie.getDamage());
                zombie.monsterHeal();
            }
        }
        break;
        case 3:
        {
            hero->heal();
        }
        break;
        case 4:
        {
            if (hero->checkHeroHp() > 0 && zombie.checkMonsterHp() > 0)
            {
                hero->skillAttack(&zombie);
            }
            if (zombie.checkMonsterHp() > 0)
            {
                hero->receiveDamage(zombie.getDamage());
                zombie.monsterHeal();
            }
        }
        break;
        case 5:
        {
            std::cout << "xd";
        }
        break;
        case 6:
        {
            zombie.showMonsterInfo();
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
            x = 0;
        }
        break;
        }
    }
}
