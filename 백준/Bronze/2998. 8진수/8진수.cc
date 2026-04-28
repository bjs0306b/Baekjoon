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
    int size = s.size()%3;
    if(size == 1){
        cout << s[0];
    }
    else if(size == 2){
        cout << (s[0]-'0')*2 + (s[1]-'0');
    }
    for(int i = size; i < s.size(); i+=3)
    {
        cout << (s[i]-'0')*4 + (s[i+1]-'0')*2 + (s[i+2]-'0');
    }
    
    
    return 0;
}