#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int sum = 0;
    for(int i=0;i<4;i++){
        int n; cin >> n;
        sum += n;
    }
    if(sum <= 1500) cout << "Yes";
    else cout << "No";
    
    return 0;
}