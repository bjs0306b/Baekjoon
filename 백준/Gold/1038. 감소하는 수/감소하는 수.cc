#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    queue<long long> q; for(int i=1;i<10;i++) q.push(i);
    vector<long long> ans_v; ans_v.push_back(0);

    while(!q.empty()){
        long long f = q.front(); q.pop();
        ans_v.push_back(f);
        for(int i=0;i<f%10;i++){
            q.push(f*10 + i);
        }
    }
    if(n >= ans_v.size()) cout << -1;
    else  cout << ans_v[n];

    
    return 0;
}