#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int arr[64][64];
void dfs(int x, int y, int size){
    if(size == 1){
        cout << arr[x][y];
        return;
    }
    bool flag = true;
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(arr[x][y] != arr[i][j]){
                flag = false;
                cout << "(";
                dfs(x,y,size/2);
                dfs(x,y+size/2,size/2);
                dfs(x+size/2,y,size/2);
                dfs(x+size/2,y+size/2,size/2);
                cout << ")";
                return;
            }
        }
    }
    if(flag) cout << arr[x][y];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<n;j++) arr[i][j] = s[j]-'0';
    }    
    dfs(0,0,n);
    
    return 0;
}