#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,h,t;
    cin >> n >> h >> t;

    priority_queue<int> pq; for(int i=0;i<n;i++){int num; cin >> num; pq.push(num);}
    if(h > pq.top()) {cout << "YES\n0"; return 0;}

    for(int i=0;i<t;i++){
        int tp = pq.top(); pq.pop();
        if(tp == 1){
            cout << "NO\n1";
            return 0;
        }
        tp/=2;
        pq.push(tp);

        if(pq.top() < h){cout << "YES\n" << i+1; return 0;}
    }
    cout << "NO\n" << pq.top();
    return 0;
}