#include<bits/stdc++.h>
using namespace std;
class Game{
    
    public:
    int health;
    char level;
};

int main(){
    //to set data in data member in public access modifier
   Game Ayush;
   Ayush.health = 70;
   Ayush.level = 'A';

   cout << "Health : " << Ayush.health << endl;
   cout << "Level : " << Ayush.level;

return 0 ;
}