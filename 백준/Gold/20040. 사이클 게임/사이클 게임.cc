#include<bits/stdc++.h>
using namespace std;

// unordered_map<int,int> parent;
int parent[1000001];
int find(int a){
    if(parent[a] == a) return a;
  
    parent[a] = find(parent[a]);
    return parent[a];
    
}

void union_find(int a, int b){
    int t1 = find(parent[a]), t2 = find(parent[b]);
    if(t1 > t2) parent[t1] = t2;
    else parent[t2] = t1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;

        if(find(a) == find(b)){
            cout << i+1; return 0;
        }
        union_find(a,b);
    }
    cout << "0";
    return 0;
}