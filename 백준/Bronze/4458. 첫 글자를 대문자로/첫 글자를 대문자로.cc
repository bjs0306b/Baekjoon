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
    string s;
    cin.ignore();
    while(n--){
        getline(cin, s);
        s[0] = toupper(s[0]);
        cout << s << '\n';
    }
    
    return 0;
}