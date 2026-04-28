#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[50][50]; // 벽 정보
int B[50][50]; // 각 위치의 방 번호.
int cnt;
bool visited[50][50];
vector<int> room_size;

void input(){
    cin >> n >> m;
    swap(n,m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];
}

int dx[] = {0,-1,0,1}, dy[] = {-1,0,1,0};
void dfs(int x, int y, int idx){
    B[x][y] = idx;
    cnt++;
    for(int i=0;i<4;i++){
        if((A[x][y] & (1<<i)) != 0) continue; // 벽이 있음.
        //
        int nx = x + dx[i] , ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx, ny, idx);
        }
    }
}

void solve(){
    int idx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                cnt = 0;
                dfs(i,j, idx);
                idx++;
                room_size.push_back(cnt);
            }
        }
    }

    int ans_3 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(B[i][j] != B[nx][ny]){
                        int sum = room_size[B[i][j]] + room_size[B[nx][ny]];
                        ans_3 = max(ans_3, sum);
                    }
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << B[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // for(auto k : room_size) cout << k << " ";

    cout << room_size.size() << "\n" << *max_element(room_size.begin(), room_size.end()) << "\n" << ans_3;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}