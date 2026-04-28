#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int k,d,a; char c1,c2;
    cin >> k>>c1>>d>>c2>>a;
    if(k+a < d || d == 0) cout << "hasu";
    else cout << "gosu";
    
    
    return 0;
}