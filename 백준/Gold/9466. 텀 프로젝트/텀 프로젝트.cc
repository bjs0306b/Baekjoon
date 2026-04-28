#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;

        int cnt[m + 1];
        int arr[m + 1];
        fill(cnt + 1, cnt + m + 1, 0);

        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int num;
            cin >> num;
            cnt[num]++;
            arr[i] = num;
        }
        queue<int> q;
        for (int i = 1; i <= m; i++)
        {
            if (cnt[i] == 0)
            {
                q.push(i);
                ans++;
            }
        }

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            if (--cnt[arr[f]] == 0)
            {
                {
                    q.push(arr[f]);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}