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
    
    std::cout << "Wykonujesz atak z kosturu, potwor dostal: " << checkFinalAmountFromMonster(cel)*3 << " obrazen" << std::endl;
    cel->receiveBasicAttackDmg(checkFinalAmountFromMonster(cel)*3);
}
void Mage::skillAttack(Monster *cel)
{

    std::cout << "Wykonujesz atak blyskawica i potwor otrzymuje: " << checkFinalAmountFromMonster(cel)*5 << " obrazen" << std::endl;
    cel->receiveSkillAttackDmg(checkFinalAmountFromMonster(cel)*5);
}

void Mage::heal()
{
    std::cout << "Hp przed leczeniem: " << hp << std::endl;

    hp += 100;
    checkMaxHP();
    std::cout << "Teraz twoje hp wynosi: " << hp << " Hp" << std::endl;
}

void Mage::showInfo()
{
    std::cout << "Nick: " << name << std::endl
              << "Hp: " << hp << std::endl
              << "Def: " << defense << std::endl
              << "Dmg: " << damage << std::endl;
}