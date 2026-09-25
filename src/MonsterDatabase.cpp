#include "../include/MonsterDatabase.h"
#include <stdexcept>

MonsterDatabase::MonsterDatabase()
{
    Monster zombie("zombie", 200, 400, 600);
    Monster spider("spider", 250, 100, 600);

    listOfMonsters.push_back(zombie);
    listOfMonsters.push_back(spider);
}
// void MonsterDatabase::showError(){
//     std::cout<<"Blad nie wybrales moba"<<std::endl;
// }
//zostawiam na przyszłość może się przyda
//Ogólnie to nie możemy dać tego showError bo obiecaliśmy że zwrócimy jakąś referencje 
//ale tutaj ładnie możemy dać throw bo: Wystąpił problem. Przerwij normalne wykonywanie tej funkcji i przekaż informację o błędzie dalej.

Monster& MonsterDatabase::getMonster(int i)
{
    if (i>(listOfMonsters.size())-1){
        throw std::runtime_error("Monster not found potato"); 
    }
    
    return listOfMonsters[i];
}