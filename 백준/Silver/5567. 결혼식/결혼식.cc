#include<bits/stdc++.h>
using namespace std;

vector<int> v[501];
bool arr[501];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int m; cin >> m;

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair<int,int>> q;

    q.push({1,0});
    int ans = 0;
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        if(temp.second > 2) break;

        arr[temp.first] = true;
        ans++;

        for(auto k : v[temp.first]){
            if(!arr[k]){q.push({k, temp.second+1}); arr[k]=true;}
        }        
    }

    cout << ans-1;
    return 0;
}