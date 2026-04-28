#include <bits/stdc++.h>
using namespace std;

int n,m; 
vector<int> v[10001];
int cnt[10001];
int mx = 0;
bool visited[10001];

int dfs(int num){
    int ret = 1;
    for(auto k : v[num]){
        if(!visited[k]){
            visited[k] = true;
            ret += dfs(k);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<10001;j++) visited[j] = false;
        visited[i] = true;
        cnt[i] = dfs(i);
        mx = max(mx, cnt[i]);
    }
    for(int i=1;i<=n;i++) if(cnt[i] == mx) cout << i << " ";
    
    
    return 0;
}