#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b,c,d; cin >>a>>b>>c>>d;
    string e,f; e = a+b; f =c+d;
    long long n1 = stoll(e), n2 = stoll(f);
    cout << n1+n2;
    
    
    return 0;
}