#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int value[101];
int dis[101];
vector<pair<int, int>> vec[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> value[i];
    for (int i = 0; i < r; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        vec[s].push_back({w, e});
        vec[e].push_back({w, s});
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        fill(dis, dis + 101, m + 1);
        dis[i] = 0;

        while (!pq.empty())
        {
            int cur_node = pq.top().second;
            int cur_dis = pq.top().first;
            pq.pop();

            if (dis[cur_node] >= cur_dis)
            {
                for (auto k : vec[cur_node])
                {
                    int next_node = k.second;
                    int weight = k.first;

                    if (dis[next_node] > dis[cur_node] + weight)
                    {
                        dis[next_node] = dis[cur_node] + weight;
                        pq.push({dis[next_node], next_node});
                    }
                }
            }
        }
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] <= m)
            {
                sum += value[j];
            }
        }

        // cout << i << ": " << sum << "\n";
        // for(int j=1;j<=n;j++) cout << dis[j] << " ";
        // cout << "\n";
        ans = max(sum , ans);
    }
    cout << ans;

    return 0;
}