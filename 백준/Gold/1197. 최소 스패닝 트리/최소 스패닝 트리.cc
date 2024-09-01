#include<bits/stdc++.h>
using namespace std;

int check[10001];

struct node{
    int from, to, cost;

    bool operator<(const node other)const {
        return cost > other.cost;
    }
};

int parent(int n){
    if(check[n] == n) return n;
    else return parent(check[n]);
}

bool cycle(int a, int b){
    if(parent(a) == parent(b)) return true;
    else return false;
}

void union_parent(int a, int b){
    int p1 = parent(a);
    int p2 = parent(b);
    if(p1 < p2) check[p1] = p2;
    else check[p2] = p1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) check[i] = i;

    priority_queue<node> pq;
    while(m--){
        int s,e,c; cin >> s >> e >> c;
        pq.push({s,e,c});
    }
    int ans = 0;
    int cnt = n-1;
    while(cnt){
        int f = pq.top().from;
        int t = pq.top().to;
        int c = pq.top().cost;
        pq.pop();

        if(!cycle(t,f)){
            cnt--;
            ans += c;
            union_parent(t,f);
        }
    }
    cout << ans;

    
    
    return 0;
}