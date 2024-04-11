#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    if(a == 1) cout << 1;
    else if(a==2){
        if(b < 3) cout << 1;
        else if(b < 5) cout << 2;
        else if(b < 7) cout << 3;
        else cout << 4;
    }
    else{
        if(b < 7) cout << min(4,b);
        else cout << b-2;
    }
    
    
    return 0;
}