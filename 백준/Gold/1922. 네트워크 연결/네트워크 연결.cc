#include <bits/stdc++.h>
using namespace std;

int parent[1001];

struct node{
    int a,b,c;

    bool operator<(const node& other) const{
        return c > other.c;
    }
};

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

bool is_cycle(int a, int b){
    if(find(a) == find(b)) return true;

    parent[find(a)] = find(b);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) parent[i] = i;

    int m; cin >> m;
    priority_queue<node> pq;
    while(m--){
        int a,b,c; cin >> a >> b >> c; pq.push({a,b,c});
    }

    int ans = 0;
    int cnt = n-1;
    while(cnt){
        int aa = pq.top().a, bb = pq.top().b, cc = pq.top().c; pq.pop();
        if(!is_cycle(aa,bb)){
            ans += cc;
            cnt--;
        }
    }
    cout << ans;

    return 0;
}