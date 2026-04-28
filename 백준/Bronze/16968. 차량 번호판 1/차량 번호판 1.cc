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
    int ans;
    if(s[0] == 'c') ans = 26;
    else ans = 10;
    for(int i=1;i<s.size();i++){
        if(s[i] == 'c'){
            if(s[i-1] == 'c')
                ans *= 25;
            else ans *= 26;
        }
        else if(s[i] == 'd'){
            if(s[i-1] == 'd') ans *= 9;
            else ans *= 10;
        }
    }
    cout << ans;
    
    return 0;
}