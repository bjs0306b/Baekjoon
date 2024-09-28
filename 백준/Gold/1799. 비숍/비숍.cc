#include <bits/stdc++.h>
using namespace std;

bool arr[19][19]; // [우상향(x+y)] [좌상향(x-y+n-1)]
bool b1[19]; // 우상향 방문
bool b2[19]; // 좌상향 방문
int n;
int ans = 0;
void dfs(int row, int cnt){
    if(row >= 2*n-1) ans = max(ans, cnt);

    else{
        bool flag = true;

        for(int i=0;i<2*n;i++){
            if(arr[row][i] && !b1[row] && !b2[i]){
                flag = false;
                b1[row] = 1;
                b2[i] = 1;

                dfs(row+2, cnt+1);

                b1[row] = 0;
                b2[i] = 0;
            }
        }
        if(flag) dfs(row+2, cnt);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool b; cin >> b;
            if(b) arr[i+j][i-j+n-1] = 1;
        }
    }

    dfs(0,0);
    int temp = ans;
    ans = 0;
    dfs(1,0);

    cout << ans + temp;

    return 0;
}