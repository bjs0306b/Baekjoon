#include<bits/stdc++.h>
using namespace std;

int a,b; 
bool check[1000][1000];
char arr[1000][1000];

void dfs(int x, int y){


    if(arr[x][y] == 'D' && x+1 < a && !check[x+1][y]){
        check[x+1][y] = true;
        dfs(x+1,y);
    }
    else if(arr[x][y] == 'U' && x > 0 && !check[x-1][y]){
        check[x-1][y] = true;
        dfs(x-1,y);
    }
    else if(arr[x][y] == 'L' && y > 0 && !check[x][y-1]){
        check[x][y-1] = true;
        dfs(x,y-1);
    }
    else if(arr[x][y] == 'R' && y+1 < b && !check[x][y+1]){
        check[x][y+1] = true;
        dfs(x,y+1);
    }

    if(x+1<a && arr[x+1][y] == 'U' && !check[x+1][y]){
        check[x+1][y] = true;
        dfs(x+1, y);
    }
    if(x>0 && arr[x-1][y] == 'D' && !check[x-1][y]){
        check[x-1][y]= true;
        dfs(x-1,y);
    }
    if(y+1<b && arr[x][y+1] == 'L' && !check[x][y+1]){
        check[x][y+1]=true;
        dfs(x,y+1);
    }
    if(y>0 && arr[x][y-1] == 'R' && !check[x][y-1]){
        check[x][y-1]=true;
        dfs(x, y-1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;

    
    for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[i][j];

    int cnt = 0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(!check[i][j]){
                check[i][j] = true;
                cnt++;
                dfs(i,j);       
            }
        }
    }
    cout << cnt;

    
    return 0;
}