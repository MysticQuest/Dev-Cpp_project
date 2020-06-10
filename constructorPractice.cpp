#include <iostream>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    string getName() { return name; }
    int getHealth() { return health; }
    int getXp() { return xp; }

    Player(string name_val = "none", int health_val = 0, int xp_val = 0)
        : name{name_val}, health{health_val}, xp{xp_val} { cout << "\nCreating: " << name_val; }

    Player(const Player &s)
        : name(s.name), health(s.health), xp(s.xp) { cout << "\nCopying: " << name; }
    ~Player() { cout << "\nDestroying: " << name; }
};

void DisplayPlayer(Player p)
{
    cout << p.getName();
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