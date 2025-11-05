#include <bits/stdc++.h>
using namespace std;

set<string> exist_members;
map<string, int> m;
int parent[200001];
int members[200001];

int t, n;

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

int merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return members[v];
    }
    if(u > v) swap(u,v);
    members[v] += members[u];
    parent[u] = v;
    return members[v];
}

void input(){
    cin >> t;
    while(t--){
        exist_members.clear();
        m.clear();
        for(int i=0;i<200001;i++){parent[i] = i; members[i] = 1;}
        cin >> n;
        for(int i=0;i<n;i++){
            string a,b; cin >> a >> b;
            if(exist_members.find(a) == exist_members.end()){
                exist_members.insert(a);
                m[a] = exist_members.size();
            }
                
            if(exist_members.find(b) == exist_members.end()){
                exist_members.insert(b);
                m[b] = exist_members.size();
            }
                
            cout << merge(m[a], m[b]) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    
    return 0;
}