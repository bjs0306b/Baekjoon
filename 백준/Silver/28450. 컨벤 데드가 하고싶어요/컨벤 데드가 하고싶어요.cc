#include <bits/stdc++.h>
using namespace std;

int a, b;
long long arr[1001][1001], arr2[1001][1001];
bool visited[1001][1001];
long long h;

struct Node {
    int x, y;
    long long cost;
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

void dijkstra() {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, 0, arr[0][0]});
    arr2[0][0] = arr[0][0];

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        
        int x = curr.x;
        int y = curr.y;
        long long cost = curr.cost;

        if (visited[x][y]) continue;
        visited[x][y] = true;

        if (x+1 < a && (!visited[x+1][y] && arr2[x+1][y] > cost + arr[x+1][y])) {
            arr2[x+1][y] = cost + arr[x+1][y];
            pq.push({x+1, y, arr2[x+1][y]});
        }

        if (y+1 < b && (!visited[x][y+1] && arr2[x][y+1] > cost + arr[x][y+1])) {
            arr2[x][y+1] = cost + arr[x][y+1];
            pq.push({x, y+1, arr2[x][y+1]});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cin >> arr[i][j];
            arr2[i][j] = LLONG_MAX;
        }
    }

    cin >> h;

    dijkstra();

    if (arr2[a-1][b-1] > h) cout << "NO";
    else cout << "YES\n" << arr2[a-1][b-1];
    
    return 0;
}
