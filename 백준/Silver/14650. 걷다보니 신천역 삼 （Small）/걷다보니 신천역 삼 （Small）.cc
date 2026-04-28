#include <bits/stdc++.h>
using namespace std;

int n;

void input(){
    cin >> n;
}

int solve(){
    if(n == 1) return 0;
    if(n == 2) return 2;
    int temp = 2;
    for(int i=2;i<n;i++){
        temp *= 3;
    }
    return temp;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}