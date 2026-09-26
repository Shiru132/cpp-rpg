#ifndef MONSTER_H
#define MONSTER_H
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
    int checkMonsterHp() const;
    void receiveBasicAttackDmg(int damage);
    void receiveSkillAttackDmg(int damage);
    void showMonsterInfo() const;
    int getDamage() const{ 
        return damage;
    }
    int getDefense()const{
        return defense;
    }
};

#endif