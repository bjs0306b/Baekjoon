#include <bits/stdc++.h>
using namespace std;

vector<int> v[2000];
bool visited[2000];

void dfs(int num, int depth){
    if(depth == 4){
        cout << 1;
        exit(0);
    }
    for(auto k : v[num]){
        if(!visited[k]){
            visited[k] = true;
            dfs(k, depth+1);
            visited[k] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        visited[i] = true;
        dfs(i,0);
        visited[i] = false;
    }
    cout << 0;

    return 0;
}