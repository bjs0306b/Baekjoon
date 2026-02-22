#include <bits/stdc++.h>
using namespace std;

void solve(){
    int cur = 0;
    for(int i=0;i<10;i++){
        int num; cin >> num;
        cur = (cur + num) % 4;
    }
    // 0 : N, 1 : E, 2 : S, 3 : W
    if(cur == 0) cout << "N";
    if(cur == 1) cout << "E";
    if(cur == 2) cout << "S";
    if(cur == 3) cout << "W";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    solve();

    return 0;
}