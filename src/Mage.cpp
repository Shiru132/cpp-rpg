#include "../include/Mage.h"
#include <iostream>
#include "../include/Character.h"

#include "../include/Monster.h"
Mage::Mage(const std::string &name, int hp, int defense, int damage)
    : Character(name, hp, defense, damage)
{
}

void Mage::baseAttack(Monster *cel)
{
    
    std::cout << "Wykonujesz atak z kosturu, potwor dostal: " << checkFinalAmount(cel)*3 << " obrazen" << std::endl;
    cel->receiveBasicAttackDmg(checkFinalAmount(cel)*3);
}
void Mage::skillAttack(Monster *cel)
{

    std::cout << "Wykonujesz atak blyskawica i potwor otrzymuje: " << checkFinalAmount(cel)*5 << " obrazen" << std::endl;
    cel->receiveSkillAttackDmg(checkFinalAmount(cel)*5);
}

void Mage::heal()
{
    std::cout << "Hp przed leczeniem: " << hp << std::endl;

    hp += 100;
    if (hp > maxHp)
    {
        hp = maxHp;
    }
    std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << std::endl;
}

void Mage::showInfo()
{
    std::cout << "Nick: " << name << std::endl
              << "Hp: " << hp << std::endl
              << "Def: " << defense << std::endl
              << "Dmg: " << damage << std::endl;
}