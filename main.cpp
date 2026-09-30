

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
#include "include/Items.h"

int main()
{
    MonsterDatabase database;
    Monster &monster = database.getMonster(0);
    std::unique_ptr<Character> hero = nullptr;
    ItemsList itemslist;
    Items &item = itemslist.dropItem(1);
    item.showItemInfo();
    
    CreateHero(hero);
    GameMenu(hero.get(), monster);
}
