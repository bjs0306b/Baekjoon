#include <bits/stdc++.h>
using namespace std;

struct node{
    int n1,n2,dis;

    bool operator<(const node other) const{
        if(dis == other.dis) return n1 > other.n2;
        return dis > other.dis;
    }
};

int n,m, total_dis;
priority_queue<node> pq;
vector<int> parent;

bool input(){
    cin >> n >> m;
    if(n == 0 && m == 0) return false;

    pq = priority_queue<node>();
    parent.clear();
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i] = i;

    total_dis = 0;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        total_dis += c;
        pq.push({a,b,c});
    }
    return true;
}

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    int aa = find(a), bb = find(b);
    if(aa > bb) swap(aa,bb);
    parent[aa] = bb;
}

void solve(){
    int cnt = n-1;
    while(cnt){
        node temp = pq.top();
        pq.pop();

        int n1 = find(temp.n1), n2 = find(temp.n2);
        if(n1 == n2) continue;
        cnt--;
        merge(n1, n2);
        total_dis -= temp.dis;
    }
    cout << total_dis << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    while(input()){
        solve();
    }

    return 0;
}