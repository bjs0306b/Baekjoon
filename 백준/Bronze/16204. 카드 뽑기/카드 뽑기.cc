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
    int n,m,k; cin >> n >> m >> k;
    cout << min(m,k)+min(n-m,n-k);
    
    
    return 0;
}