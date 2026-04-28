#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b; cin >> a>> b;
    long long mx = max(a,b);
    long long ll = mx;
    while(!(ll%a==0 && ll%b==0))
        ll += mx;
    cout << ll; 
    return 0;
}