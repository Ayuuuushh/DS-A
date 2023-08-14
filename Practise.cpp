#include <bits/stdc++.h>
using namespace std;
int valid(char ch)
{
   if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
   {
      return 1;
   }
   return 0;
}

char low(char ch)
{
   int temp = ch;
   if (temp >= 'A' && temp <= 'Z')
   {
      temp = temp - 'A' + 'a';
      return temp;
   }
   return ch;
}
bool check(string temp)
{
   int st = 0;
   int e = temp.length() - 1;
   while (st <= e)
   {
      if (temp[st] != temp[e])
      {
         return 0;
      }
      else
      {
         st++;
         e--;
      }
   }
   return 1;
}
string isPalindrome(string s)
{
   string temp = "";
   for (int i = 0; i <= s.length() - 1; i++)
   {
      if (valid(s[i]))
      {
         temp[i] = s[i];
         temp[i] = low(temp[i]);
      }
   }
   return temp;
}
int main()
{
   string s = "Ayush";
   cout << isPalindrome(s);

   return 0;
}