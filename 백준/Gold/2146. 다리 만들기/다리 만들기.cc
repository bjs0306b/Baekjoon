#include <bits/stdc++.h>
using namespace std;

int n, A[100][100];
bool visited[100][100];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
}

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
void assign(int x, int y, int num)
{
    A[x][y] = num;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            assign(nx, ny, num);
        }
    }
}

void assign_island_num()
{
    int cnt = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && A[i][j])
            {
                visited[i][j] = true;
                assign(i, j, cnt);
                cnt++;
            }
        }
    }
}

int check_distance(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    visited[x][y] = true;

    int first_island_distance = 0, first_island_num = 0;
    int cnt = 1;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto front = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int nx = front.first + dx[j], ny = front.second + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
                {
                    if (A[nx][ny]) // 섬 도착.
                    {
                        if (first_island_distance) // 이미 다른 섬 찾음
                        {
                            if (first_island_num != A[nx][ny])
                                return first_island_distance + cnt - 1;
                        }
                        else
                        {
                            first_island_distance = cnt;
                            first_island_num = A[nx][ny];
                        }
                    }
                    else // 바다
                    {
                        q.push({nx, ny});
                    }
                    visited[nx][ny] = true;
                }
            }
        }
        cnt++;
    }
    return INT32_MAX;
}

void shortest_bridge()
{
    int ans = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!A[i][j])
            {
                ans = min(ans, check_distance(i, j));
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    assign_island_num(); // 각 섬에 번호 할당
    shortest_bridge(); // 모든 바다에 대해 가장 가까운 섬 2개에 대해 거리 측정하고 더하기

    return 0;
}