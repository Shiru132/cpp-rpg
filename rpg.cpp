
#include <iostream>
using namespace std;
#include <memory>

class Monster;
class Character
{
protected:
    string name;
    int hp;
    int damage;
    int defense;
    int lvl;
    int maxHp = 2100;
    int checker;

public:
    Character(string name, int hp, int defense, int damage)
    {
        this->name = name;
        this->hp = hp;
        this->defense = defense;
        this->damage = damage;
    }

    void checkMaxHP()
    {
        if (hp > maxHp)
        {
            hp = maxHp;
            std::cout << hp;
        }
    }
    void receiveDamage(int amount)
    {
        int finalAmount = (amount - defense);
        if (finalAmount < 0)
        {
            finalAmount = 0;
        }
        std::cout << "Potwor cie uderzyl za: " << finalAmount << " obrazen" << endl;
        hp -= (finalAmount);
        if (hp < 0)
        {
            hp = 0;
            std::cout << "Zostales pokonany!" << endl;
        }
        std::cout << "Zostalo ci: " << hp << " hp" << endl;
    }
    int checkHeroHp()
    {
        return hp;
    }
    virtual void showInfo() = 0;
    virtual void baseAttack(Monster *cel) = 0;
    virtual void skillAttack(Monster *cel) = 0;
    virtual void heal() = 0;
    virtual ~Character() {}
};
class Monster
{
protected:
    string name;

public:
    Monster(string name)
    {
        this->name = name;
    }
    int hp = 500;
    int maxHp = 10000;
    int damage = 10;
    void monsterHeal()
    {
        int randomNum = rand() % (4 - 1 + 1) + 1;
        if (randomNum == 2)
        {
            hp += 100;
            if (hp > maxHp)
            {
                hp = maxHp;
            }
            std::cout << "Potwor uleczyl sie teraz ma: " << hp << " hp" << endl;
        }
    };
    int checkMonsterHp()
    {
        return hp;
    }
};

class Warrior : public Character
{

public:
    Warrior(string name, int hp, int defense, int damage) : Character(name, hp, defense, damage)
    {
    }

    void baseAttack(Monster *cel) override
    {
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!" << endl;
            return;
        }

        std::cout << "Hp potwora: " << cel->hp << endl;
        std::cout << "Wykonujesz atak mieczem, potwor dostal: " << damage * 2 << " obrazen" << endl;
        cel->hp -= damage * 2;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!" << endl;
        }
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
    }
    void skillAttack(Monster *cel) override
    {
        std::cout << "Wykonujesz atak duchowy i potwor otrzymuje: " << damage * 4 << " obrazen" << endl;
        cel->hp -= damage * 4;

        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
    }
    void heal() override
    {
        std::cout << "Hp przed leczeniem: " << hp << endl;

        hp += 70;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
        std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << endl;
    }
    void showInfo() override
    {
        std::cout << "Nick: " << name << endl
                  << "Hp: " << hp << endl
                  << "Def: " << defense << endl
                  << "Dmg: " << damage << endl;
    }
};
class Mage : public Character
{

public:
    Mage(string name, int hp, int defense, int damage) : Character(name, hp, defense, damage)
    {
    }

    void baseAttack(Monster *cel) override
    {
        std::cout << "Wykonujesz atak z kosturu, potwor dostal: " << damage * 3 << " obrazen" << endl;
        cel->hp -= damage * 3;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
    }
    void skillAttack(Monster *cel) override
    {
        std::cout << "Wykonujesz atak blyskawica i potwor otrzymuje: " << damage * 5 << " obrazen" << endl;
        cel->hp -= damage * 5;
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
    }
    void heal() override
    {
        std::cout << "Hp przed leczeniem: " << hp << endl;
        hp += 130;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
        std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << endl;
    }
    void showInfo() override
    {
        std::cout << "Nick: " << name << endl
                  << "Hp: " << hp << endl
                  << "Def: " << defense << endl
                  << "Dmg: " << damage << endl;
    }
};
class Archer : public Character
{

public:
    Archer(string name, int hp, int defense, int damage) : Character(name, hp, defense, damage)
    {
    }

