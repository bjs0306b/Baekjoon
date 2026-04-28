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
    int a,b,c,d,e; cin >> a >> b >> c >> d >> e;
    int x,y;
    x = a*e;
    y = b;
    if(c<e) y += (e-c)*d;
    
    cout << min(x,y);
    return 0;
}