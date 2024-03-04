#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    a = a%b;
    int ans;
    for(int i=0;i<c-1;i++){
        a *= 10;
        a %= b;
    }
    a*=10;
    cout << a/b;
    
    return 0;
}