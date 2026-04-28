#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans = INT32_MAX, A[8][8], visited[8][8];
vector<pair<int, int>> pos;
vector<vector<int>> cctv[5];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
            if (A[i][j] > 0 && A[i][j] < 6)
            {
                pos.push_back({i, j});
                k++;
            }
        }

    // 방향 저장.

    // 1번 CCTV
    for (int i = 0; i < 4; i++)
    {
        vector<int> temp1;
        temp1.push_back(i);
        cctv[0].push_back(temp1);
    }

    // 2
    for (int i = 0; i < 2; i++)
    {
        vector<int> temp2;
        for (int j = 0; j < 2; j++)
            temp2.push_back(i * 2 + j);
        cctv[1].push_back(temp2);
    }

    // 3
    vector<int> temp3 = {0, 2};
    cctv[2].push_back(temp3);
    temp3 = {0, 3};
    cctv[2].push_back(temp3);
    temp3 = {1, 2};
    cctv[2].push_back(temp3);
    temp3 = {1, 3};
    cctv[2].push_back(temp3);

    // 4
    for (int i = 0; i < 4; i++)
    {
        vector<int> temp4;
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
                temp4.push_back(j);
        }
        cctv[3].push_back(temp4);
    }

    // 5
    vector<int> temp5 = {0, 1, 2, 3};
    cctv[4].push_back(temp5);

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "\n" << i << "\n";
    //     for (auto k : cctv[i])
    //     {
    //         for (auto kk : k)
    //         {
    //             cout << kk << " ";
    //         }
    //         cout << '\n';
    //     }
    // }
}

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
void erase(int x, int y, int dir)
{

    while (1)
    {
        x += dx[dir], y += dy[dir];
        if (!(x >= 0 && x < n && y >= 0 && y < m) || A[x][y] == 6)
            break;
        visited[x][y]++;
    }
}
void recover(int x, int y, int dir)
{

    while (1)
    {
        x += dx[dir], y += dy[dir];
        if (!(x >= 0 && x < n && y >= 0 && y < m) || A[x][y] == 6)
            break;
        visited[x][y]--;
    }
}

void dfs(int dep)
{
    if (dep == k)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (visited[i][j] == 0 && A[i][j] == 0)
                    cnt++;
        ans = min(ans, cnt);
        return;
    }

    int x = pos[dep].first, y = pos[dep].second;
    vector<vector<int>> temp = cctv[A[x][y] - 1];
    for (int j = 0; j < temp.size(); j++)
    {
        for (auto k : temp[j])
        {
            erase(x, y, k);
        }

        dfs(dep + 1);

        for (auto k : temp[j])
        {
            recover(x, y, k);
        }
    }
}

int solve()
{
    dfs(0);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();

    return 0;
}