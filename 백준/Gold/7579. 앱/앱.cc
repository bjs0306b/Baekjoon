#include<bits/stdc++.h>
using namespace std;

int dp[10001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N >> M;
    int m[N], c[N];
    for(int i=0;i<N;i++) cin >> m[i];
    for(int i=0;i<N;i++) cin >> c[i];
    
    for(int i=0;i<N;i++){
        for(int j=10001-c[i];j>=0;j--){
            dp[j+c[i]] = max(dp[j+c[i]], dp[j] + m[i]);
        }
    }

    // for(int i=0;i<101;i++) cout << dp[i] << " ";
    // cout << "\n";

    for(int i=0;i<10001;i++){
        if(dp[i] >= M){
            cout << i;
            break;
        }
    }

    return 0;
}