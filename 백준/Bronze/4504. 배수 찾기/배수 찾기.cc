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
    int m;
    for(;;){
        cin >> m;
        if(m == 0) break;
        cout << m << " is ";
        if(m%n) cout << "NOT ";
        cout << "a multiple of " << n << ".\n";
    }
    
    return 0;
}

