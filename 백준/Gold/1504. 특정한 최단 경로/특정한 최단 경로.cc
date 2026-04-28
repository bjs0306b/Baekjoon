#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[801];
int dis[801][2][2];

struct node
{
    int n, c;    // node, cost
    bool f1, f2; // 특정 node 통과 여부

    bool operator<(const node other) const
    {
        return c > other.c;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        int c, d, e;
        cin >> c >> d >> e;
        v[c].push_back({e, d});
        v[d].push_back({e, c});
    }
    int p1, p2;
    cin >> p1 >> p2; // 지나야 하는 node

    for (int i = 1; i < 801; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                dis[i][j][k] = INT32_MAX;
    
    priority_queue<node> pq;
    if(p1 == 1){
        dis[1][1][0] = 0;
        pq.push({1, 0, 1, 0});
    }
    else{
        dis[1][0][0] = 0;
        pq.push({1, 0, 0, 0});
    }

    while (!pq.empty())
    {

        node cur = pq.top();
        pq.pop();

        if (dis[cur.n][cur.f1][cur.f2] >= cur.c)
        {
            for (auto k : v[cur.n])
            {
                int cost = k.first;
                int next_n = k.second;
                bool b1 = cur.f1, b2 = cur.f2;
                if (next_n == p1)
                    b1 = true;
                if (next_n == p2)
                    b2 = true;

                if (dis[next_n][b1][b2] > dis[cur.n][cur.f1][cur.f2] + cost)
                {
                    dis[next_n][b1][b2] = dis[cur.n][cur.f1][cur.f2] + cost;
                    pq.push({next_n, dis[next_n][b1][b2], b1, b2});
                }
            }
        }
    }

    if (dis[a][1][1] == INT32_MAX)
        cout << -1;
    else
        cout << dis[a][1][1];

    return 0;
}