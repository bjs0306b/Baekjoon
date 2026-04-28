#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a>> b;
    if(a>b) swap(a,b);
    int sum = 0; sum += a-1;
    sum += (b-1)*a;
    cout << sum;
    
    return 0;
}