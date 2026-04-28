#include <bits/stdc++.h>
using namespace std;

int a, b;
bool key[26];
int ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    while (n--)
    {
        cin >> a >> b;

        ans = 0;
        memset(key, 0, sizeof(key));
        char arr[a][b];
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cin >> arr[i][j];
            }
        }

        string keys;
        cin >> keys;

        if (keys != "0")
        {
            for (auto k : keys)
            {
                int num = k - 'a';
                key[num] = true;
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        bool visited[a][b];

        for (;;)
        {
            bool flag = true;
            memset(visited, 0, sizeof(visited));
            queue<pair<int, int>> q;
            for (int i = 0; i < a; i++)
            {
                for (int j = 0; j < b; j++)
                {
                    if (i == 0 || i == a - 1 || j == 0 || j == b - 1)
                    {
                        if (arr[i][j] == '.')
                        {
                            q.push({i, j});
                            visited[i][j] = true;
                        }
                        else if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
                        {
                            q.push({i, j});
                            int num = arr[i][j] - 'a';
                            key[num] = true;
                            arr[i][j] = '.';
                            flag = false;
                            visited[i][j] = true;
                        }
                        else if (arr[i][j] >= 'A' && arr[i][j] <= 'Z')
                        {
                            int num = arr[i][j] - 'A';
                            if (key[num])
                            {
                                q.push({i, j});
                                arr[i][j] = '.';
                                flag = false;
                                visited[i][j] = true;
                            }
                        }
                        else if (arr[i][j] == '$')
                        {
                            ans++;
                            arr[i][j] = '.';
                            q.push({i, j});
                            flag = false;
                            visited[i][j] = true;
                        }
                    }
                }
            }

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    if (!visited[x + dx[i]][y + dy[i]] && x + dx[i] >= 0 && x + dx[i] < a && y + dy[i] >= 0 && y + dy[i] < b)
                    {
                        visited[x + dx[i]][y + dy[i]] = true;

                        if (arr[x + dx[i]][y + dy[i]] == '.')
                        {
                            q.push({x + dx[i], y + dy[i]});
                        }
                        else if (arr[x + dx[i]][y + dy[i]] >= 'a' && arr[x + dx[i]][y + dy[i]] <= 'z')
                        {
                            int num = arr[x + dx[i]][y + dy[i]] - 'a';
                            key[num] = true;
                            q.push({x + dx[i], y + dy[i]});
                            arr[x + dx[i]][y + dy[i]] = '.';
                            flag = false;
                        }
                        else if (arr[x + dx[i]][y + dy[i]] >= 'A' && arr[x + dx[i]][y + dy[i]] <= 'Z')
                        {
                            int num = arr[x + dx[i]][y + dy[i]] - 'A';
                            if (key[num])
                            {
                                arr[x + dx[i]][y + dy[i]] = '.';
                                q.push({x + dx[i], y + dy[i]});
                                flag = false;
                            }
                        }
                        else if (arr[x + dx[i]][y + dy[i]] == '$')
                        {
                            arr[x + dx[i]][y + dy[i]] = '.';
                            ans++;
                            flag = false;
                        }
                    }
                }
            }
            if (flag)
                break;
        }
        // for (int i = 0; i < a; i++)
        // {
        //     for (int j = 0; j < b; j++)
        //         cout << arr[i][j];
        //     cout << '\n';
        // }
        cout << ans << "\n";
    }

    return 0;
}