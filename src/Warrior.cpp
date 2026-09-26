#include "../include/Warrior.h"
#include <iostream>
#include "../include/Character.h"

#include "../include/Monster.h"

Warrior::Warrior(const std::string &name, int hp, int defense, int damage)
    : Character(name, hp, defense, damage)
{
}

void Warrior::baseAttack(Monster *cel)
{
    std::cout << "Wykonujesz atak mieczem, potwor dostal: " << checkFinalAmount(cel)*2 << " obrazen" << std::endl;
    cel->receiveBasicAttackDmg(checkFinalAmount(cel)*2);
}
void Warrior::skillAttack(Monster *cel)
{
    std::cout << "Wykonujesz atak duchowy i potwor otrzymuje: " << checkFinalAmount(cel)*5 << " obrazen" << std::endl;
    cel->receiveSkillAttackDmg(checkFinalAmount(cel)*5);
}

void Warrior::heal()
{
    std::cout << "Hp przed leczeniem: " << hp << std::endl;

    hp += 70;
    if (hp > maxHp)
    {
        hp = maxHp;
    }
    std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << std::endl;
}

void Warrior::showInfo()
{
    std::cout << "Nick: " << name << std::endl
              << "Hp: " << hp << std::endl
              << "Def: " << defense << std::endl
              << "Dmg: " << damage << std::endl;
}