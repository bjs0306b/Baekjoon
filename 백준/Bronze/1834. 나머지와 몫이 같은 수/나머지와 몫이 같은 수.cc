#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n,sum; cin >> n;
    cout << n*(n-1)*(n+1)/2;
    
    return 0;
}