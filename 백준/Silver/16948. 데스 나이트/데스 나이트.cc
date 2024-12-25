#include <bits/stdc++.h>
using namespace std;

bool visited[200][200];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;

    int dx[6] = {-2, -2, 0, 0, 2, 2}, dy[6] = {-1,1,-2,2,-1,1};

    int cnt = 0;
    while(!q.empty())
    {
        cnt++;
        int size = q.size();
        // cout << cnt << "\n\n";
        for (int i = 0; i < size; i++)
        {
            auto temp = q.front();
            // cout << temp.first  <<  ' ' << temp.second << "\n";
            q.pop();
            if (temp.first == x2 && temp.second == y2)
            {
                cout << cnt - 1;
                return 0;
            }
            for (int j = 0; j < 6; j++)
            {
                if (!visited[dx[j] + temp.first][dy[j] + temp.second] && dx[j] + temp.first >= 0 && dx[j] + temp.first < n && dy[j] + temp.second >= 0 && dy[j] + temp.second < n)
                {
                    q.push({dx[j] + temp.first, dy[j] + temp.second});
                    visited[dx[j] + temp.first][dy[j] + temp.second] = true;
                }
            }
        }
    }
    cout << -1;

    return 0;
}