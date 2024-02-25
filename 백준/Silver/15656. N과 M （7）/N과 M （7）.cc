#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int m,n, arr[8];
set<int> v;
void dfs(int a){
    if(a == n){
        for(int i=0;i<n;i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for(auto k : v){
            arr[a] = k;
            dfs(a+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;i++){int num; cin >> num; v.insert(num);}
    dfs(0);

    return 0;
}