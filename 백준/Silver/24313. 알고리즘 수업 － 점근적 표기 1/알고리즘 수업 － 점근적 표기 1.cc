#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,d; cin >>a>>b>>c>>d;
    if(a*d+b <= c*d && a <= c) cout << 1;
    else cout << 0;
    
    
    return 0;
}