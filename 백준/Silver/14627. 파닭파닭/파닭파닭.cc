#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long S, C;
    cin >> S >> C;
    long long sum = 0;
    vector<long long> v(S);
    for (long long i = 0; i < S; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    long long s = 1, e = *max_element(v.begin(), v.end());

    while (s <= e)
    {
        long long m = (s + e) / 2;

        long long cnt = 0;
        for (auto k : v)
            cnt += (k / m);    
        
        if (C > cnt) e = m - 1;
        else s = m + 1;
        
    }

    cout << sum - C * e;

    return 0;
}