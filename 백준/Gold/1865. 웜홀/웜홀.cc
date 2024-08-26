#include <bits/stdc++.h>
using namespace std;

long long dis[501]; // int32_max + 양수 하면 int의 경우 overflow 발생.
int a, b, c;                              // node, + 간선, - 간선 수
vector<pair<int, pair<int, int>>> vec; 

bool bford(int start)
{
    for (int j = 1; j <= a; j++) dis[j] = INT32_MAX;
    dis[start] = 0;

    for (int k = 1; k <= a; k++)
    {
        for (auto n : vec)
        {
            int from = n.first;
            int to = n.second.first;
            int cost = n.second.second;

            if (dis[to] > dis[from] + cost)
            {
                dis[to] = dis[from] + cost;
                if (k == a) return true;
            }     
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        while (b--)
        {
            int s, e, w;
            cin >> s >> e >> w;
            vec.push_back({s, {e, w}});
            vec.push_back({e,{s,w}});
        }
        while (c--)
        {
            int s, e, w;
            cin >> s >> e >> w;
            w = -1 * w;
            vec.push_back({s, {e, w}});
        }

        if(bford(1)) cout << "YES\n";
        else cout << "NO\n";
        vec.clear();
    }

    return 0;
}