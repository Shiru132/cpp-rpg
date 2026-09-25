#include "../include/Mage.h"
#include <iostream>
#include "../include/Character.h"

#include "../include/Monster.h"
Mage::Mage(const std::string &name, int hp, int defense, int damage)
    : Character(name, hp, defense, damage)
{
}

void Mage::baseAttack(Monster*cel){
    std::cout << "Wykonujesz atak z kosturu, potwor dostal: " << damage * 3 << " obrazen" << std::endl;
    cel->receiveBasicAttackDmg(damage);

}
void Mage::skillAttack(Monster*cel){
    std::cout << "Wykonujesz atak blyskawica i potwor otrzymuje: " << damage * 5 << " obrazen" << std::endl;
    cel->receiveSkillAttackDmg(damage);

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