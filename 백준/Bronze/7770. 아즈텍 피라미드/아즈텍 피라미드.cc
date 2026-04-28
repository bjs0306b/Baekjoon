#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    int ans = 0;
    int cnt = 0;
    for(;;){
        cnt += (ans * ans + (ans+1)*(ans+1));
        if(cnt > n) break;
        ans++;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    cout << solve(n);

    return 0;
}