#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y, h;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n, m;
    cin >> k >> m >> n;
    int A[n][m];
    bool visited[n][m][k+1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            for(int h=0;h<=k;h++) visited[i][j][h] = false;
        }
    queue<node> q;
    visited[0][0][k] = true;
    q.push({0, 0, k});
    int cnt = 0;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, hdx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, hdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node f = q.front();
            q.pop();
            if(f.x == n-1 && f.y == m-1){cout << cnt; return 0;}

            if (f.h) // 말 이동
            {
                for (int j = 0; j < 8; j++)
                {
                    int nx = f.x + hdx[j], ny = f.y + hdy[j];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == 0 && !visited[nx][ny][f.h-1])
                    {
                        visited[nx][ny][f.h-1] = true;
                        q.push({nx, ny, f.h - 1});
                    }
                }
            }
            for (int j = 0; j < 4; j++) // 그냥 이동
            {
                int nx = f.x + dx[j], ny = f.y + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == 0 && !visited[nx][ny][f.h])
                {
                    visited[nx][ny][f.h] = true;
                    q.push({nx, ny, f.h});
                }
            }
        }
        cnt++;
    }
    cout << -1; // 이동 불가
    return 0;
}