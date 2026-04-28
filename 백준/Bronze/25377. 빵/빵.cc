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
    int n; cin >> n;
    int min = 1001;
    while(n--){
        int a,b; cin >> a >> b;
        if(a<=b){
            if(b < min) min= b;
        } 
    }
    if(min == 1001) cout << -1;
    else cout << min;
    
    return 0;
}