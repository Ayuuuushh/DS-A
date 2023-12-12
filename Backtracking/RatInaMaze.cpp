#include <bits/stdc++.h> 
#include <vector>
using namespace std;

bool isSafe(int newx, int newy,vector < vector < bool >>& visited,
vector < vector < int >> &arr,int n  ){

    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && 
    visited[newx][newy]!=1 && arr[newx][newy]!=0 )
    return true;

    return false;
}



void solve(int x, int y,vector < vector < int >>& arr, int n, 
vector<string> &ans, string path, vector < vector < bool >>& visited ){

    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    //D L R U

    visited[x][y]=true;

    //DOWN
    if(isSafe(x+1,y,visited,arr,n)){
        solve(x+1, y, arr, n, ans, path+'D', visited);
    }
    //LEFT
    if(isSafe(x,y-1,visited,arr,n)){
        solve(x, y-1, arr, n, ans, path+'L', visited);
    }
    if(isSafe(x,y+1,visited,arr,n)){
        solve(x, y+1, arr, n, ans, path+'R', visited);
    }
    if(isSafe(x-1,y,visited,arr,n)){
        solve(x-1, y, arr, n, ans, path+'U', visited);
    }

    visited[x][y]=false;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
   
   vector<string> ans;
   vector<vector<bool>> visited(n,vector<bool>(n,0));
   string path="";

   if(arr[0][0]==0)
   return ans;
    
   solve(0,0,arr,n,ans,path, visited);

   return ans;

}


int main(){

    vector<vector<int>> arr=
    {{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
        cout << endl;
  
    vector<string> ans;
    cout << "POSSIBLE PATH : " ;
    ans=searchMaze(arr,4);

     for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] <<" ";
        }
        cout << ", ";
    }


    return 0;
}