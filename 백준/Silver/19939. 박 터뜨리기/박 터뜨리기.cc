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
    int a,b; cin >> a >> b;
    if(a < b*(b+1)/2) cout << -1;
    else{
        if((a-b*(b+1)/2)%b) cout << b;
        else cout << b-1;
    }
    
    
    return 0;
}