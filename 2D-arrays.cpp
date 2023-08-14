#include <bits/stdc++.h>
using namespace std;

string IsFounded(int arr[][3], int target, int row, int col)
{
    row = 4;
    col = 3;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == target)
            {
                return "Target Founded";
            }
            /* code */
        }
    }
    return "Not Found Error 404";
}

int Maxi (int arr[][3]){

int  Mx = INT_MIN;
int count  = 0;
int MaxInd = -1 ;
     for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            count += arr[i][j];
        }
       if(Mx < count){
        Mx = count ;
        MaxInd = i ;
       }
        count = 0;
    }
    return MaxInd + 1;
}

void printSum(int arr[][3])
{
    int arr1[4];
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            count += arr[i][j];
        }
        arr1[i] = count;
        count = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "r" << i + 1 << " : " << arr1[i] << endl;
    }
}



int main()
{
    int arr[4][3];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            cin >> arr[i][j];
        }
        cout << endl;
    }

    int target;
    cout << "Enter the number you wanted to search : ";
    cin >> target;
    cout << IsFounded(arr, target, 4, 3);

    printSum(arr);

    cout << " Maximum Out of the Rows is : "<<Maxi(arr);

    return 0;
}