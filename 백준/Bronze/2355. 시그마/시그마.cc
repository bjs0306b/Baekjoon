#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b;
    cin >> a >> b;
    if(a > b) swap(a,b);
    long long sum;
    sum = (b*(b+1)-a*(a-1))/2;
    cout << sum;
    return 0;
}