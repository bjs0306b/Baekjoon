#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n; cin >> n;
    vector<int> v;
    while(n){
        v.push_back(n%2);
        n /= 2;
    }
    for(auto iter = v.rbegin(); iter != v.rend(); iter++){
        cout << *iter;
    }
    
    return 0;
}