    void baseAttack(Monster *cel) override
    {
        std::cout << "Strzelasz strzala, potwor dostal: " << damage * 2.5 << " obrazen" << endl;
        cel->hp -= damage * 2.5;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
    }
    void skillAttack(Monster *cel) override
    {
        std::cout << "strzelasz ognista strzala i potwor otrzymuje: " << damage * 6 << " obrazen" << endl;
        cel->hp -= damage * 6;
        std::cout << "Wykonujesz jebniecie z luku!" << endl;
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
    }
    void heal() override
    {
        std::cout << "Hp przed leczeniem: " << hp << endl;
        hp += 50;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
        std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << endl;
    }
    void showInfo() override
    {
        std::cout << "Nick: " << name << endl
                  << "Hp: " << hp << endl
                  << "Def: " << defense << endl
                  << "Dmg: " << damage << endl;
    }
};

int main()
{
    Monster zombie("zombie");
    string nick;
    int health;
    int defense;
    int damage;
    string klasa_wybor;
    int klasa;
    std::unique_ptr<Character> hero;
    int x = 4;
    int y = 3;

    std::cout << "Podaj nick: ";
    cin >> nick;

    while (y != 0)
    {
        std::cout << "Wybierz klasę (Warrior,Mage,Archer): ";
        cin >> klasa_wybor;
        if (klasa_wybor == "Warrior" || klasa_wybor == "warrior")
        {
            klasa = 1;
            y = 0;
        }
        else if (klasa_wybor == "Mage" || klasa_wybor == "mage")
        {
            klasa = 2;
            y = 0;
        }
        else if (klasa_wybor == "Archer" || klasa_wybor == "archer")
        {
            klasa = 3;
            y = 0;
        }
        else
        {
            std::cout << "Zla nazwa postaci" << endl;
        }
    }
    switch (klasa)
    {
    case 1:
    {
        health = 200;
        defense = 20;
        damage = 30;
        hero = std::make_unique<Warrior>(nick, health, defense, damage);
    }
    break;
    case 2:
    {
        health = 120;
        defense = 10;
        damage = 50;
        hero = std::make_unique<Mage>(nick, health, defense, damage);
    }
    break;
    case 3:
    {
        health = 150;
        defense = 15;
        damage = 40;
        hero = std::make_unique<Archer>(nick, health, defense, damage);
    }
    break;
    default:
        break;
    }

    std::cout << "===Wybierz opcje od (1 do 9)===" << endl;
    std::cout << "1. pokaz info swojej postaci: " << endl;
    std::cout << "2. wykonaj podstawowy atak: " << endl;
    std::cout << "3. ulecz sie: " << endl;
    std::cout << "4. wykonaj uderzenie skillem: " << endl;
    std::cout << "5. budowa: " << endl;
    std::cout << "6. budowa: " << endl;
    std::cout << "7. budowa: " << endl;
    std::cout << "8. budowa: " << endl;
    std::cout << "9. koniec programu: " << endl;

    while (x != 0)
    {
        int chosenOption;

        cin >> chosenOption;
        switch (chosenOption)
        {
        case 1:
        {
            hero->showInfo();
        }
        break;
        case 2:
        {
            if (hero->checkHeroHp() > 0 && zombie.checkMonsterHp() > 0)
            {
                hero->baseAttack(&zombie);
            }
            if (zombie.checkMonsterHp() > 0)
            {
                hero->receiveDamage(zombie.damage);
                zombie.monsterHeal();
            }
        }
        break;
        case 3:
        {
            hero->heal();
        }
        break;
        case 4:
        {
            if (hero->checkHeroHp() > 0 && zombie.checkMonsterHp() > 0)
            {
                hero->skillAttack(&zombie);
            }
            if (zombie.checkMonsterHp() > 0)
            {
                hero->receiveDamage(zombie.damage);
                zombie.monsterHeal();
            }
        }
        break;
        case 5:
        {
            cout << "xd";
        }
        break;
        case 6:
        {
            hero->showInfo();
        }
        break;
        case 7:
        {
            hero->showInfo();
        }
        break;
        case 8:
        {
            hero->showInfo();
        }
        break;
        case 9:
        {
            x = 0;
        }
        break;
        }
    }
}
=======

