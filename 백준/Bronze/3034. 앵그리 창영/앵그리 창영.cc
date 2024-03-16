#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,a,b; cin >> n >> a >> b;
    while(n--){
        int x; cin >> x;
        if(a*a+b*b >= x*x) cout << "DA\n";
        else cout << "NE\n";
    }
    
    
    return 0;
}