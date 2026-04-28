#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b,c; cin>>a>>b>>c;
    if(a+b < 2*c) cout << a+b;
    else cout << a+b-2*c;
    
    return 0;
}