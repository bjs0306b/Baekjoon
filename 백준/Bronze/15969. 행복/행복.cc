#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    set<int> s; while(n--){int num; cin >> num; s.insert(num);}
    cout << *--s.end() - *s.begin();
    
    return 0;
}