#ifndef MonsterDB_H
#define MonsterDB_H
#include <vector>
#include "../include/Monster.h"
#include <string>


class MonsterDatabase
{
private:
    std::vector<Monster> listOfMonsters;

public:
    MonsterDatabase();
    // void showError(); Zobacz w MonsterDatabase.cpp dlaczego tak
        
    
    Monster& getMonster(int i);
};

#endif
