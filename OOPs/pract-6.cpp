#include<bits/stdc++.h>
using namespace std;

//Polymorphism
class B{
public:
// Function overloading
void say(){
    cout <<"hi";
}
void say(string s){
    cout <<"hello " <<s;
}
// operator overloading
void operator+ (B &obj2){
    cout <<"Hello Ayush";

}
};
int main(){
B obj;
B obj2;
obj + obj2;
string s = "Ayush";
obj.say(s);
   
return 0 ;
}