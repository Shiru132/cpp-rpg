#ifndef MAGE_H
#define MAGE_H
#include <string>
#include "Character.h"
#include "Monster.h"
class Mage : public Character
{

public:
    Mage(const std::string &name, int hp, int defense, int damage);

    void baseAttack(Monster *cel) override;

    void skillAttack(Monster *cel) override;

    void heal() override;

    void showInfo() override;
};
#endif