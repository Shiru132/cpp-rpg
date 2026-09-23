#include "../include/Character.h"
#include <iostream>

Character::Character(std::string name, int hp, int defense, int damage)
{
    this->name = name;
    this->hp = hp;
    this->defense = defense;
    this->damage = damage;
}

void Character::checkMaxHP()
{
    if (hp > maxHp)
    {
        hp = maxHp;
   
    }
}
void Character::receiveDamage(int amount)
{
    int finalAmount = (amount - defense);
    if (finalAmount < 0)
    {
        finalAmount = 0;
    }
    std::cout << "Potwor cie uderzyl za: " << finalAmount << " obrazen" << std::endl;
    hp -= (finalAmount);
    if (hp < 0)
    {
        hp = 0;
        std::cout << "Zostales pokonany!" << std::endl;
    }
    std::cout << "Zostalo ci: " << hp << " hp" << std::endl;
}
int Character::checkHeroHp()
{
    return hp;
}