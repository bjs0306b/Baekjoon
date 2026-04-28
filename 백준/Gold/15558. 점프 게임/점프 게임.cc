#include <bits/stdc++.h>
using namespace std;

int ans()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    bool A[2][n], visited[2][n];
    for (int i = 0; i < 2; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '1')
                A[i][j] = true;
            else
                A[i][j] = false;
            visited[i][j] = false;
        }
    }

    queue<pair<bool, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int current_time = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto temp = q.front();
            q.pop();

            if(temp.second + k >= n) return 1;
            if (current_time < temp.second - 1 && A[temp.first][temp.second - 1] && !visited[temp.first][temp.second - 1])
            {
                q.push({temp.first, temp.second - 1});
                visited[temp.first][temp.second - 1] = true;
            }
            if (A[temp.first][temp.second + 1] && !visited[temp.first][temp.second + 1])
            {
                
                q.push({temp.first, temp.second + 1});
                visited[temp.first][temp.second + 1] = true;
            }
            if (A[!temp.first][temp.second + k] && !visited[!temp.first][temp.second + k])
            {
                q.push({!temp.first, temp.second + k});
                visited[!temp.first][temp.second + k] = true;
            }
        }
        current_time++;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << ans();

    return 0;
}