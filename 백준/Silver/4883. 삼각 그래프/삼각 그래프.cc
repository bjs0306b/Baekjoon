#include <bits/stdc++.h>
using namespace std;

long long n, A[100001][3], mn[100001][3];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int t = 1;; t++)
    {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> A[i][j];
                mn[i][j] = INT64_MAX;
            }
        }

        mn[0][1] = A[0][1], mn[0][2] = A[0][1]+A[0][2];

        for (int i = 1; i < n; i++)
        {
            mn[i][0] = min(mn[i - 1][0], mn[i - 1][1]) + A[i][0];
            mn[i][1] = min(min(mn[i - 1][0], mn[i - 1][1]), min(mn[i][0], mn[i - 1][2])) + A[i][1];
            mn[i][2] = min(mn[i][1], min(mn[i - 1][1], mn[i - 1][2])) + A[i][2];
        }

        cout << t << ". " << mn[n - 1][1] << "\n";
    }
}