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
    int n; char c; cin >> n >> c;
    set<string> ss;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        ss.insert(s);
    }
    int size = ss.size();

    if(c == 'Y') cout << size;
    else if(c == 'F') cout << size/2;
    else if(c == 'O') cout << size/3;
    
    
    return 0;
}