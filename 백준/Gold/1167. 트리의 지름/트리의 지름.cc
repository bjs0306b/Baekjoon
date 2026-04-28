#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> vec[n + 1];

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        for (;;)
        {
            int a, b;
            cin >> a;
            if (a == -1)
                break;
            cin >> b;

            vec[num].push_back({a, b}); // next_node, weight
            vec[a].push_back({num, b});
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    int dis[n + 1];
    fill(dis, dis + n + 1, INT32_MAX);
    dis[1] = 0;
    while (!pq.empty())
    {
        int cur_node = pq.top().second;
        int cur_dis = pq.top().first;
        pq.pop();

        if (dis[cur_node] >= cur_dis)
        {
            for (auto k : vec[cur_node])
            {
                int next_node = k.first;
                int weight = k.second;

                if (dis[next_node] > dis[cur_node] + weight)
                {
                    dis[next_node] = dis[cur_node] + weight;
                    pq.push({dis[next_node], next_node});
                }
            }
        }
    }

    int max_node = max_element(dis + 1, dis + n + 1) - dis;

    pq.push({0, max_node});

    fill(dis, dis + n + 1, INT32_MAX);
    dis[max_node] = 0;
    while (!pq.empty())
    {
        int cur_node = pq.top().second;
        int cur_dis = pq.top().first;
        pq.pop();

        if (dis[cur_node] >= cur_dis)
        {
            for (auto k : vec[cur_node])
            {
                int next_node = k.first;
                int weight = k.second;

                if (dis[next_node] > dis[cur_node] + weight)
                {
                    dis[next_node] = dis[cur_node] + weight;
                    pq.push({dis[next_node], next_node});
                }
            }
        }
    }

    cout << *max_element(dis + 1, dis + n + 1);

    return 0;
}