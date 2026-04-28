#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
vector<int> v[200];
int cnt, a,arr[3];

void dfs(int n, int s){
    if(n == 3){
        for(auto k : v[arr[0]]){
            if(k == arr[1] || k == arr[2]){
                return;
            }
        }
        for(auto k : v[arr[1]]){
            if(k == arr[0] || k == arr[2]){
                return;
            }
        }
        for(auto k : v[arr[2]]){
            if(k == arr[1] || k == arr[0]){
                return;
            }
        }
        cnt++; return;
    }
    else{
        for(int i=s;i<a;i++){
            arr[n] = i+1;
            dfs(n+1,i+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int b; cin >> a >> b;
    while(b--){
        int c,d; cin >> c >> d;
        v[c].push_back(d);
    }
    dfs(0,0);
    cout << cnt;
    
    return 0;
}