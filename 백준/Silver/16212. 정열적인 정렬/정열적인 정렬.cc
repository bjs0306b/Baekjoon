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
    multiset<int> s;
    while(n--){int num; cin >> num; s.insert(num);}
    for(auto k : s) cout << k << " ";
    
    return 0;
}