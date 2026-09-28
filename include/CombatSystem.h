#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H
#include "Monster.h"
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"
#include <memory>

void BattleTurn(Character *hero, Monster &monster, int choose);

void CreateHero(std::unique_ptr <Character> &hero);

#endif
