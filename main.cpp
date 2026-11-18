

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
#include <string>

#include <iostream>

int main()
{
    const std::string path = "data/Items.json";
    ItemLoader itemLoader;
    
    auto items = itemLoader.loadFromFile(path);
 

    for (const auto& item : items){
        std::cout << "Utworzona definicja: \n";
        std::cout << "Item ID: " << item.getItemId().getItemId() << '\n';
        std::cout << "Name: " << item.getName() << std::endl;
        std::cout << "desc: " << item.getDescription() << std::endl;
        std::cout << "damage: " << item.getDamage() << std::endl;
        std::cout << "defense: " << item.getDefense() << std::endl;
        std::cout << "hp: " << item.getHp() << std::endl;
        std::cout << "stackable: " << item.isStackable() << std::endl;
        std::cout << "value: " << item.getValue() << std::endl;
        std::cout << "maxstack: " << item.getMaxStack() << std::endl;
    }
    std::cout<< "ilosc przedmiotow: "<<items.size()<<std::endl;

    return 0;
}