#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int A[300][300];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void input()
{
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
}

bool is_in(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void rotate()
{
    int x = 0, y = 0;
    bool visited[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
    int cnt = n * m;
    for (;;)
    {
        int d = 0;
        int nx, ny;
        vector<pair<int, int>> v;
        for (;;)
        {
            v.push_back({x, y});
            // cout << "x :" << x << ", y :" << y << "\n";
            if (--cnt == 0)
            {
                vector<int> temp;
                for (int i = 0; i < v.size(); i++)
                {
                    int num = (i - r % v.size() + v.size()) % v.size();
                    temp.push_back(A[v[num].first][v[num].second]);
                }

                for (int i = 0; i < v.size(); i++)
                {
                    A[v[i].first][v[i].second] = temp[i];
                }
                return;
            }

            visited[x][y] = true;

            nx = x + dx[d], ny = y + dy[d];
            if (!is_in(nx, ny) || visited[nx][ny])
            { // 배열을 벗어나거나 이미 방문했으면 방향 바꿔
                d++;
            }
            if (d == 4)
                break;
            nx = x + dx[d], ny = y + dy[d];

            x = nx, y = ny;
        }

        vector<int> temp;
        for (int i = 0; i < v.size(); i++)
        {
            int num = (i - r % v.size() + v.size()) % v.size();
            temp.push_back(A[v[num].first][v[num].second]);
        }

        for (int i = 0; i < v.size(); i++)
        {
            A[v[i].first][v[i].second] = temp[i];
        }

        x++;
    }
}

void solve()
{
    rotate();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}