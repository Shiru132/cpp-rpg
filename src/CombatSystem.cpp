#include "../include/CombatSystem.h"

#include <memory>
#include <sstream>
#include <iostream>

void BattleTurn(Character *hero, Monster &monster, int choose)
{
    switch (choose)
    {
    case 2:
    case 4:
    {
        if (hero->checkHeroHp() > 0 && monster.checkMonsterHp() > 0)
        {
            if (choose == 2)
            {
                hero->baseAttack(&monster);
            }
            else
            {
                hero->skillAttack(&monster);
            }
        }
        if (monster.checkMonsterHp() > 0)
        {
            hero->receiveDamage(monster.getDamage());
            monster.monsterHeal();
        }
    }
    }
}

void CreateHero(std::unique_ptr<Character> &hero)
{

    bool y = false;
    int klasa;
    std::string klasa_wybor;
    std::string nick;

    int health;
    int defense;
    int damage;

    std::cout << "Podaj nick: ";
    std::cin >> nick;

    while (y != true)
    {
        std::cout << "Wybierz klasę (Warrior,Mage,Archer): ";
        std::cin >> klasa_wybor;
        if (klasa_wybor == "Warrior" || klasa_wybor == "warrior")
        {
            klasa = 1;
            y = true;
        }
        else if (klasa_wybor == "Mage" || klasa_wybor == "mage")
        {
            klasa = 2;
            y = true;
        }
        else if (klasa_wybor == "Archer" || klasa_wybor == "archer")
        {
            klasa = 3;
            y = true;
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
        health = 1200;
        defense = 100;
        damage = 110;
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
}

void GameMenu(Character *hero, Monster &monster)
{
    bool exit = false;
    std::cout << "===Wybierz opcje od (1 do 9)===" << std::endl;
    std::cout << "1. pokaz info swojej postaci: " << std::endl;
    std::cout << "2. wykonaj podstawowy atak: " << std::endl;
    std::cout << "3. uleczecesadsadsa sie: " << std::endl;
    std::cout << "4. wykonaj uderzenie skillem: " << std::endl;
    std::cout << "5. budowa: " << std::endl;
    std::cout << "6. Pokaz staty przeciwnika: " << std::endl;
    std::cout << "7. budowa: " << std::endl;
    std::cout << "8. budowa: " << std::endl;
    std::cout << "9. koniec programu: " << std::endl;

    while (exit != true)
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

            BattleTurn(hero, monster, chosenOption);
        }
        break;
        case 3:
        {
            hero->heal();
        }
        break;
        case 4:

        {
            BattleTurn(hero, monster, chosenOption);
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
            exit = true;
        }
        break;
        default:
            std::cout << "Podaj poprawna liczbe: " << std::endl;
        }
    }
}
