#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long even_sum = 0, odd_sum = 0;
    long long even_cnt = 0, odd_cnt = 0;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i]%2){
            odd_sum += (i - odd_cnt++);
        }
        else{
            even_sum += (i - even_cnt++);
        }
    }
    cout << min(odd_sum, even_sum);

    return 0;
}