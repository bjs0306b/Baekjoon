#include <bits/stdc++.h>
using namespace std;

int arr[50][50];
bool visited[50][50];
int n, l, r;
int ans = 0;
bool flag;

vector<pair<int, int>> v;

void dfs(int x, int y)
{
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < n && y + dy[i] >= 0 && !visited[x + dx[i]][y + dy[i]])
        { // 벽에 부딪히지 않고 방문하지 않았을 때
            if (abs(arr[x + dx[i]][y + dy[i]] - arr[x][y]) >= l && abs(arr[x + dx[i]][y + dy[i]] - arr[x][y]) <= r)
            { // 수의 차이가 l ~ r 일 때
                flag = true;
                visited[x + dx[i]][y + dy[i]] = true;
                v.push_back({x + dx[i], y + dy[i]});
                dfs(x + dx[i], y + dy[i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    flag = true; // 반복문을 위한 true

    while (flag)
    {
        flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    v.push_back({i, j});
                    visited[i][j] = true;
                    dfs(i, j);

                    int sum = 0;
                    for (auto k : v)
                    {
                        sum += arr[k.first][k.second];
                    }
                    int aver = sum / v.size();

                    for (auto k : v)
                    {
                        arr[k.first][k.second] = aver;
                    }

                    v.clear();
                }
            }
        }
        if(flag) ans++;

        for(int i=0;i<n;i++) for(int j=0;j<n;j++) visited[i][j] = false;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans;

    return 0;
}