#include<bits/stdc++.h>
using namespace std;

vector<int> vec[100001];
int query[100001];
bool visited[100001];
int dfs(int root){

    // cout << root << "\n";
    int temp = 1;
    for(auto k : vec[root]){
        if(!visited[k]){
            visited[k] = 1;
            temp += dfs(k);
        }
    }
    query[root] = temp;
    return temp;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,r,Q; cin >> n >> r >> Q;
    
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    visited[r]= 1;
    int temp = dfs(r);


    while(Q--){
        int node; cin >> node;
        cout << query[node] << "\n";
    }

    // for(int i=1;i<=n;i++) cout << query[i] << " ";
    
    return 0;
}