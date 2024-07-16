#include<bits/stdc++.h>
using namespace std;

int a,b,c; 
bool visited[100001];
set<int> edge[100001];
int orders[100001];
int order = 1;

void dfs(int n){
    visited[n] = 1;
    orders[n] = order++;
    for(auto k : edge[n]){
        if(!visited[k]) dfs(k);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b >> c;

    for(int i=0;i<b;i++){
        int n1,n2; cin >> n1 >> n2;
        edge[n1].insert(n2);
        edge[n2].insert(n1); 
    }

    dfs(c);

    for(int i=1;i<=a;i++) cout << orders[i] << "\n";

    
    
    return 0;
}