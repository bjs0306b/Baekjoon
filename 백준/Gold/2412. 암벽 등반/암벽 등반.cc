#include <bits/stdc++.h>
using namespace std;

int n,t;
vector<int> v[200001];
map<pair<int,int>, bool> visited;
void input(){
    cin >> n >> t;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        v[b].push_back(a);
    }
}

int solve(){
    queue<pair<int,int>> q;
    q.push({0,0});

    int cnt = 1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int j=y-2;j<=y+2;j++){
                if(!(j >= 0 && j <= t)) continue;
                for(auto k : v[j]){
                    if(abs(k - x) <= 2){
                        if(j == t) return cnt;
                        if(!visited[{k,j}]){
                            q.push({k,j});
                            visited[{k,j}] = true;
                        }
                    }
                }
            }
            
        }
        cnt++;
    }
    return -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}