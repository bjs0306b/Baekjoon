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
    int a,b,c; cin >> a>>b>>c;
    int ans = b/2+c;
    if(a > ans) cout << ans;
    else cout << a;

    
    
    return 0;
}