#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int arr[n][m]; for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> arr[i][j];


    int ans = 0;
    for(int i=0;i<n;i++){
        int cnt1 = 0, cnt2 = 0, pre_num = 0;
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                if(cnt1 || cnt2) ans += min(cnt1, cnt2)+1;
                cnt1=0, cnt2=0;
                pre_num = 0;
            }
            else if(arr[i][j] == 1){
                if(pre_num == 0 || pre_num == 2) cnt1++;
                pre_num = 1;
            }
            else if(arr[i][j] == 2){
                if(pre_num == 0 || pre_num == 1) cnt2++;
                pre_num = 2;
            }   
        }
        // cout << cnt1 << " " << cnt2 << "\n";
        if(cnt1 || cnt2) ans += min(cnt1, cnt2) + 1;
    }

    cout << ans;

    return 0;
}