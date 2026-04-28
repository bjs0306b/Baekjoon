#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin>>a>>b>>c;
    int d = min(a/2, b);
    cout << min(d,(a+b-c)/3);
    
    
    return 0;
}