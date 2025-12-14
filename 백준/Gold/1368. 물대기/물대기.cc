#include <bits/stdc++.h>
using namespace std;

struct edge{
    int dis, n1, n2;

    bool operator<(const edge& other) const{
        if(dis == other.dis) return n1 <= other.n1;
        return dis > other.dis;
    }
};

int n;
priority_queue<edge> pq;

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int num; cin >> num;
        pq.push({num, 0, i});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num; cin >> num;
            if(i < j){
                pq.push({num, i, j});
            }
        }
    }
}

vector<int> parent;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    int x = find(a);
    int y = find(b);

    if(x > y) swap(x,y);
    parent[x] = y;
}

int kruskal(){
    parent.resize(n+1);
    for(int i=0;i<=n;i++) parent[i] = i;

    int cnt = n, ans = 0;
    while(cnt){
        auto temp = pq.top();
        pq.pop();
        if(find(temp.n1) == find(temp.n2)) continue;
        merge(temp.n1, temp.n2);
        cnt--;
        ans += temp.dis;
    }

    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << kruskal();

    return 0;
}