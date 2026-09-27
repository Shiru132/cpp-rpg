#include "../include/CombatSystem.h"

void BattleTurn (Character *hero, Monster &monster, int wybor)
{
    switch (wybor)
    {
    case 2:
    case 4:
    {
        if (hero->checkHeroHp() > 0 && monster.checkMonsterHp() > 0)
        {
            if (wybor == 2)
            {
                hero->baseAttack(&monster);
            }
            else
            {
                hero->skillAttack(&monster);
            }
        }
        if (monster.checkMonsterHp() > 0)
        {
            hero->receiveDamage(monster.getDamage());
            monster.monsterHeal();
        }
    }
    }
}
