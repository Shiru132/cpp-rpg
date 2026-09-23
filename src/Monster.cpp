#include "../include/Monster.h"
#include <iostream>

Monster::Monster(std::string name, int hp, int damage, int defense){
     
        this->name = name;
        this->hp = hp;
        this->damage = damage;
        this->defense = defense;
     
}
void Monster::monsterHeal(){
        int randomNum = rand() % (4 - 1 + 1) + 1;
        if (randomNum == 2)
        {
            this->hp+=100;
            if (this->hp > this->monsterMaxHp)
            {
                this->hp = this->monsterMaxHp;
            }
            std::cout << "Potwor uleczyl sie teraz ma: " << this->hp << " hp" << std::endl;
        }
    }
int Monster::checkMonsterHp(){
    return hp;
}

