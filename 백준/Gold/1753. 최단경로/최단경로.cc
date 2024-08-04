#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vec[20001];
int dis[20001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dis[start] = 0;

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_dist > dis[current_node]) continue;

        for (auto &edge : vec[current_node]) {
            int next_node = edge.first;
            int weight = edge.second;

            if (dis[next_node] > dis[current_node] + weight) {
                dis[next_node] = dis[current_node] + weight;
                pq.push({dis[next_node], next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int v, e; cin >> v >> e;
    int k; cin >> k;
    fill(dis, dis + 20001, INT32_MAX);

    for (int i = 0; i < e; i++) {
        int a, b, w; cin >> a >> b >> w;
        vec[a].push_back({b, w});
    }

    dijkstra(k);

    for (int i = 1; i <= v; i++) {
        if (dis[i] == INT32_MAX) cout << "INF\n";
        else cout << dis[i] << "\n";
    }
    return 0;
}