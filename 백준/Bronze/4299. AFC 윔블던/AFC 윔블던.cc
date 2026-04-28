#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b; cin >>a>>b;
    if((a+b)%2 || a < b) cout << -1;
    else cout << (a+b)/2 << " " << (a-b)/2;
    
    return 0;
}