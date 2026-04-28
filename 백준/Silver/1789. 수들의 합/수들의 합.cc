#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n,k; cin >> n;
    for(k=0; k*(k+1)/2 <= n; k++);
    cout << k-1;
    return 0;
}