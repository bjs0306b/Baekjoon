#include<bits/stdc++.h>
using namespace std;

int p[10001];

struct node{
    int from, to , cost;

    bool operator<(const node other) const{
        return cost > other.cost;
    }
};

int parent(int n){
    if(p[n] == n) return n;
    else return parent(p[n]);
}

bool is_cycle(int a, int b){
    if(parent(a) == parent(b)) return true;
    return false;
}

void union_parent(int a, int b){
    int p1 = parent(a), p2 = parent(b);
    if(p1 < p2) p[p1] = p2;
    else p[p2] = p1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    for(int i=1;i<=a;i++) p[i] = i;
    priority_queue<node> pq;
    while(b--){
        int f,t,c; cin >> f >> t >> c;
        pq.push({f,t,c});
    }
    int ans = 0;
    int cnt = a-1;
    while(cnt){
        auto temp = pq.top();
        pq.pop();

        if(!is_cycle(temp.to, temp.from)){
            cnt--;
            ans += temp.cost;
            union_parent(temp.to, temp.from);
        }
    }
    cout << ans;
    
    
    return 0;
}