#include <bits/stdc++.h>
using namespace std;

struct node{
    int dis, n1,n2;

    bool operator<(const node other) const{
        if(dis == other.dis) return n1 > other.n1;
        return dis > other.dis;
    }
};

int n, ans;
priority_queue<node> pq;
vector<int> parent;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    int aa = find(a), bb = find(b);
    if(aa > bb) swap(aa,bb);
    parent[aa] = bb;
}

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<n;j++){
            char c = s[j];
            int num;
            if(c >= 'a' && c <= 'z') num = c - 'a' + 1;
            else if(c >= 'A' && c <= 'Z') num = c- 'A' + 27;
            else continue;

            ans += num;
            if(i != j) pq.push({num, i, j});
        }
    }
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i] = i;
}

int solve(){
    int cnt = n-1;
    while(cnt){
        if(pq.empty()) return -1;
        node t = pq.top();
        pq.pop();

        int n1 = find(t.n1), n2 = find(t.n2);

        if(n1 == n2) continue;

        merge(n1, n2);
        cnt--;
        ans -= t.dis;
    }
    return ans;
}



int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}