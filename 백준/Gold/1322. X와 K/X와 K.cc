#include <bits/stdc++.h>
using namespace std;


long long power(long long a,long long b){
    long long ret = 1;
    for(int i=0;i<b;i++) ret *= a;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    long long n, k;
    cin >> n >> k;
    long long temp = 1;

    vector<int> v;
    while (n)
    {
        if (n % 2)
            v.push_back(0);
        else
        {
            if ((temp & k) == temp)
                v.push_back(1);
            else
                v.push_back(0);
            temp = temp << 1;
        }
        n/=2;
    }

    while (temp <= k)
    {
        if ((temp & k) == temp)
            v.push_back(1);
        else
            v.push_back(0);
        temp = temp << 1;
    }
    

    long long ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        ans += v[i] * power(2, i);
    }

    cout << ans;

    return 0;
}