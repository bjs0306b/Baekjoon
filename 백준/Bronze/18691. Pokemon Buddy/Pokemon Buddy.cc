#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int group[3] = {1,3,5};
    for(int i=0;i<n;i++){
        int a,b,c; cin >> a >> b >> c;
        if(b >= c) cout << "0\n";
        else cout << (c-b)*group[a-1] << "\n";
    }
}