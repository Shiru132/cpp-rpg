

// #include <iostream>
// #include <memory>
// #include <vector>
// #include <algorithm>

// #include "include/Character.h"
// #include "include/Monster.h"
// #include "include/MonsterDatabase.h"
// #include "include/Warrior.h"
// #include "include/Mage.h"
// #include "include/Archer.h"
// #include "include/CombatSystem.h"
// #include "include/Items.h"
// #include "include/Inventory.h"

// int main()
// {
//     MonsterDatabase database;
//     Monster &monster = database.getMonster(0);
//     std::unique_ptr<Character> hero = nullptr;
//     ItemsList itemslist;

//     Item &item = itemslist.getItem(2);
//     Item &item1 = itemslist.getItem(1);
//     Item &item2 = itemslist.getItem(0);
//     Item &item3 = itemslist.getItem(2);
//     Item &item4 = itemslist.getItem(2);
//        Inventory inventory;
//        inventory.addItem(item,-2);
//        inventory.addItem(item1,2);
//        inventory.addItem(item2,0);
//        inventory.addItem(item3,-3);
//        inventory.addItem(item4,3);

//     inventory.checkInventory();

//     // todo ekwipunek i dokończenie itemów
//     CreateHero(hero);
//     GameMenu(hero.get(), monster);
// }

#include "core/IdGenerator.h"
#include "items/ItemDefinition.h"
#include "items/ItemInstance.h"
#include "core/Types.h"
#include "items/ItemLoader.h"
#include "items/ItemRegistry.h"
#include <string>

#include <iostream>

int main()
{
    std::string path = "data/items.json";
    ItemLoader itemloader;
    auto items = itemloader.loadFromFile(path);
    ItemRegistry itemRegistry(items);
    ItemId itemid(1001);
    ItemId itemid2(1001);
    ItemId itemid3(1002);
    ItemId itemid4(9999);

    const auto& it = itemRegistry.getItemDefiniton(itemid);
    const auto& it2=itemRegistry.getItemDefiniton(itemid2);
    const auto& it3 =itemRegistry.getItemDefiniton(itemid3);
    const auto& it4 =itemRegistry.getItemDefiniton(itemid4);
    std::cout<< it.getName()<<std::endl;
    std::cout<< it2.getName()<<std::endl;
    std::cout<< it3.getName()<<std::endl;
    std::cout<< it4.getName()<<std::endl;
    

    ItemIdHash hasher;
    
    return 0;
}