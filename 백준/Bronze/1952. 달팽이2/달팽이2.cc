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
    int m,n; cin >> m >> n;
    
    if(m <= n) cout << 2*m-2;
    else cout << 2*n-1; 
    
    
    return 0;
}