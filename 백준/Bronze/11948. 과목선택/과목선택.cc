#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,d,e,f; cin >>a>>b>>c>>d>>e>>f;
    cout << a+b+c+d-min({a,b,c,d})+max(e,f); 
    
    
    return 0;
}