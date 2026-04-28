#include<bits/stdc++.h>
using namespace std;

vector<int> arr[1001];
int cnt[1001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int num; cin >> num;
        vector<int> v(num);
        for(int j=0;j<num;j++){
            cin >> v[j];
        }

        for(int j=0;j<num-1;j++){
            arr[v[j]].push_back(v[j+1]);
            cnt[v[j+1]]++;
        }
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(cnt[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        ans.push_back(f);

        for(auto k : arr[f]){
            if(--cnt[k] == 0) q.push(k);
        }
    }

    if(ans.size() == n){
        for(auto k : ans) cout << k << "\n";
    }
    else cout << 0;
    

    
    return 0;
}