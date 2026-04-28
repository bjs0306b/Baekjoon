#include <bits/stdc++.h>
using namespace std;

char A[5][5];
set<string> st;

void input(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> A[i][j];
        }
    }
}

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
void dfs(int x, int y, int dep, string s){
    if(dep == 5){
        st.insert(s);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) dfs(nx,ny,dep+1, s+A[nx][ny]);
    }
}

void solve(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            string temp = "";
            temp += A[i][j];
            dfs(i,j,0,temp);
        }
    }
    cout << st.size();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}