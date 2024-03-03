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
    long long a,b,c; cin >> a >> b >> c;
    int rank = 1;
    vector<long long> v;
    if(a == 0){cout << 1; return 0;}
    for(int i=0;i<a;i++){
        long long num; cin >> num;
        if(i<c) v.push_back(num);
    }
    for(auto k : v){
        if(k <= b) break;
        rank++;
    }
    if(*min_element(v.begin(), v.end()) >= b && c <= a) cout << -1;
    else cout << rank;

    return 0;
}   