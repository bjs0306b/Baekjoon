#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
vector<pair<int, int>> v;
int cnt = 0;

void dfs(int c)
{
    if (c == cnt)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }

    int x = v[c].first, y = v[c].second;

    bool b[10];
    for (int i = 0; i < 10; i++)
        b[i] = true;

    for (int i = 0; i < 9; i++)
        if (b[arr[i][y]])
            b[arr[i][y]] = false;
    for (int i = 0; i < 9; i++)
        if (b[arr[x][i]])
            b[arr[x][i]] = false;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (b[arr[x / 3 * 3 + i][y / 3 * 3 + j]])
                b[arr[x / 3 * 3 + i][y / 3 * 3 + j]] = false;

    for (int i = 1; i <= 9; i++)
    {
        if (b[i])
        {
            arr[x][y] = i;
            dfs(c + 1);
            arr[x][y] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            if (c == '0')
            {
                v.push_back({i, j});
                cnt++;
            }
        }
    }
    dfs(0);

    return 0;
}