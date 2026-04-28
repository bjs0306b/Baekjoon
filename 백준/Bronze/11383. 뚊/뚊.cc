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
    int a,b; cin >> a >> b;  bool check = true;
    vector<string> v(a); for(int i=0; i<a; i++) cin >> v[i];
    for(int i=0;i<a;i++){
        string str; cin >> str;
        
        auto iter = str.begin();
        for(auto k : v[i]){
            if(k != *iter++){check = false; break;}
            if(k != *iter++){check = false; break;}
        }
        if(!check) break;
    }
    if(check) cout << "Eyfa";
    else cout << "Not Eyfa";
    
    return 0;
}