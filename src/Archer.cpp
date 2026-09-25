#include "../include/Archer.h"
#include <iostream>
#include "../include/Character.h"
#include "../include/Monster.h"

Archer::Archer(const std::string &name, int hp, int defense, int damage)
    : Character(name, hp, defense, damage)
{
}
void Archer::baseAttack(Monster*cel){
    std::cout << "Strzelasz strzala, potwor dostal: " << damage * 2 << " obrazen" << std::endl;
    cel->receiveBasicAttackDmg(damage);

}
void Archer::skillAttack(Monster*cel){
    std::cout << "strzelasz ognista strzala i potwor otrzymuje: " << damage * 6 << " obrazen" << std::endl;
    cel->receiveSkillAttackDmg(damage);

}

void Archer::heal() 
{
        std::cout << "Hp przed leczeniem: " << hp << std::endl;

        hp += 100;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
        std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << std::endl;
    }

void Archer::showInfo() 
    {
        std::cout << "Nick: " << name << std::endl
                  << "Hp: " << hp << std::endl
                  << "Def: " << defense << std::endl
                  << "Dmg: " << damage << std::endl;
    }