#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
using namespace std;
int a,b,arr[10],visited[100001];
set<int> s;
void dfs(int n){
    if(n == b){
        for(int i=0;i<b;i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for(auto a : s){
            if(!visited[a]){
                arr[n] = a;
                visited[a] = 1;
                dfs(n+1);
                visited[a] = 0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a;i++) {int num; cin >> num; s.insert(num);}
    dfs(0);
    
    return 0;
}