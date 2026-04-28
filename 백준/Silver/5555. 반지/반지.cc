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
    string s; cin >> s;
    int n; cin >> n;
    int ans = 0;
    while(n--){
        string str; cin >> str;
        str += str;
        str.find(s) != string::npos ? ans++ : ans;
    }
    cout << ans;
    
    return 0;
}