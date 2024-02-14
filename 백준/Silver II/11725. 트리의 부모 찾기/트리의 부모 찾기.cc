#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

bool visited[100001];
int arr[100001];
vector<int> v[100001];

void dfs(int n){
    visited[n] = true;
    for(int i=0;i<v[n].size();i++){
        int next = v[n][i];
        if(!visited[next]){
            arr[next] = n;
            dfs(next);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for(int i=2;i<n+1;i++) cout << arr[i] << "\n";
    
    
    return 0;
}