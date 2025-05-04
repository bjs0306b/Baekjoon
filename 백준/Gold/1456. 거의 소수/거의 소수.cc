#include <bits/stdc++.h>
using namespace std;

bool is_not_prime[10000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> prime;
    is_not_prime[0] = true, is_not_prime[1] = true;
    for (long long i = 2; i < 10000001; i++)
    {
        if (!is_not_prime[i])
        {
            prime.push_back(i);
            for (long long j = i * 2; j < 10000001; j += i)
            {
                is_not_prime[j] = true;
            }
        }
    }

    vector<long long> almost_prime;
    for (long long i = 0; i < 155611; i++)
    {
        for (long long j = prime[i] * prime[i]; j < 100000000000001; j *= prime[i])
        {   
            almost_prime.push_back(j);
        }
    }
    for(int i=155611;i<prime.size();i++){
        almost_prime.push_back(prime[i] * prime[i]);
    }

    sort(almost_prime.begin(), almost_prime.end());

    long long n, m;
    cin >> n >> m;

    cout << upper_bound(almost_prime.begin(), almost_prime.end(), m) - lower_bound(almost_prime.begin(), almost_prime.end(), n);

    return 0;
}