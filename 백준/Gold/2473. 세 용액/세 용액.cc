#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    if (v[0] >= 0)
    {
        cout << v[0] << " " << v[1] << " " << v[2];
    }
    else if (v[n - 1] < 0)
    {
        cout << v[n - 3] << " " << v[n - 2] << " " << v[n - 1];
    }
    else
    {
        long long mn = INT64_MAX;
        long long ans[3];
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int temp = v[i] + v[j];
                auto iter = lower_bound(v.begin() + j + 1, v.end(), -temp);
                if (iter == v.end())
                {
                    iter--;
                    if (mn > abs(temp + *iter))
                    {
                        mn = abs(temp + *iter);
                        ans[0] = v[i], ans[1] = v[j], ans[2] = *iter;
                    }
                }
                else if(*(iter - 1) == v[j]){
                    if (mn > abs(temp + *iter))
                    {
                        mn = abs(temp + *iter);
                        ans[0] = v[i], ans[1] = v[j], ans[2] = *iter;
                    }
                }
                else
                {
                    long long t1 = *(iter - 1), t2 = *iter;

                    if (abs(t1 + temp) > abs(t2 + temp))
                    {
                        if (mn > abs(t2 + temp))
                        {
                            mn = abs(t2 + temp);
                            ans[0] = v[i], ans[1] = v[j], ans[2] = t2;
                        }
                    }
                    else
                    {
                        if (mn > abs(t1 + temp))
                        {
                            mn = abs(t1 + temp);
                            ans[0] = v[i], ans[1] = v[j], ans[2] = t1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++)
            cout << ans[i] << " ";
    }

    return 0;
}