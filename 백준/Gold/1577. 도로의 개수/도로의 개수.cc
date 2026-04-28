#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,m; cin >> n >> m;
    vector<vector<long long>> v(n+1, vector<long long>(m+1,0));
    vector<vector<vector<bool>>> is_blocked(n + 1, vector<vector<bool>>(m + 1, vector<bool>(2, 0))); // 0 -> 가로, 1-> 세로
    long long k; cin >> k;
    while(k--){
        long long a,b,c,d; cin >> a >> b >> c >> d;
        if(a == c){ // 가로 길이 막힐 때
            is_blocked[a][min(b,d)][0] = true;
        }
        else{
            is_blocked[min(a,c)][b][1] = true;
        }
    }
    v[0][0] = 1;

    for(long long i=1;i<=n;i++){
        if(is_blocked[i-1][0][1]) break;
        v[i][0] = 1;
    }
     for(long long i=1;i<=m;i++){
        if(is_blocked[0][i-1][0]) break;
        v[0][i] = 1;
    }


    
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            long long sum = 0;
            if(!is_blocked[i-1][j][1]) sum += v[i-1][j];
            if(!is_blocked[i][j-1][0]) sum += v[i][j-1];
            v[i][j] = sum;
        }
    }
    // for(long long i=n;i>=0;i--){
    //     for(long long j=0;j<=m;j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << v[n][m];


    return 0;
}