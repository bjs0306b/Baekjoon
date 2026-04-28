#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    if(s.size() == 4) cout << 20;
    else if(s[1] == '0'){
        int n = s[2] - '0';
        cout<< 10+n;
    } 
    else if(s[2] == '0'){
        int n = s[0] - '0';
        cout << 10+n;
    }
    else{
        int m = s[0] - '0';
        int n = s[1] - '0';
        cout << m+n;
    }
    
    return 0;
}