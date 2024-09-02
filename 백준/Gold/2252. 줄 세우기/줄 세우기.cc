#include<bits/stdc++.h>
using namespace std;

vector<int> vec[32001];
bool visited[32001];

void func(int num){
    if(!visited[num]){
        for(auto k : vec[num]){
            func(k);
        }
        cout << num << " ";
        visited[num] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    while(m--){
        int f,t; cin >> f >> t;  // from , to 
        vec[t].push_back(f);
    }

    for(int i=1;i<=n;i++){
        func(i);
    }
    
    return 0;
}