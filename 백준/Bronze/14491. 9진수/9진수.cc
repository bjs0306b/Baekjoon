#include <bits/stdc++.h>
using namespace std;

int n;
void input(){
    cin >> n;
}

void solve(){
    vector<int> v;
    while(n){
        v.push_back(n % 9);
        n /= 9;
    }
    for(int i = v.size()-1; i>=0;i--) cout << v[i]; 
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}