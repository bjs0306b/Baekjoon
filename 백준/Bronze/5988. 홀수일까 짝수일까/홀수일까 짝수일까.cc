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
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        if((s[s.size()-1]-'0')%2==0) cout << "even\n";
        else cout << "odd\n";
    }
    
    return 0;
}