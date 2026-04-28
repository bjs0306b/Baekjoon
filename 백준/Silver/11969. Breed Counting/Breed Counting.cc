#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n,q; cin >> n >> q;
    int cnt[n+1][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cnt[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++) cnt[i][j] = cnt[i-1][j];
        int num; cin >> num;
        num--;
        cnt[i][num]++;    
    }

    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b;

        for(int j=0;j<3;j++){
            cout << cnt[b][j] - cnt[a-1][j] << " ";
        }
        cout << "\n";
    }
}