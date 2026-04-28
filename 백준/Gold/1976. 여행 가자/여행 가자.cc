#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int dis[n][n]; for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> dis[i][j];
            if(i != j && dis[i][j] == 0) dis[i][j] = 1000000;
        }
    }
    vector<int> v(m); for(int i=0;i<m;i++){cin >> v[i]; v[i]--;}

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dis[j][k] = min(dis[j][k], dis[j][i]+dis[i][k]);
            }
        }
    }

    for(int i=0;i<m-1;i++){
        if(dis[v[i]][v[i+1]] == 1000000){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}