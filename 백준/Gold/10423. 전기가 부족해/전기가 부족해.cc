#include <bits/stdc++.h>
using namespace std;

struct node{
    int n1,n2,c;
    bool operator<(const node other) const{
        if(c == other.c) return n1 < other.n1;
        return c > other.c;
    }
};

priority_queue<node> pq;
int n,m,k;
vector<int> power_from, parent;
vector<int> v[1001];
void input(){
    cin >> n >> m >> k;
    power_from.assign(n+1, 0);
    parent.resize(n+1); for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=0;i<k;i++){ 
        int num; cin >> num;
        power_from[num] = num;
    }
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        if(power_from[a] && power_from[b]) continue; // 발전소 끼리 연결 x
        pq.push({a,b,c});
    }
}

void dfs(int idx, int num, int pre_idx){
    power_from[idx] = num;
    for(auto k : v[idx]){
        if(k != pre_idx){
            dfs(k, num, idx);
        }
    }
}

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void solve(){
    int ans = 0;
    int cnt = n - k; // 연결해야 할 간선
    while(!pq.empty() && cnt){
        node t = pq.top(); 
        pq.pop();

        int p1 = find(t.n1), p2 = find(t.n2); // 사이클 확인
        if(p1 == p2) continue;
        if(p1 > p2) swap(p1,p2);
        parent[p1] = p2;
        
        // 둘 다 발전소랑 이어져있을 때
        if(power_from[t.n1] > 0 && power_from[t.n2] > 0) continue;
        
        // 둘 중에 하나는 발전소랑 이어져 있을 때 -> 연결 x 였던 트리의 power_from을 해당 발전소로
        if(power_from[t.n1] == 0 && power_from[t.n2] != 0) dfs(t.n1, power_from[t.n2], -1);
        if(power_from[t.n1] != 0 && power_from[t.n2] == 0) dfs(t.n2, power_from[t.n1], -1);

        // 간선 연결
        v[t.n1].push_back(t.n2);
        v[t.n2].push_back(t.n1);

        cnt--;
        ans += t.c;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}