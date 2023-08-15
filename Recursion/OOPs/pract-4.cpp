#include <bits/stdc++.h>
using namespace std;

class Game
{
public:
    int health;
    char level;
    char *name;
    static int timeToComplete;


    // Constructor
    Game()
    {
        cout << "Constructor called " << endl;
        name = new char[200];
    }

    // parametrized constructor
    Game(int health)
    {
        this->health = health;
    }
    Game(int health, char level)
    {
        this->health = health;
        this->level = level;
    }

    // copy constructor
    Game(Game &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

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
    void setlevel(char l)
    {
        level = l;
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }
    void print()
    {
        cout << endl
             << "[";
        cout << health << ",";
        cout << level << ",";
        cout << this->name << "]" << endl;
    }

    // manually destructor called for static allocation
    ~Game(){
        cout <<" Destructor called " << endl;
    }

    //static function
    static int random(){
        return timeToComplete;
    }
};

int Game :: timeToComplete = 5;
 

int main()

{
    // statically
    cout << Game::timeToComplete;
    cout <<Game::random();
    Game ramesh;
    char name[6] = "Ayush";

    // cout << ramesh.getHealth() << endl;
    // cout << ramesh.getlevel() << endl;
    ramesh.sethealth(40);
    ramesh.setlevel('F');
    ramesh.setName(name);
    ramesh.print();


    Game ritesh = ramesh;
    ramesh.name[0] = 'a';
    cout <<"Ramesh";
    ramesh.print();
    cout <<"Ritesh";
    ritesh.print();

    // dynamically
    Game *abdul = new Game;
    //manually calling destructor
    delete abdul;
    return 0;
}