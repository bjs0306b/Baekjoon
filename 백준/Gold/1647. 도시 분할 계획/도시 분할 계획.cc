#include<bits/stdc++.h>
using namespace std;

struct node{
    int s,e,c;

    bool operator < (const node other)const{
        return c > other.c;
    }
};

int parent[100001];


int find_parent(int a){
    if(parent[a] == a) return a;
    else return find_parent(parent[a]);
}
void union_parent(int a, int b){
    int t1 = find_parent(a), t2 = find_parent(b);
    if(t1 < t2) parent[t1] = t2;
    else parent[t2] = t1;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,e; cin >> n >> e;
    for(int i=1;i<=n;i++) parent[i] = i;
    priority_queue<node> pq;
    while(e--){
        int a,b,c; cin >> a >> b >> c;
        pq.push({a,b,c});
    }
    int cnt = 0, ans = 0;
    while(cnt != n-2){
        node nd = pq.top();
        pq.pop();

        if(find_parent(nd.s) != find_parent(nd.e)){
            union_parent(nd.s, nd.e);
            ans += nd.c;
            cnt++;
        }
    }
    cout << ans;
    
    
    return 0;
}