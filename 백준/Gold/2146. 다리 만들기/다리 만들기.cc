#include <bits/stdc++.h>
using namespace std;

int n, A[100][100];
bool visited[100][100];
set<pair<int, int>> coast; // 해안가

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
    bool is_coast = false; // 해안가 체크, 주변에 하나라도 0이면 해안가

    A[x][y] = num;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (A[nx][ny] && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                assign(nx, ny, num);
            }
            if (A[nx][ny] == 0)
                is_coast = true;
        }
    }
    if (is_coast)
        coast.insert({x, y});
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

int check_distance(int x, int y, int island_num)
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

    int cnt = 0;
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
                    visited[nx][ny] = true;
                    if(!A[nx][ny]){
                        q.push({nx,ny});
                    }
                    if (A[nx][ny] && A[nx][ny] != island_num) // 다른 섬 도착
                    {
                        return cnt;
                    }
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
    for (auto k : coast)
    {
        int x = k.first, y = k.second;
        int island_num = A[x][y];
        ans = min(ans, check_distance(x, y, island_num));
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    assign_island_num(); // 각 섬에 번호 할당
    shortest_bridge();   // 해안가와 가장 가까운 다른 섬 거리 구하기

    return 0;
}