#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[1001];      // 1번에서 해당 노드까지의 최대 거리
int parent[1001];    // 경로 역추적을 위한 부모 노드 저장
int indegree[1001];  // 진입 차수
vector<pair<int, int>> adj[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        indegree[v]++;
    }
}

void solve() {
    queue<int> q;
    
    // [사실] 1번에서 출발하므로 1번을 큐에 넣고 시작합니다.
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // [추론] 1번 노드는 시작점이자 도착점입니다. 
        // 한 번 출발한 이후 다시 1번에 도달했다면, 거기서 더 나가는 경로는 고려하지 않습니다.
        if (curr == 1 && dist[1] > 0) continue;

        for (auto& edge : adj[curr]) {
            int next = edge.first;
            int weight = edge.second;

            // [사실] 더 큰 가중치를 발견하면 거리와 부모를 갱신합니다. (DP)
            if (dist[next] < dist[curr] + weight) {
                dist[next] = dist[curr] + weight;
                parent[next] = curr;
            }

            // 위상 정렬: 진입 차수를 줄이고 0이 되면 큐에 삽입
            indegree[next]--;
            
            // [추론] 1번 노드는 모든 중간 노드를 거친 후 마지막에 처리되어야 하므로 
            // 진입 차수가 0이 되더라도 큐에 넣지 않습니다.
            if (indegree[next] == 0 && next != 1) {
                q.push(next);
            }
        }
    }

    // 결과 출력
    cout << dist[1] << "\n";

    // 경로 역추적 (parent 배열 이용)
    vector<int> path;
    int curr = 1;
    path.push_back(1);
    
    // [사실] 1번으로 돌아왔으므로, 역순으로 parent를 타고 올라가면 경로가 완성됩니다.
    curr = parent[1];
    while (curr != 1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(1);
    
    // 역순으로 저장되었으므로 다시 뒤집어서 출력
    reverse(path.begin(), path.end());
    for (int node : path) cout << node << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}