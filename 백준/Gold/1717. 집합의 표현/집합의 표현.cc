#include <bits/stdc++.h>
using namespace std;

int parent[1000001];

int find(int a){    
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
void union_parent(int a, int b){
    int p1 = find(a), p2 = find(b);
    if(p1 < p2) parent[p1] = p2;
    else parent[p2] = p1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i] = i;
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        if(a){
            if(find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            union_parent(b,c);
        }
    }

    return 0;
}