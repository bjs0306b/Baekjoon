#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vec[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        vec[s].push_back({c, e});
    }

    int ans = 0;

    int from_x_dis[n + 1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> from_x_pq;
    from_x_pq.push({0, x});
    for (int i = 1; i <= n; i++)
        from_x_dis[i] = INT32_MAX;
    from_x_dis[x] = 0;
    while (!from_x_pq.empty())
    {
        int cur_node = from_x_pq.top().second;
        int cur_from_x_dis = from_x_pq.top().first;
        from_x_pq.pop();

        if (from_x_dis[cur_node] >= cur_from_x_dis)
        {
            for (auto k : vec[cur_node])
            {
                int next_node = k.second;
                int weight = k.first;

                if (from_x_dis[next_node] > from_x_dis[cur_node] + weight)
                {
                    from_x_dis[next_node] = from_x_dis[cur_node] + weight;
                    from_x_pq.push({from_x_dis[next_node], next_node});
                }
            }
        }
    }

    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (i != x)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            for (int j = 1; j <= n; j++)
                dis[j] = INT32_MAX;
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
        }
        ans = max(ans, dis[x] + from_x_dis[i]);
    }
    cout << ans;

    return 0;
}