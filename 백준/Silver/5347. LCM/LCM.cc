#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n; cin >> n;
    while(n--){
        long long a,b; cin >> a >> b;
        cout << a/gcd(a,b)*b <<"\n";
    }
    
    return 0;
}