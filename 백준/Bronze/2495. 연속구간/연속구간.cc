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
    for(int i=0;i<3;i++){
        string s; cin >> s;
        int mx_cnt = 1, ans = 1;
        for(int j=0;j<s.size()-1;j++){
            if(s[j] == s[j+1]) mx_cnt++;
            else{ans = max(ans,mx_cnt); mx_cnt = 1;}
        }
        ans = max(ans,mx_cnt);
        cout << ans << "\n";
    }
    
    
    return 0;
}