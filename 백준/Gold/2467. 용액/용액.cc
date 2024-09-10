#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    pair<long long, long long> ans;
    long long mn = INT64_MAX;
    vector<long long> vec(n);
    for (long long i = 0; i < n; i++)
        cin >> vec[i];

    if (vec[0] >= 0)
    {
        cout << vec[0] << " " << vec[1];
    }
    else if (vec[n - 1] <= 0)
    {
        cout << vec[n - 2] << " " << vec[n - 1];
    }
    else
    {
        for (long long i = 0; i < n - 1; i++)
        {
            auto iter = lower_bound(vec.begin() + i + 1, vec.end(), -vec[i]);
            long long n1 = *iter, n2 = *(--iter);

            if (vec[i] == n2)
            {
                if (mn > abs(vec[i] + n1))
                {
                    mn = abs(vec[i] + n1);
                    ans = {vec[i], n1};
                }
            }
            else
            {
                long long temp;

                long long wait;
                if (abs(n1 + vec[i]) < abs(n2 + vec[i]))
                {
                    temp = abs(n1 + vec[i]);
                    wait = n1;
                }
                else
                {
                    temp = abs(n2 + vec[i]);
                    wait = n2;
                }
                if (temp < mn)
                {
                    mn = temp;
                    ans = {vec[i], wait};
                }
            }
        }
        cout << ans.first << " " << ans.second;
    }
    return 0;
}