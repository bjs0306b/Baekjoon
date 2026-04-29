#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

void solve(){
    int n; cin >> n;
    int A[n][n]; 
    bool visited[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){cin >> A[i][j]; visited[i][j] = false;}
    int x_s, x_e, y_s, y_e; cin >> x_s >> y_s >> x_e >> y_e;
    
    queue<pair<int,int>> q;
    q.push({x_s, y_s});
    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto f = q.front();
            q.pop();
            if(f.first == x_e && f.second == y_e){
                cout << cnt << "\n";
                return;
            }

            bool flag = false;
            for(int j=0;j<4;j++){
                int nx = f.first + dx[j], ny = f.second + dy[j];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && A[nx][ny] != 1){
                    if(cnt % 3 != 2 && A[nx][ny] == 2){
                        flag = true;
                        continue;
                    }
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            if(flag) q.push(f);
        }
        cnt++;
    }
    cout << "-1\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for(int i=1;i<=t;i++){
        cout << "#" << i << " ";
        solve();
    }

    return 0;
}