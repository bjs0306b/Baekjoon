#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
vector<pair<int, int>> v;

bool possible(int x, int y, int k)
{

    for (int i = 0; i < 9; i++)
    {
        if (arr[x][i] == k)
            return false;
        
    }

    
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][y] == k)
            return false;
    }

    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[x / 3 * 3 + i][y / 3 * 3 + j] == k)
                return false;
        }
    }

    return true;
}

void dfs(int n)
{
    if (n == v.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    else
    {
        int x = v[n].first, y = v[n].second;
        // cout << x << " " << y << "\n";
        for (int i = 1; i < 10; i++)
        {
            if (possible(x, y, i))
            {
                arr[x][y] = i;
                dfs(n + 1);
                arr[x][y] = 0;
            }
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
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                v.push_back({i, j});
        }
    }
    // for(auto k : v) cout << k.first << " " << k.second << "\n";

    dfs(0);

    return 0;
}