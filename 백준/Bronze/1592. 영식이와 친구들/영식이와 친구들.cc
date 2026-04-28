#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    cout << (a/gcd(a,c))*(b-1);
    
    
    return 0;
}