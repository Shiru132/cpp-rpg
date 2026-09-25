#ifndef WARRIOR_H
#define WARRIOR_H
#include <string>
#include "Character.h"
#include "Monster.h"


class Warrior : public Character
{

public:
Warrior(const std::string &name, int hp, int defense, int damage);
    

    void baseAttack(Monster *cel) override;
   
    void skillAttack(Monster *cel) override;
    
    void heal() override;
    
    void showInfo() override;
  
};
#endif