#include <bits/stdc++.h>
using namespace std;

bool func(){
    int a,b; cin >> a >> b;
    if(a == 1){
        if(b == 2) return false;
        return true;
    }
    else if(a == 2){
        if(b == 3) return false;
        return true;
    }
    else if(a == 3){
        if(b == 1) return false;
        return true;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    if(func()) cout << "A";
    else cout << "B";


    return 0;
}