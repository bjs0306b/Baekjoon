#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int l,a,b,c,d; cin >>l>>a>>b>>c>>d;
    int e,f;
    cout << l - max((a+c-1)/c, (b+d-1)/d);
    return 0;
}