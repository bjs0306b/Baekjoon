#include <bits/stdc++.h>
using namespace std;

bool solve(){
    int a,b; cin >> a >> b;
    for(int i=0;i<a;i++){
        if(b % 2 == 0) return false;
        b /= 2;
    }
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for(int i=1;i<=t;i++){
        cout << "#" << i << " ";
        if(solve()) cout << "ON\n";
        else cout << "OFF\n";
    }
    

    return 0;
}