#include <iostream>
using namespace std;

class Monster;
class Character
{
protected:
    string name;
    int hp;
    int damage;
    int defense;
    int lvl;
    int maxHp = 2100;
    int checker;

public:
    Character(string name, int hp, int defense, int damage)
    {
        this->name = name;
        this->hp = hp;
        this->defense = defense;
        this->damage = damage;
    }

    void checkMaxHP()
    {
        if (hp > maxHp)
        {
            hp = maxHp;
            std::cout << hp;
        }
    }
    void receiveDamage(int amount)
    {
        int finalAmount = (amount - defense);
        if (finalAmount < 0)
        {
            finalAmount = 0;
        }
        std::cout << "Potwor cie uderzyl za: " << finalAmount << " obrazen" << endl;
        hp -= (finalAmount);
        if (hp < 0)
        {
            hp = 0;
            std::cout << "Zostales pokonany!" << endl;
        }
        std::cout << "Zostalo ci: " << hp << " hp" << endl;
    }
    int checkHeroHp()
    {
        return hp;
    }
    virtual void showInfo() = 0;
    virtual void baseAttack(Monster *cel) = 0;
    virtual void skillAttack(Monster *cel) = 0;
    virtual void heal() = 0;
    virtual ~Character() {}
};
class Monster
{
protected:
    string name;

public:
    Monster(string name)
    {
        this->name = name;
    }
    int hp = 500;
    int maxHp = 10000;
    int damage = 10;
    void monsterHeal()
    {
        int randomNum = rand() % (4 - 1 + 1) + 1;
        if (randomNum == 2)
        {
            hp += 100;
            if (hp > maxHp)
            {
                hp = maxHp;
            }
            std::cout << "Potwor uleczyl sie teraz ma: " << hp << " hp" << endl;
        }
    };
    int checkMonsterHp()
    {
        return hp;
    }
};

class Warrior : public Character
{

public:
    Warrior(string name, int hp, int defense, int damage) : Character(name, hp, defense, damage)
    {
    }

    void baseAttack(Monster *cel) override
    {

        std::cout << "Wykonujesz atak mieczem, potwor dostal: " << damage * 2 << " obrazen" << endl;
        cel->hp -= damage * 2;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!" << endl;
        }
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
    }
    void skillAttack(Monster *cel) override
    {
        std::cout << "Wykonujesz atak duchowy i potwor otrzymuje: " << damage * 4 << " obrazen" << endl;
        cel->hp -= damage * 4;

        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
    }
    void heal() override
    {
        std::cout << "Hp przed leczeniem: " << hp << endl;

        hp += 70;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
        std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << endl;
    }
    void showInfo() override
    {
        std::cout << "Nick: " << name << endl
                  << "Hp: " << hp << endl
                  << "Def: " << defense << endl
                  << "Dmg: " << damage << endl;
    }
};
class Mage : public Character
{

public:
    Mage(string name, int hp, int defense, int damage) : Character(name, hp, defense, damage)
    {
    }

    void baseAttack(Monster *cel) override
    {
        std::cout << "Wykonujesz atak z kosturu, potwor dostal: " << damage * 3 << " obrazen" << endl;
        cel->hp -= damage * 3;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
    }
    void skillAttack(Monster *cel) override
    {
        std::cout << "Wykonujesz atak blyskawica i potwor otrzymuje: " << damage * 5 << " obrazen" << endl;
        cel->hp -= damage * 5;
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
    }
    void heal() override
    {
        std::cout << "Hp przed leczeniem: " << hp << endl;
        hp += 130;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
        std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << endl;
    }
    void showInfo() override
    {
        std::cout << "Nick: " << name << endl
                  << "Hp: " << hp << endl
                  << "Def: " << defense << endl
                  << "Dmg: " << damage << endl;
    }
};
class Archer : public Character
{

public:
    Archer(string name, int hp, int defense, int damage) : Character(name, hp, defense, damage)
    {
    }

