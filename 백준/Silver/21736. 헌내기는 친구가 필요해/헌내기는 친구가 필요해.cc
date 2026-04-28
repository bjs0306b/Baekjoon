#include<bits/stdc++.h>
using namespace std;

char arr[600][600]; 
int x,y; 
int ans = 0;
void dfs(int a, int b){
    if(a+1 < x && arr[a+1][b] != 'X'){
        if(arr[a+1][b] == 'P') ans++;
        arr[a+1][b] = 'X';
        dfs(a+1, b);
    }

    if(a > 0 && arr[a-1][b] != 'X'){
        if(arr[a-1][b] == 'P') ans++;
        arr[a-1][b] = 'X';
        dfs(a-1, b);
    }

    if(b+1 < y && arr[a][b+1] != 'X'){
        if(arr[a][b+1] == 'P') ans++;
        arr[a][b+1] = 'X';
        dfs(a, b+1);
    }

    if(b > 0 && arr[a][b-1] != 'X'){
        if(arr[a][b-1] == 'P') ans++;
        arr[a][b-1] = 'X';
        dfs(a, b-1);
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> x >> y;
    
    int cur_x, cur_y;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'I'){
                cur_x = i; cur_y = j;
            }
        }
    }
    arr[cur_x][cur_y] = 'X';
    dfs(cur_x, cur_y);
    
    if(ans) cout << ans;
    else cout << "TT";

    return 0;
}