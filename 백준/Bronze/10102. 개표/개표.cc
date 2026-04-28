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
    string s; cin >> s;
    int a = count(s.begin(), s.end(), 'A'), b = count(s.begin(), s.end(), 'B');
    if(a>b) cout << "A";
    else if(a<b) cout << "B";
    else cout << "Tie";
    
    
    return 0;
}