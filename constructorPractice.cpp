#include <iostream>
#include <vector>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;
    int *id;

public:
    static int id_counter;
    string setName(string name) { this->name = name; }
    string getName() const { return name; }
    int getHealth() { return health; }
    int getXp() { return xp; }
    int getID() const { return *id; }

    Player(int health_val)
        : health{health_val} { cout << "\nCreating number Obj: " << health_val; }

    Player(string name_val = "none", int health_val = 0, int xp_val = 0, int identifier = 0)
        : name{name_val}, health{health_val}, xp{xp_val}
    {

        id = new int;
        identifier = ++id_counter;
        *id = identifier;
        cout << "\nCreating normal Obj: " << name_val;
    }

    Player(const Player &s)
        : name(s.name), health(s.health), xp(s.xp), id(s.id)
    {
        id = new int;
        *id = *s.id;
        cout << "\nCopying (deep): " << name;
    }
    // //By delegation - a delegating constructor cannot have other mem-initializers
    // Player(const Player &s)
    //     : name(s.name), health(s.health), xp(s.xp), Player{*s.id}
    // {
    //     cout << "\nCopying: " << name;
    // }

    Player(Player &&s)
        : name(s.name), health(s.health), xp(s.xp), id{s.id}
    {
        s.id = nullptr;
        cout << "\nMoving: " << name;
    }
    ~Player()
    {
        delete id;
        cout << "\nDestroying: " << name;
    }
};

int Player::id_counter{0};

void DisplayPlayer(const Player &p)
{
    cout << "\n***DISPLAYING***: " << p.getName() << " " << p.getID();
}

int main()
{

    //test blocks
    {
        vector<Player> vec;
        vec.push_back(Player{"test1", 10, 5});
        vec.push_back(Player{"test2", 10, 5});
        DisplayPlayer(vec[1]);
        vec.push_back(Player{"test3", 10, 5});
    }
    {
        cout << endl;
    }
    {
        Player bob;
        Player bernard{"Bernard"};
        DisplayPlayer(bernard);
    }
    {
        cout << endl;
    }
    {
        Player otinanai{"Otinanai", 100};
        const Player Dow{"DestroyerOfWorlds", 500, 300};
        DisplayPlayer(Dow);
    }
    {
        cout << endl;
    }
    {
        Player placeholder{"TEST", 3000, 2000};
        Player placeholderCopy{placeholder};
    }

    int x;
    std::cin >> x;

    return 0;
}