#include <bits/stdc++.h>
using namespace std;

char A[12][6];
int ans = 0;
bool visited[12][6];
vector<pair<int,int>> temp;

void input(){
    for(int i=0;i<12;i++) for(int j=0;j<6;j++) cin >> A[i][j];
}

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
void dfs(int x, int y, char c){
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < 12 && ny >= 0 && ny < 6 && A[nx][ny] == c && !visited[nx][ny]){
            visited[nx][ny] = true;
            temp.push_back({nx,ny});
            dfs(nx,ny,c);
        }
    }
}

bool boom(){
    bool ret = false;
    for(int i=0;i<12;i++) for(int j=0;j<6;j++) visited[i][j] = false;
    
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            if(A[i][j] != '.' && !visited[i][j]){
                temp.clear();
                temp.push_back({i,j});
                visited[i][j] = true;
                dfs(i,j, A[i][j]);
                if(temp.size() > 3){
                    ret = true;
                    for(auto k : temp){
                        A[k.first][k.second] = '.';
                    }
                }
            }
        }
    }
    return ret;
}

void down(){
    for(int i=0;i<6;i++){
        vector<char> vv;
        for(int j=11;j>=0;j--) if(A[j][i] != '.') vv.push_back(A[j][i]);
        for(int j=0;j<vv.size();j++) A[11-j][i] = vv[j];
        for(int j=vv.size();j<12;j++) A[11-j][i] = '.';
    }
}

void solve(){
    while(boom()){
        ans++;
        down();
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();
    
    return 0;
}