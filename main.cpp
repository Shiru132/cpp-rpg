

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "include/Character.h"
#include "include/Monster.h"
#include "include/MonsterDatabase.h"
#include "include/Warrior.h"
#include "include/Mage.h"
#include "include/Archer.h"
#include "include/CombatSystem.h"

int main()
{
    MonsterDatabase database;
    Monster &monster = database.getMonster(0);
    std::unique_ptr<Character> hero = nullptr;

    CreateHero(hero);
    GameMenu(hero.get(), monster);
}
