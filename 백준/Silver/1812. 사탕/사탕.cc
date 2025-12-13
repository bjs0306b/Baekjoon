#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++){
        int ans = 0;
        for(int j=0;j<n;j++){
            int num = v[(i+j)%n];
            if(j%2) num *= -1;
            ans += num;
        }
        cout << ans/2 << "\n";
    }

    return 0;
}