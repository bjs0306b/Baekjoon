#include <bits/stdc++.h>
using namespace std;

int k;

bool func(int a, int b){
    if(a>b){
        if(a > b + (k - a + 1) + 1) return false;
    }
    else if(a<b){
        if(b > a + k - b + 1) return false;
    }
    return true;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> k;
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        if(func(a,b)) cout << "1\n";
        else cout << "0\n";
    }
}