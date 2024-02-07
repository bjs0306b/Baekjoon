#include <iostream>
#include <algorithm>
using namespace std;
int n,m,arr[1001][1001],visited[1001];

void dfs(int k){
    visited[k]=1;
    for(int i=1;i<n+1;i++){
        if(arr[k][i]==1 && !visited[i]){
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        arr[a][b]=1; arr[b][a]=1;
    }  
    int cnt = 0; 
    for(int i=1;i<n+1;i++){
        if(visited[i] == 1) continue;
        dfs(i); cnt++;
    }
    cout << cnt;
    return 0;
}