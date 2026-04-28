#include <bits/stdc++.h>
using namespace std;

int pluss[1001], multi[1001];
bool visited[1001];
void bfs()
{
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    { 
        int front = q.front();
        q.pop();
        if (!visited[front * 2] && front * 2 < 1001)
        {
            q.push(front * 2);
            visited[front * 2] = true;
            pluss[front*2] = pluss[front];
            multi[front*2] = multi[front] + 1;
        }
        if (!visited[front + 1] && front + 1 < 1001)
        {
            q.push(front + 1);
            visited[front + 1] = true;
            pluss[front+1] = pluss[front] + 1;
            multi[front+1] = multi[front];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    bfs();

    int cnt = 0;
    int max_multi = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        max_multi = max(max_multi, multi[num]);
        cnt += pluss[num];
    }
    cnt += max_multi;
    cout << cnt;
    return 0;
}