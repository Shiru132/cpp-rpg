

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
  
    Item &item = itemslist.getItem(0);
       
    

    
   
    
    item.showItemInfo();
   
    
    if (item.GetName() ==  "healing potion"){
        std::cout << "PASS"<<std::endl;
    }
    else{
        std::cout<<"FAIL"<<std::endl;
    }
    // todo ekwipunek i dokończenie itemów
    CreateHero(hero);
    GameMenu(hero.get(), monster);
}
