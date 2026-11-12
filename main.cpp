

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

#include <iostream>

int main()
{

    IdGenerator &generator = IdGenerator::getInstance();
    ItemId itemId(1);
    InstanceId instanceId(generator.generateInstanceId());

    ItemDefinition itemDefinition(itemId, "zelazny miecz", "jakis tam mieczyk", ItemType::Weapon, 100, 50, 0, false, 1000, 1);
    ItemInstance itemInstance(&instanceId, &itemId, &itemDefinition, 2, 20);
    std::cout << itemInstance.getBonusDamage() << std::endl;
    std::cout << itemInstance.getUpgradeLvl() << std::endl;
    std::cout << itemDefinition.getDamage() << std::endl;
    std::cout << itemDefinition.getDefense() << std::endl;
    std::cout << itemDefinition.getDescription() << std::endl;
    std::cout << itemDefinition.getHp() << std::endl;
    std::cout << itemDefinition.getMaxStack() << std::endl;
    std::cout << itemDefinition.getName() << std::endl;
    std::cout << itemDefinition.getValue() << std::endl;
    std::cout << itemDefinition.isStackable() << std::endl;

    return 0;
}
