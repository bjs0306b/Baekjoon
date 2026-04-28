#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int func(int a, int b){
    if(a%b==0) return b;
    return func(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int a = stoi(s.substr(0, s.find(':')));
    int b = stoi(s.substr(s.find(':')+1));
    int gcd = func(a,b);
    cout << a/gcd << ":" << b/gcd;

    
    
    return 0;
}