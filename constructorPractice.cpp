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
        : name{name_val}, health{health_val}, xp{xp_val} {}

    Player(const Player &s)
        : name(s.name), health(s.health), xp(s.xp) {}
    ~Player() {}
};

int main()
{
    Player bob;
    Player bernard{"Bernard"};
    {
        Player archimonde{"Archimonde", 100};
        Player DestroyerOfWorlds{"DOW", 500, 300};
    }

    int x;
    std::cin >> x;

    return 0;
}