#include <bits/stdc++.h>
using namespace std;

long long fac[20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fac[1] = 1;
    for (int i = 2; i < 20; i++)
        fac[i] = fac[i - 1] * i;
    int n;
    cin >> n;
    int m;
    cin >> m;

    if (m == 1)
    {
        vector<int> v(n);
        for (int i = 1; i <= n; i++)
            v[i - 1] = i;
        vector<bool> visited(n + 1, false);
        long long a;
        cin >> a;
        a--;
        int temp = n - 1;

        while (a)
        {
            int cnt = 0;
            while (a >= fac[temp])
            {
                a -= fac[temp];
                cnt++;
            }

            for (int i = 1; i <= n; i++)
            {
                if (!visited[i])
                {
                    if (cnt == 0)
                    {
                        cout << i << " ";
                        visited[i] = true;
                        break;
                    }
                    cnt--;
                }
            }
            temp--;
        }
        for(int i=1;i<=n;i++) if(!visited[i]) cout << i << " ";
    }
    else
    {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<bool> visited(n + 1, false);
        long long ans = 1;
        for (int i = 0; i < n - 1; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (j == v[i])
                {
                    ans += (cnt * fac[n - i - 1]);
                    visited[v[i]] = true;
                    break;
                }
                if (!visited[j])
                    cnt++;
            }
        }
        cout << ans;
    }
    return 0;
}