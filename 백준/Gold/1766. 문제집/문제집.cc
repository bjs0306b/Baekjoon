#include<bits/stdc++.h>
using namespace std;

int cnt[32001];
vector<int> arr[32001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        arr[a].push_back(b);
        cnt[b]++;
    }

    queue<int> q;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1;i<=n;i++){
        if(cnt[i] == 0) pq.push(i);
    }

    while(!pq.empty()){

        int t = pq.top();
        cout << t << " ";
        pq.pop();

        for(auto k : arr[t]){
            if(--cnt[k] == 0) pq.push(k);
        }
    }
    
    return 0;
}