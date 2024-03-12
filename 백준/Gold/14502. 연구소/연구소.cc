#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int arr[8][8];
int a,b, mx = 0;
vector<pair<int,int>> v;

void dfs2(int x, int y){
    if(x-1 >= 0 && arr[x-1][y] == 0){
        arr[x-1][y] = 3;
        dfs2(x-1, y);
    }
    if(x+1 < a && arr[x+1][y] == 0){
        arr[x+1][y] = 3;
        dfs2(x+1, y);
    }
    if(y-1 >= 0 && arr[x][y-1] == 0){
        arr[x][y-1] = 3;
        dfs2(x, y-1);
    }
    if(y+1 < b && arr[x][y+1] == 0){
        arr[x][y+1] = 3;
        dfs2(x, y+1);
    }
}

void dfs1(int n){
    if(n == 3){
        for(auto k : v) dfs2(k.first, k.second);
        int cnt = 0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(arr[i][j] == 0) cnt++;
            }
        }
        mx = max(mx, cnt);
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(arr[i][j] == 3) arr[i][j] = 0;
            }
        }
    
    }
    else{
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(arr[i][j] == 0){
                    arr[i][j] = 1;
                    dfs1(n+1);
                    arr[i][j] = 0;
                }
            }
        }
    
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
     cin >> a >> b;
    
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) v.push_back({i,j});
        }
    }  
    dfs1(0);
    cout << mx;
    
    return 0;
}