#include <bits/stdc++.h>
using namespace std;

long long n;
void input()
{
    cin >> n;
}

long long solve()
{
    if (n == 1)
        return 1;

    set<long long> s;
    for (long long i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            s.insert(i);
            s.insert(n / i);
        }
    }

    long long ans = n;

    vector<long long> sosu;

    for (auto k : s)
    {
        if(k == 1) continue;
        long long cnt = 0;
        for (long long i = 1; i <= sqrt(k); i++)
        {
            if (k % i == 0)
            {
                cnt++;
                if (cnt > 1)
                    break;
            }
        }
        if (cnt == 1)
            sosu.push_back(k);
    }
    for(auto k : sosu){
        ans = ans / k * (k-1);
    }

    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}