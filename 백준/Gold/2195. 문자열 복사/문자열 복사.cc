#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s, p; cin >> s >> p;

    int ans = 0;
    for(int j=0;j<p.size();){
        int i=0;
        for(;;i++){
            if(j+i > p.size()) break;
            auto pos = s.find(p.substr(j, i));
            if(pos == string::npos) break;
        }
        j += i-1; 
        ans++;
    }
    cout << ans;
    
    return 0;
}