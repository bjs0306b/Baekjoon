#include <bits/stdc++.h>
using namespace std;

int n, ans, len;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        if(a > b) swap(a,b);
        v[i] = {a,b};
    }
    sort(v.begin(), v.end(), compare);
    cin >> len;
}

void solve(){
    for(int i=0;i<n;i++){
        if(v[i].second - v[i].first > len) continue;
        pq.push(v[i].first);
        while(!pq.empty() && v[i].second - pq.top() > len) pq.pop();
        int size = pq.size();
        ans = max(ans, size);
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();
}