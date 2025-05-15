#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    queue<int> q; for(int i=0;i<n;i++) q.push(i+1);
    for(long long i=1;i<n;i++){
        long long move_cnt = (i*i*i - 1) % (n -i + 1);
        while(move_cnt--){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    cout << q.front();
    
    return 0;
}