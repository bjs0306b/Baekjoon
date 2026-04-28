#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y;

    bool operator<(const node other) const{
        return (x+y) / (y+1) < (other.x + other.y) / (other.y + 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,l;
    cin >> n >> m >> l;
    if(n == 0){
        cout << (l+m) / (m+1);
        return 0;
    }
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    priority_queue<node> pq;
    pq.push({v[0], 0}); pq.push({l - v[n-1], 0});
    for(int i=0;i<n-1;i++){
        pq.push({v[i+1] - v[i], 0});
    }

    for(int i=0;i<m;i++){
        auto t = pq.top(); pq.pop();
        pq.push({t.x, t.y+1});
    }

    cout << (pq.top().x + pq.top().y) / (pq.top().y+1);

    return 0;
}