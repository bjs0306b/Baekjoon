#include <bits/stdc++.h>
using namespace std;

struct node{
    int s,e,c; 
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    vector<node> v(m);
    vector<long long> dis(n+1, INT64_MAX);
    dis[1] = 0;
    for(int i=0;i<m;i++) cin >> v[i].s >> v[i].e >> v[i].c;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int s = v[j].s, e = v[j].e, c = v[j].c;
            if(dis[s] == INT64_MAX) continue;
            dis[e] = min(dis[e], dis[s] + c);
        }
    }

    for(int i=0;i<m;i++){
        int s = v[i].s, e = v[i].e, c = v[i].c;
        if(dis[s] != INT64_MAX && dis[e] > dis[s] + c){
            cout << -1;
            return 0;
        }
    }

    for(int i=2;i<=n;i++){
        if(dis[i] == INT64_MAX) cout << "-1\n";
        else cout << dis[i] << "\n";
    }
    
    return 0;
}