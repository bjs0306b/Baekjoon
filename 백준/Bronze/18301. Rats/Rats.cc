#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin >>a>>b>>c;
    int ans = (a+1)*(b+1)/(c+1)-1;
    cout << ans;
    
    
    return 0;
}