#include <iostream>
#include <algorithm>
#include <memory.h>
#include <deque>
using namespace std;

int a,b,c; 
int visit[1001]; 
int arr[1001][1001];

void dfs(int n){
    cout << n << " ";
    visit[n] = 1;
    for(int i=1;i<a+1;i++){
        if(arr[n][i] && !visit[i]){
            dfs(i);
        }
    }
}

void bfs(int n){
    deque<int> v; 
    v.push_back(n);
    visit[n] = 1;
    while(!v.empty()){
        int temp = v.front(); v.pop_front();  cout << temp << " ";
        for(int i=1;i<a+1;i++){
            if(arr[temp][i] && !visit[i]){
                v.push_back(i);
                visit[i] = 1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >>a>>b>>c;
    memset(visit, 0, (a+1)*sizeof(int));
    memset(arr, 0, (a+1)*(a+1)*sizeof(int));
    for(int i=0;i<b;i++){
        int d,e; cin >>d>>e;
        arr[d][e] = 1;
        arr[e][d] = 1;
    }
    dfs(c);
    memset(visit, 0, (a+1)*sizeof(int));
    cout << "\n";
    bfs(c);
    
    return 0;
}