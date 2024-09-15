#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> um;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;

    long long n;
    cin >> n;
    vector<long long> sumn(n + 1);
    sumn[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> sumn[i];
        sumn[i] += sumn[i - 1];
    }

    long long m;
    cin >> m;
    vector<long long> summ(m + 1);
    summ[0] = 0;
    for (long long i = 1; i <= m; i++)
    {
        cin >> summ[i];
        summ[i] += summ[i - 1];
    }

    for(long long i=1;i<=n;i++){
        for(long long j=0;j<i;j++){
            long long num = sumn[i] - sumn[j];
            um[num]++;
        }
    }

    long long ans = 0;
    for(long long i=1;i<=m;i++){
        for(long long j=0;j<i;j++){
            long long num = summ[i] - summ[j];
            ans += um[t-num];
        }
    }
    cout << ans;
    
    


    return 0;
}