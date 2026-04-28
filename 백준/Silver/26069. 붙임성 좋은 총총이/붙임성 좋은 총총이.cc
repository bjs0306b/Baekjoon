#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    set<string> s;
    bool check = false;
    while(n--){
        string a,b; cin >> a >> b;
        if(a == "ChongChong" || b == "ChongChong"){
            check = true;
            s.insert(a); s.insert(b);
        }

        if(check){
            if(s.find(a) != s.end()) s.insert(b);
            if(s.find(b) != s.end()) s.insert(a);
        }
    }
    cout << s.size();
    
    return 0;
}