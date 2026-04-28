#include <bits/stdc++.h>
using namespace std;
int n,m,r;
priority_queue<int> pq[100001];
bool visited[100001];
int ans[100001];
int cnt;
void dfs(int node){
    ans[node] = ++cnt;
    while(!pq[node].empty()){
        int top = pq[node].top(); pq[node].pop();
        if(!visited[top]){
            visited[top] = true; dfs(top);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;
    while(m--){
        int a,b; cin >> a >> b;
        pq[a].push(b);
        pq[b].push(a);
    }
    visited[r] = true;
    dfs(r);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
    return 0;
}