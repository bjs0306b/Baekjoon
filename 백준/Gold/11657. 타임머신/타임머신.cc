#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> dis(n, INT64_MAX);
    dis[0] = 0;
    vector<pair<pair<int, int>, int>> v(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        v[i] = {{a, b}, c};
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a = v[j].first.first, b = v[j].first.second, c = v[j].second;
            if (dis[a] != INT64_MAX)
            {
                dis[b] = min(dis[b], dis[a] + c);
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        int a = v[j].first.first, b = v[j].first.second, c = v[j].second;
        if (dis[a] != INT64_MAX)
        {
            if(dis[b] > dis[a] + c){
                cout << -1;
                return 0;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(dis[i] == INT64_MAX) cout << "-1\n";
        else cout << dis[i] << "\n";
    }

    return 0;
}