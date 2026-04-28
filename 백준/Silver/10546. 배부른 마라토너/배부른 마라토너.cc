#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    map<string, int> m;
    for(int i=0;i<2*n-1;i++){
        string s; cin >> s;
        m[s]++;
    }

    for(auto k : m){
        if(k.second % 2) cout << k.first;
    }
    
    return 0;
}