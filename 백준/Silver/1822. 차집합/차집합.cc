#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b, cnt = 0; cin >> a >> b;
    set<int> s1,s2,ans;
    while(a--){
        int x; cin >> x;
        s1.insert(x);
    }
    while(b--){
        int x; cin >> x;
        s2.insert(x);
    }
    for(auto k : s1){
        if(s2.find(k) == s2.end()){cnt++; ans.insert(k);}
    }
    cout << cnt << "\n";
    for(auto k : ans) cout << k << " ";
    return 0;
}