#include <bits/stdc++.h>
using namespace std;

bool arr[1000][1000];
bool visited[1000][1000][2];

struct node
{
    int x, y; // 좌표
    bool b;   // 벽을 깼는가.
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            char c;
            cin >> c;
            if (c == '0')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }
    queue<node> q;
    visited[0][0][0] = true;
    q.push({0, 0, false});
    int ans = 0;
    while (!q.empty())
    {
        ans++;

        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            auto cur = q.front();
            q.pop();

            if (cur.x == a - 1 && cur.y == b - 1)
            {
                cout << ans;
                return 0;
            }

            if (cur.x + 1 < a && !visited[cur.x + 1][cur.y][cur.b])
            {
                if (arr[cur.x + 1][cur.y] == 1 && !cur.b)
                {
                    q.push({cur.x + 1, cur.y, true});
                    visited[cur.x + 1][cur.y][1] = true;
                }
                else if (arr[cur.x + 1][cur.y] == 0)
                {
                    q.push({cur.x + 1, cur.y, cur.b});
                    visited[cur.x + 1][cur.y][cur.b] = true;
                }
            }

            // 위로 이동
            if (cur.x - 1 >= 0 && !visited[cur.x - 1][cur.y][cur.b])
            {
                if (arr[cur.x - 1][cur.y] == 1 && !cur.b)
                {
                    q.push({cur.x - 1, cur.y, true});
                    visited[cur.x - 1][cur.y][1] = true;
                }
                else if (arr[cur.x - 1][cur.y] == 0)
                {
                    q.push({cur.x - 1, cur.y, cur.b});
                    visited[cur.x - 1][cur.y][cur.b] = true;
                }
            }

            // 오른쪽으로 이동
            if (cur.y + 1 < b && !visited[cur.x][cur.y + 1][cur.b])
            {
                if (arr[cur.x][cur.y + 1] == 1 && !cur.b)
                {
                    q.push({cur.x, cur.y + 1, true});
                    visited[cur.x][cur.y + 1][1] = true;
                }
                else if (arr[cur.x][cur.y + 1] == 0)
                {
                    q.push({cur.x, cur.y + 1, cur.b});
                    visited[cur.x][cur.y + 1][cur.b] = true;
                }
            }

            // 왼쪽으로 이동
            if (cur.y - 1 >= 0 && !visited[cur.x][cur.y - 1][cur.b])
            {
                if (arr[cur.x][cur.y - 1] == 1 && !cur.b)
                {
                    q.push({cur.x, cur.y - 1, true});
                    visited[cur.x][cur.y - 1][1] = true;
                }
                else if (arr[cur.x][cur.y - 1] == 0)
                {
                    q.push({cur.x, cur.y - 1, cur.b});
                    visited[cur.x][cur.y - 1][cur.b] = true;
                }
            }
        }
    }
    cout << -1;

    return 0;
}