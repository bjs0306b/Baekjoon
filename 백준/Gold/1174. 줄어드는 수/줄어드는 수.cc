#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<long long> q; for(long long i=0;i<10;i++) q.push(i);
    vector<long long> vec;

    while(!q.empty()){
        long long front = q.front(); q.pop();
        vec.push_back(front);

        long long one = front % 10;
        for(long long i = one-1;i>=0;i--){
            q.push(front*10+i);
        }
    }

    sort(vec.begin(), vec.end());

    long long n; cin >> n;

    if(n > vec.size()) cout << -1;
    else cout << vec[n-1];
    
    return 0;
}