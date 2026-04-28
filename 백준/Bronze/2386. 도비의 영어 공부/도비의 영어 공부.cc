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
    char c;
    for(;;){
        cin >> c; if(c == '#') break;
        int cnt = 0;
        string s; getline(cin, s);
        for(auto k : s){
            if(c == tolower(k))
                cnt++;
        }
        cout << c <<  " " << cnt << "\n";
    }
    
    
    return 0;
}