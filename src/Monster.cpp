#include "../include/Monster.h"
#include <iostream>

Monster::Monster(const std::string &name, int hp, int damage, int defense)
{

    this->name = name;
    this->hp = hp;
    this->damage = damage;
    this->defense = defense;
}
void Monster::monsterHeal()
{
    int randomNum = rand() % (4 - 1 + 1) + 1;
    if (randomNum == 2)
    {
        this->hp += 100;
        if (this->hp > this->monsterMaxHp)
        {
            this->hp = this->monsterMaxHp;
        }
        std::cout << "Potwor uleczyl sie teraz ma: " << this->hp << " hp" << std::endl;
    }
}
void Monster::receiveBasicAttackDmg(int damage)
{
    
    
        this->hp -= damage;

        if (this->hp < 0)
        {
            this->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
        std::cout << "Pozostałe hp potwora: " << this->hp << std::endl;
}
void Monster::receiveSkillAttackDmg(int damage)
{
    
      
        this->hp -= damage;
       

        if (this->hp < 0)
        {
            this->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
        std::cout << "Pozostałe hp potwora: " << this->hp << std::endl;
    
}
int Monster::checkMonsterHp() const
{
    return hp;
}
void Monster::showMonsterInfo() const{
    std::cout << "Nazwa potwora: " << name << std::endl
                  << "Hp: " << hp << std::endl
                  << "Def: " << defense << std::endl
                  << "Dmg: " << damage << std::endl;
}
