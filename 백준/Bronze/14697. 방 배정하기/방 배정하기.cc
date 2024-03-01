#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

set<int> s;

void func(int a, int b, int c){
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(a+b);
    s.insert(a+c);
    s.insert(b+c);
    s.insert(a+b+c);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,n; cin >> a >> b >> c >> n;
    vector<int> va,vb,vc;
    for(int i=1;i<=ceil(n/a);i++){
        va.push_back(i*a);
    }
    for(int i=1;i<=ceil(n/b);i++){
        vb.push_back(i*b);
    }
    for(int i=1;i<=ceil(n/c);i++){
        vc.push_back(i*c);
    }
    
    for(auto aa : va){
        for(auto bb : vb){
            for(auto cc : vc){
                func(aa,bb,cc);
            }
        }
    }

    if(s.find(n) != s.end()) cout << 1;
    else cout << 0;
    return 0;
}