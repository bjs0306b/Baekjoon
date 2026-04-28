#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i=0;i<n;i++){long long num; cin >> num; pq.push(num);}

    while(m--){
        long long temp1 = pq.top(); pq.pop();
        long long temp2 = pq.top(); pq.pop();
        pq.push(temp1+temp2); pq.push(temp1+temp2);
    }

    long long ans = 0;
    while(!pq.empty()){
        ans += pq.top(); pq.pop();
    }
    cout << ans;

    return 0;
}