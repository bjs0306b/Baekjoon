#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin>>a>>b>>c;
    if(a+b+c < 100){
        if(a == min({a,b,c})) cout << "Soongsil";
        else if(b == min({a,b,c})) cout << "Korea";
        else if(c == min({a,b,c})) cout << "Hanyang";
    }
    else cout << "OK";
    
    
    return 0;
}