    void baseAttack(Monster *cel) override
    {
        std::cout << "Strzelasz strzala, potwor dostal: " << damage * 2.5 << " obrazen" << endl;
        cel->hp -= damage * 2.5;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
    }
    void skillAttack(Monster *cel) override
    {
        std::cout << "strzelasz ognista strzala i potwor otrzymuje: " << damage * 6 << " obrazen" << endl;
        cel->hp -= damage * 6;
        std::cout << "Wykonujesz jebniecie z luku!" << endl;
        std::cout << "Pozostałe hp potwora: " << cel->hp << endl;
        if (cel->hp < 0)
        {
            cel->hp = 0;
            std::cout << "Pokonałeś potwora!!!";
        }
    }
    void heal() override
    {
        std::cout << "Hp przed leczeniem: " << hp << endl;
        hp += 50;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
        std::cout << "Teraz twoje hp wynosi:" << hp << " Hp" << endl;
    }
    void showInfo() override
    {
        std::cout << "Nick: " << name << endl
                  << "Hp: " << hp << endl
                  << "Def: " << defense << endl
                  << "Dmg: " << damage << endl;
    }
};

int main()
{
    Monster zombie("zombie");
    string nick;
    int health;
    int defense;
    int damage;
    string klasa_wybor;
    int klasa;
    Character *hero;
    int x = 4;
    int y = 3;

    std::cout << "Podaj nick: ";
    cin >> nick;

    while (y != 0)
    {
        std::cout << "Wybierz klasę (Warrior,Mage,Archer): ";
        cin >> klasa_wybor;
        if (klasa_wybor == "Warrior" || klasa_wybor == "warrior")
        {
            klasa = 1;
            y = 0;
        }
        else if (klasa_wybor == "Mage" || klasa_wybor == "mage")
        {
            klasa = 2;
            y = 0;
        }
        else if (klasa_wybor == "Archer" || klasa_wybor == "archer")
        {
            klasa = 3;
            y = 0;
        }
        else
        {
            std::cout << "Zla nazwa postaci" << endl;
        }
    }
    switch (klasa)
    {
    case 1:
    {
        health = 200;
        defense = 20;
        damage = 30;
        hero = new Warrior(nick, health, defense, damage);
    }
    break;
    case 2:
    {
        health = 120;
        defense = 10;
        damage = 50;
        hero = new Mage(nick, health, defense, damage);
    }
    break;
    case 3:
    {
        health = 150;
        defense = 15;
        damage = 40;
        hero = new Archer(nick, health, defense, damage);
    }
    break;
    default:
        break;
    }

    std::cout << "===Wybierz opcje od (1 do 9)===" << endl;
    std::cout << "1. pokaz info swojej postaci: " << endl;
    std::cout << "2. wykonaj podstawowy atak: " << endl;
    std::cout << "3. ulecz sie: " << endl;
    std::cout << "4. wykonaj uderzenie skillem: " << endl;
    std::cout << "5. budowa: " << endl;
    std::cout << "6. budowa: " << endl;
    std::cout << "7. budowa: " << endl;
    std::cout << "8. budowa: " << endl;
    std::cout << "9. koniec programu: " << endl;

    while (x != 0)
    {
        int chosenOption;

        cin >> chosenOption;
        switch (chosenOption)
        {
        case 1:
        {
            hero->showInfo();
        }
        break;
        case 2:
        {
            if (hero->checkHeroHp() > 0 && zombie.checkMonsterHp() > 0)
            {
                hero->baseAttack(&zombie);
                hero->receiveDamage(zombie.damage);
                zombie.monsterHeal();
            }
        }
        break;
        case 3:
        {
            hero->heal();
        }
        break;
        case 4:
        {
            if (hero->checkHeroHp() > 0 && zombie.checkMonsterHp() > 0)
            {
                hero->skillAttack(&zombie);
                hero->receiveDamage(zombie.damage);
                zombie.monsterHeal();
            }
        }
        break;
        case 5:
        {
            hero->showInfo();
        }
        break;
        case 6:
        {
            hero->showInfo();
        }
        break;
        case 7:
        {
            hero->showInfo();
        }
        break;
        case 8:
        {
            hero->showInfo();
        }
        break;
        case 9:
        {
            x = 0;
        }
        break;
        }
    }
    delete hero;
}
>>>>>>> cce9d068f950c83fc96eeb3a0156872a6ce3b2ba
