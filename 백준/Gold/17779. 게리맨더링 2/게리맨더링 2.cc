#include <bits/stdc++.h>
using namespace std;

int n;
int A[21][21];
int ans = INT32_MAX;

void input(){
    cin >> n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> A[i][j];
}

void ward(int x, int y, int d1, int d2){
    int temp[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            temp[i][j] = 0;
        }
    }
    
    // 경계선

    // 1
    for(int i=0;i<=d1;i++) temp[x+i][y-i] = 5;
    // 2
    for(int i=0;i<=d2;i++) temp[x+i][y+i] = 5;
    // 3
    for(int i=0;i<=d2;i++) temp[x+d1+i][y-d1+i] = 5;
    // 4
    for(int i=0;i<=d1;i++) temp[x+d2+i][y+d2-i] = 5;

    // 선거구

    // 1
    for(int i=1;i<x+d1;i++){
        for(int j=1;j<=y;j++){
            if(temp[i][j] == 5) break;
            temp[i][j] = 1;
        }
    }
    // 2
    for(int i=1;i<=x+d2;i++){
        for(int j=n;j>y;j--){
            if(temp[i][j] == 5) break;
            temp[i][j] = 2;
        }
    }
    // 3
    for(int i=x+d1;i<=n;i++){
        for(int j=1;j<y-d1+d2;j++){
            if(temp[i][j] == 5) break;
            temp[i][j] = 3;
        }
    }
    // 4
    for(int i=x+d2+1;i<=n;i++){
        for(int j=n;j>=y-d1+d2;j--){
            if(temp[i][j] == 5) break;
            temp[i][j] = 4;
        }
    }

    // 남은 부분 5로 채우기
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(temp[i][j] == 0) temp[i][j] = 5;
        }
    }



    vector<int> cnt(6,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cnt[temp[i][j]] += A[i][j];
        }
    }
    

    int mx = 0, mn = INT32_MAX;
    for(int i=1;i<=5;i++){
        mx = max(mx, cnt[i]);
        mn = min(mn, cnt[i]);
    }

    ans = min(ans, mx-mn);
}

void solve(){
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            for(int d1=1;d1<=n;d1++){
                for(int d2=1;d2<=n;d2++){
                    if(x + d1 + d2 <= n && 1 <= y-d1 && y+d2 <= n){
                        ward(x, y, d1, d2);
                    }
                }
            }
        }
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}