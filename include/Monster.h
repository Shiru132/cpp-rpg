#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Monster
{
protected:
    std::string name;
    int hp;
    int monsterMaxHp = 15000;
    int damage;
    int defense;

public:
    Monster(const std::string& name, int hp, int damage, int defense);
   
    void monsterHeal();
    int checkMonsterHp();
};

#endif