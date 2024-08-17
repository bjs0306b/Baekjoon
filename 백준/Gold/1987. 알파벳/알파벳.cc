#include<bits/stdc++.h>
using namespace std;

char arr[20][20]; // 알파벳 배열 저장
bool visited[20][20]; // 위치 방문
bool alphabet[26]; // 알파벳 방문
int a,b;
int ans = 0;

void dfs(int x, int y, int cnt){
    ans = max(ans, cnt);

    if(x + 1 < a && !visited[x+1][y] && !alphabet[arr[x+1][y]-'A']){
        visited[x+1][y] = 1;
        alphabet[arr[x+1][y]-'A'] = 1;

        dfs(x+1, y, cnt+1);

        visited[x+1][y] = 0;
        alphabet[arr[x+1][y]-'A'] = 0;
    }

    if(x > 0 && !visited[x-1][y] && !alphabet[arr[x-1][y]-'A']){
        visited[x-1][y] = 1;
        alphabet[arr[x-1][y]-'A'] = 1;

        dfs(x-1, y, cnt+1);

        visited[x-1][y] = 0;
        alphabet[arr[x-1][y]-'A'] = 0;
    }

    if(y + 1 < b && !visited[x][y+1] && !alphabet[arr[x][y+1]-'A']){
        visited[x][y+1] = 1;
        alphabet[arr[x][y+1]-'A'] = 1;

        dfs(x, y+1, cnt+1);

        visited[x][y+1] = 0;
        alphabet[arr[x][y+1]-'A'] = 0;
    }

    if(y > 0 && !visited[x][y-1] && !alphabet[arr[x][y-1]-'A']){
        visited[x][y-1] = 1;
        alphabet[arr[x][y-1]-'A'] = 1;

        dfs(x, y-1, cnt+1);

        visited[x][y-1] = 0;
        alphabet[arr[x][y-1]-'A'] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[i][j];
    visited[0][0] = 1;
    alphabet[arr[0][0]-'A']=1;
    dfs(0,0,1); 
    cout << ans;
    return 0;
}