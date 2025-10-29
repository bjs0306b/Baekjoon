#include <bits/stdc++.h>
using namespace std;

int n, m, h;
bool A[31][10], flag = false;

void input()
{
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        A[a][b] = true;
    }
}

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        int cur = i;
        for (int j = 1; j <= h; j++)
        {
            bool f1 = false, f2 = false;
            if (cur < n && A[j][cur])
                f1 = true;
            if (cur > 1 && A[j][cur - 1])
                f2 = true;
            if (f1)
                cur++;
            if (f2)
                cur--;
        }
        if (i != cur)
            return false;
    }
    return true;
}

void dfs(int dep, int m, int x)
{
    if (flag)
        return;
    if (dep == m)
    {   
        if (check())
            flag = true;
    }
    else
    {
        for (int i = x; i <= h; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!A[i][j])
                {
                    if (A[i][j - 1] || A[i][j + 1]) // 양옆에 있을 때
                        continue;

                    A[i][j] = true;
                    dfs(dep + 1, m, i);
                    A[i][j] = false;
                }
            }
        }
    }
}

int solve()
{
    for(int i=0;i<4;i++){
        dfs(0, i, 1);
        if(flag) return i;
    }
    if (flag) return 1;
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << solve();
    return 0;
}