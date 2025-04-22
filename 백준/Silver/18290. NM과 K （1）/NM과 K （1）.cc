#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int A[100];
vector<int> v;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int func()
{
    bool visited[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            int r = i / m, c = i % m;
            for (int j = 0; j < 4; j++)
            {
                int nr = r + dx[j], nc = c + dy[j];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc])
                    return INT32_MIN;
            }
            sum += A[i];
            visited[r][c] = true;
        }
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i * m + j];
        }
    }

    for (int i = 0; i < n * m - k; i++)
        v.push_back(0);
    for (int i = 0; i < k; i++)
        v.push_back(1);

    int ans = INT32_MIN;
    do
    {
        ans = max(ans, func());
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;

    return 0;
}