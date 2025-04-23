#include <bits/stdc++.h>
using namespace std;

vector<int> light[100], heavy[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        light[a].push_back(b);
        heavy[b].push_back(a);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        queue<int> q; q.push(i);
        vector<bool> visited(n, false);
        int cnt = 0;
        while(!q.empty()){
            int front = q.front(); q.pop();
            for(auto k : light[front]){
                if(!visited[k]){
                    visited[k] = true;
                    q.push(k);
                    cnt++;
                }
            }
        }
        if(n/2 < cnt) ans++;
    }
    for(int i=1;i<=n;i++){
        queue<int> q; q.push(i);
        vector<bool> visited(n, false);
        int cnt = 0;
        while(!q.empty()){
            int front = q.front(); q.pop();
            for(auto k : heavy[front]){
                if(!visited[k]){
                    visited[k] = true;
                    q.push(k);
                    cnt++;
                }
            }
        }
        if(n/2 < cnt) ans++;
    }
    cout << ans;

    return 0;
}