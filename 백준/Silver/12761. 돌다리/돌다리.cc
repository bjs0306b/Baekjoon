#include <bits/stdc++.h>
using namespace std;

bool visited[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    visited[n] = true;
    queue<int> q;
    q.push(n);

    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int front = q.front();
            q.pop();
            if (front == m) {
                cout << ans;
                return 0;
            }

            if (front + 1 < 100001 && !visited[front + 1]) {
                q.push(front + 1);
                visited[front + 1] = true;
            }
            if (front - 1 >= 0 && !visited[front - 1]) {
                q.push(front - 1);
                visited[front - 1] = true;
            }
            if (front + a < 100001 && !visited[front + a]) {
                q.push(front + a);
                visited[front + a] = true;
            }
            if (front + b < 100001 && !visited[front + b]) {
                q.push(front + b);
                visited[front + b] = true;
            }
            if (front - a >= 0 && !visited[front - a]) {
                q.push(front - a);
                visited[front - a] = true;
            }
            if (front - b >= 0 && !visited[front - b]) {
                q.push(front - b);
                visited[front - b] = true;
            }
            if (front * a < 100001 && !visited[front * a]) {
                q.push(front * a);
                visited[front * a] = true;
            }
            if (front * b < 100001 && !visited[front * b]) {
                q.push(front * b);
                visited[front * b] = true;
            }
        }
        ans++;
    }

    return 0;
}