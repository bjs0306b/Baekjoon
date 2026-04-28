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
    long long a,b,c; cin >> a >> b >> c;
    cout << ((a+c-1)/c) * ((b+c-1)/c);
    
    return 0;
}