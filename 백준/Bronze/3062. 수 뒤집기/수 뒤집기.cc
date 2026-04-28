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
    while(n--){
        string s; cin >> s;
        int a = stoi(s);
        reverse(s.begin(), s.end());
        int b = stoi(s);
        int temp = a + b;
        string t = to_string(temp);
        string r = t;
        reverse(r.begin(), r.end());
        if(t == r) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}