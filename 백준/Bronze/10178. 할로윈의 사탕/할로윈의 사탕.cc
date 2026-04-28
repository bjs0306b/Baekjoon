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
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        cout << "You get " << a/b << " piece(s) and your dad gets " << a%b << " piece(s).\n";
    }
    
    return 0;
}

