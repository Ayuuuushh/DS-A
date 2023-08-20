#include<bits/stdc++.h>
using namespace std;

//Inheritance
class Human{  //parent class/super class
public:
int height;
int weight;
int age;
public:
int getAge(){
    return age;
}
void setWeight(int weight){
    this->weight = weight;
}
void setAge(int age){
    this->age = age;
}
};
//Male class inheriting the property of human class
class Male : public Human{

    public:
    string color;

    void sleep(){
        cout <<" Male sleeping"<< endl;

    }
};
int main(){
   Male Adam;
   Adam.setWeight(45);
   Adam.setAge(34);
  cout << Adam.getAge();
   Adam.sleep();

return 0 ;
}