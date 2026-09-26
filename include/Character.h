#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Monster;
class Character
{
protected:
    std::string name;
    int hp;
    int damage;
    int defense;
    int lvl; //zrób mój przyszły ja z tym kiedyś coś sensownego
    int maxHp = 2100;
    

public:
    Character(const std::string& name, int hp, int defense, int damage);

    void checkMaxHP();
    void receiveDamage(int amount);
    int checkHeroHp();
    int checkFinalAmountFromMonster(Monster* cel);

    

    virtual void showInfo() = 0;
    virtual void baseAttack(Monster *cel) = 0;
    virtual void skillAttack(Monster *cel) = 0;
    virtual void heal() = 0;
    virtual ~Character() {}
};
#endif