#include <bits/stdc++.h>
using namespace std;

int parent[300001];

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void union_find(int a, int b){
    
    int pa = find(a), pb = find(b);

    if(pa > pb) parent[pb] = pa;
    else parent[pa] = pb;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) parent[i] = i;

    for(int i=0;i<n-2;i++){
        int a,b; cin >> a >> b;
        union_find(a,b);
    }

    for(int i=2;i<=n;i++){
        if(find(1) != find(i)){
            cout << 1 << " " << i;
            return 0;
        }
    }
    

    return 0;
}