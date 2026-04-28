#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int a,b,arr[9];
vector<int> v; 
bool visited[10001];

void dfs(int n, int m){
    if(n == b){
        for(int i=0;i<b;i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=m;i<v.size();i++){
            if(!visited[v[i]]){
                arr[n] = v[i];
                visited[v[i]] = true;
                dfs(n+1, i+1);
                visited[v[i]] = false;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a>>b;
    for(int i=0;i<a;i++){int num; cin >> num; v.push_back(num);}
    sort(v.begin(), v.end());
    dfs(0,0);
    
    return 0;
}