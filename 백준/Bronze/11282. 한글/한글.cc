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
    string s;
    n+=3071;    
    s.push_back(n/4096+234);
    s.push_back(n/64%64+128);
    s.push_back(n%64+128);
    cout << s;
    
    return 0;
}