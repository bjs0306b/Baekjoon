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
    long long n; cin >> n;
    
    long long s = 0, e = pow(2,31.5);
    while(s<=e){
        long long m  = (s+e)/2;
        if(m*m < n) s = m + 1;
        else if(m*m >= n) e = m- 1;
    }
    cout << s;
    
    return 0;
}