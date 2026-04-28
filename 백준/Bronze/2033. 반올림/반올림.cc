#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    for(int i=s.size()-1;i>0;i--){
        int num = s[i] - '0';
        if(num > 4) s[i-1]++;
        s[i] = '0';
    }
    if(s[0] == ':'){
        cout << "10";
        for(int i=1;i<s.size();i++) cout << s[i];
    }
    else cout << s;
    return 0;
}

