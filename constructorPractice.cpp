#include <iostream>

using namespace std;

int id_counter{0};

class Player
{
private:
    string name;
    int health;
    int xp;
    int *id;

public:
    string getName() { return name; }
    int getHealth() { return health; }
    int getXp() { return xp; }
    int getID() { return *id; }

    Player(string name_val = "none", int health_val = 0, int xp_val = 0, int identifier = 0)
        : name{name_val}, health{health_val}, xp{xp_val}
    {

        id = new int;
        identifier = ++id_counter;
        *id = identifier;
        cout << "\nCreating: " << name_val;
    }

    Player(const Player &s)
        : name(s.name), health(s.health), xp(s.xp), id(s.id)
    {
        id = new int;
        *id = *s.id;
        cout << "\nCopying: " << name;
    }
    ~Player()
    {
        delete id;
        cout << "\nDestroying: " << name;
    }
};

void DisplayPlayer(Player p)
{
    cout << p.getName() << " " << p.getID();
}

int main()
{

    //test blocks
    {
        Player bob;
        Player bernard{"Bernard"};
        DisplayPlayer(bernard);
    }
    {
        Player otinanai{"Otinanai", 100};
        Player DestroyerOfWorlds{"DOW", 500, 300};
        DisplayPlayer(DestroyerOfWorlds);
    }
    {
        Player test{"TEST", 3000, 2000};
        Player testCopy{test};
    }

    int x;
    std::cin >> x;

    return 0;
}