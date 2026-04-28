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
    string s;
    multiset<long long> ms;
    while(n--){
        cin >> s;
        reverse(s.begin(),s.end());
        long long temp = stoll(s);
        ms.insert(temp);
    }
    for(auto k : ms) cout << k << "\n";
    
    
    return 0;
}