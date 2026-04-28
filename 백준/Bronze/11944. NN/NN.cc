#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    string s = to_string(n);
    for(int i=0;i<n;i++){
        for(auto k : s){
            cout << k; m--;
            if(m==0) break;
        }
        if(m==0) break;
    }
    
    return 0;
}