#ifndef ARCHER_H
#define ARCHER_H
#include <string>
#include "Character.h"
#include "Monster.h"



class Archer : public Character
{

public:
Archer(const std::string& name, int hp, int defense, int damage);

    

    void baseAttack(Monster *cel) override;
   
    void skillAttack(Monster *cel) override;
    
    void heal() override;
    
    void showInfo() override;
  
};
#endif