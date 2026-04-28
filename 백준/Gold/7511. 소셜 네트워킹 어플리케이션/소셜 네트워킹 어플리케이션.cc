#include <bits/stdc++.h>
using namespace std;

int parent[1000001];

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    int a = find(u), b = find(v);
    if(a == b) return;

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int s=1;s<=t;s++){
        cout << "Scenario " << s << ":\n";
        int n; cin >> n;
  
        for(int i=0;i<n;i++)parent[i] = i;
        
        int k; cin >> k;
        for(int i=0;i<k;i++){
            int a,b; cin >> a >> b;
            merge(a,b);
        }

        int m; cin >> m;
        for(int i=0;i<m;i++){
            int a,b; cin >> a >> b;
            if(find(a) == find(b)) cout << "1\n";
            else cout << "0\n";
        }
        cout << "\n";
    }
    
}