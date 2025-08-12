#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans;
bool A[50][50];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'L')
                A[i][j] = true;
            else
                A[i][j] = false;
        }
    }
}

pair<int, int> find_far_edge(int x, int y)
{
    pair<int, int> ret;
    bool visited[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        auto f = q.front();
        ret = f;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = f.first + dx[i], ny = f.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                
            }
        }
    }
    return ret;
}

int find_longest_dis(int x, int y)
{
    int ret = -1;
    bool visited[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            auto f = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = f.first + dx[i], ny = f.second + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        ret++;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j])
            {   
                //cout <<  i << " " << j << "\n\n";
                auto edge = find_far_edge(i, j);
                //cout << "find_far_edge:"  << edge.first << " " << edge.second << "\n\n";
                int dis = find_longest_dis(edge.first, edge.second);
                //cout << "dis:" << dis << "\n";
                ans = max(dis, ans);
            }
        }
    }
    cout << ans;

    return 0;
}