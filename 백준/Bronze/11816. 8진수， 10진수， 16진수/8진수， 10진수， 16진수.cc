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
    string s; cin >> s;
    if(s[0] == '0'){
        if(s[1] == 'x'){
            cout << stoi(s, nullptr, 16) << '\n';
        }
        else{
            cout << stoi(s, nullptr, 8) << '\n';
        }
    }
    else{
        cout << s << '\n';
    }
    
    
    return 0;
}