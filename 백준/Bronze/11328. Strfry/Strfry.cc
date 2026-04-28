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
        string a,b; cin >> a >> b;
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        if(a == b) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    
    return 0;
}