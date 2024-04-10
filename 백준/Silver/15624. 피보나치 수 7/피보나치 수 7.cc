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
    int n; cin >> n;
    if(n==0) cout << 0;
    if(n<=2) cout << 1;
    int a = 1;
    int b = 1;
    int c = a+b;

    for(int i=3;i<=n;i++){
        a = b;
        b = c;
        c = (a+b)%1000000007;
    }
    cout << b;
    
    return 0;
}