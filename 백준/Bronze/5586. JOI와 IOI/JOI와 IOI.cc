#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
#include <string.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for(int i=0;i<s.size()-2;i++){
        if(s[i] == 'J' && s[i+1] == 'O' && s[i+2] == 'I') cnt1++;
        if(s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') cnt2++;
    }
    cout << cnt1 << "\n" << cnt2;

    
    return 0;
}