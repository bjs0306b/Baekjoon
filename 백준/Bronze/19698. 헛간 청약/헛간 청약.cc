#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,d; cin >>a>>b>>c>>d;
    int ans = (b/d)*(c/d);
    if(ans > a) cout << a;
    else cout << ans;
    
    
    return 0;
}