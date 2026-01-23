#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007L;
int n;
priority_queue<long long> pq;
void input()
{
    cin >> n;
    pq = priority_queue<long long>();
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        pq.push(-num);
    }
}

long long solve()
{
    long long ret = 1;

    while (pq.size() > 1)
    {
        long long a = -pq.top();
        pq.pop();
        long long b = -pq.top();
        pq.pop();

        unsigned __int128 ab = (unsigned __int128)a * b;

        ret = (ret * (long long)(ab % mod)) % mod;
        pq.push(-(long long)ab);
    }

    return ret % mod;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        input();
        cout << solve() << "\n";
    }
    return 0;
}