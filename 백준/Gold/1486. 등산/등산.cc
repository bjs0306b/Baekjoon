#include <bits/stdc++.h>
using namespace std;

int n,m,t,d;
int mx = 0;
int A[25][25];
int mn[625][625];
vector<pair<int,int>> v[625];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

bool isIn(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void input(){
    cin >> n >> m >> t >> d;
    for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++){
            char c; cin >> c;
            int num = c - 'A';
            if(num >= 32) num -= 6;
            A[i][j] = num;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(!isIn(nx,ny)) continue;
                int dif = abs(A[i][j] - A[nx][ny]);
                if(dif > t) continue;

                if(A[i][j] < A[nx][ny]) v[i*m+j].push_back({dif*dif, nx*m+ny});
                else v[i*m+j].push_back({1, nx*m+ny});
            }
        }
    }
}

void dijkstra(int from){
    vector<int> dis(n*m, INT32_MAX);
    dis[from] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, from});
    while(!pq.empty()){
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dis[cur] < d) continue;

        for(auto k : v[cur]){
            int cost = k.first;
            int next = k.second;
            if(dis[next] > dis[cur] + cost){
                dis[next] = dis[cur] + cost;
                pq.push({dis[next], next});
            }
        }
    }

    for(int i=0;i<n*m;i++){
        mn[from][i] = dis[i];
    }
}

void solve(){
    for(int i=0;i<n*m;i++) dijkstra(i);
    int ans = 0;
    for(int i=0;i<n*m;i++){
        if(mn[0][i] == INT32_MAX || mn[i][0] == INT32_MAX) continue;
        if(mn[0][i] + mn[i][0] <= d){
            ans = max(ans, A[i/m][i%m]);
        }
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}