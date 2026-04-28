#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    float a,b; cin >>a>>b;
    float ans = a*(100-b)/100;
    if(ans >= 100) cout << 0;
    else cout << 1; 
    return 0;
}