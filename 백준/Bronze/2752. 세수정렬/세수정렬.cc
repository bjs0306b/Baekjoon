#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    set<int> s;
    for(int i=0;i<3;i++){
        int n; cin >> n; s.insert(n);
    }
    for(auto a : s) cout << a << " ";
    
    
    return 0;
}