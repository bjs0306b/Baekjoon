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
    string s;
    for(;;){
        cin >> s;
        if(s == "0") break;
        int sum = s.size() + 1;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1') sum += 2;
            else if(s[i] == '0') sum += 4;
            else sum += 3;
        }
        cout << sum << "\n";
    }
    
    
    return 0;
}   