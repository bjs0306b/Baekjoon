#include <bits/stdc++.h>
using namespace std;

double cnt;

vector<int> v[500001];
bool visited[500001];

void dfs(int n){
    bool flag = false;
    for(int i=0;i<v[n].size();i++){
        if(!visited[v[n][i]]){
            flag = true;
            visited[v[n][i]] = true;
            dfs(v[n][i]);
        }
    }
    if(!flag) cnt++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double m;
    cin >> n >> m;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }
    visited[1] = true;
    dfs(1);

    printf("%.10f",m / cnt);

    return 0;
}