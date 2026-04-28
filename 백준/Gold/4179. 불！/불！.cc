#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> fires, cur_pos;
    char A[n][m];
    bool visited[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            cin >> A[i][j];
            if (A[i][j] == 'F')
            {
                fires.push({i, j});
                A[i][j] = '#';
            }
            if (A[i][j] == 'J')
            {
                visited[i][j] = true;
                cur_pos.push({i, j});
                A[i][j] = '.';
            }
        }
    }

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int cnt = 0;
    while (!cur_pos.empty())
    {
        // 불 이동
        int size = fires.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int nx = fires.front().first + dx[j], ny = fires.front().second + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == '.')
                {
                    A[nx][ny] = '#';
                    fires.push({nx, ny});
                }
            }
            fires.pop();
        }

        // 사람 이동
        size = cur_pos.size();
        cnt++;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int nx = cur_pos.front().first + dx[j], ny = cur_pos.front().second + dy[j];
                if (nx == -1 || nx == n || ny == -1 || ny == m) // 가장자리 -> 탈출
                { 
                    cout << cnt;
                    return 0;
                }
                if (A[nx][ny] == '#' || visited[nx][ny]) continue; // 벽
                
                visited[nx][ny] = true;
                cur_pos.push({nx, ny});
            }
            cur_pos.pop();
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}