#include <bits/stdc++.h>
using namespace std;

bool arr[5][5];
bool selected[25];
int ans;
bool over_four(){
    int cnt = 0;
    for(int i=0;i<25;i++) if(selected[i] && arr[i/5][i%5]) cnt++;
    if(cnt > 3) return true;
    else return false;
}

bool is_one_body(){
    
    int x,y;

    bool visited[5][5]; for(int i=0;i<5;i++) for(int j=0;j<5;j++) visited[i][j] = 0;
    bool temp[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(selected[i*5+j]){temp[i][j] = 1; x= i, y = j;}
            else temp[i][j] = 0;
        }
    }

    queue<pair<int,int>> q;
    q.push({x,y});
    int cnt = 1;
    visited[x][y] = 1;

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

        for(int i=0;i<4;i++){
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >=0 && tx < 5 && ty >= 0 && ty < 5){
                if(!visited[tx][ty] && temp[tx][ty]){
                    visited[tx][ty] = 1;
                    cnt++;
                    q.push({tx,ty});   
                }
            } 
        }
    }
    if(cnt == 7) return true;
    return false;

}

void dfs(int n, int cnt){
    if(cnt == 7){
        if(over_four() && is_one_body()){
            ans++;
        }
    }
    else{
        for(int i=n;i<25;i++){
            if(!selected[i]){
                selected[i] = true;
                dfs(i+1, cnt+1);
                selected[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<5;i++) for(int j=0;j<5;j++){
        char c; cin >> c;
        if(c == 'S') arr[i][j] = 1;
    }

    dfs(0,0);

    cout << ans;

    return 0;
}