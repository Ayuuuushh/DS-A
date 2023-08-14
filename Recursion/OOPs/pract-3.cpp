#include <bits/stdc++.h>
using namespace std;
class Game
{
private:
    int health;

public:
    char level;

    // to use the private data access modifier
    /// we use getter/setter

    // getter
    int getHealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }

    // setter
    void sethealth(int h)
    {
        health = h;
    }
    void setlevel(int l)
    {
        level = l;
    }
};
int main()
{
    //static allocation
    Game Ayush;
    Ayush.sethealth(70);
    Ayush.setlevel('A');
    cout << "Health : " << Ayush.getHealth() << endl;
    cout << "Level : " << Ayush.getlevel() << endl;

    //dynamic allocation
    Game *ritesh= new Game;
    cout << "Health : " << (*ritesh).getHealth() << endl;
    cout << "Level : " << (*ritesh).level;


    return 0;
}