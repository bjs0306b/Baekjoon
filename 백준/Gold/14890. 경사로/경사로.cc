#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l; cin >> n >> l;
    int A[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[i][j];
    vector<int> v[2*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v[i].push_back(A[i][j]);
            v[n+i].push_back(A[j][i]);
        }
    }

    int ans = 0;

    for(int j=0;j<2*n;j++){
        vector<int> temp = v[j];
        bool flag1 = true, flag2 = true, ascend = true;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(abs(temp[i-1]-temp[i]) > 1) {flag1 = false; break;}
            
            if(temp[i-1] < temp[i]){
                if(!ascend && cnt < l*2 || cnt < l) {flag1 = false; break;}
                ascend = true;
                cnt = 1;
            }
            else if(temp[i-1] > temp[i]){
                ascend = false;
                cnt = 1;
            }
            else cnt++;
        }
        
        cnt = 1;
        ascend = true;
        for(int i=n-1;i>0;i--){
            if(abs(temp[i-1]-temp[i]) > 1) {flag2 = false; break;}

            if(temp[i-1] > temp[i]){
                if(!ascend && cnt < l*2 || cnt < l) {flag2 = false; break;}
                ascend = true;
                cnt = 1;
            }
            else if(temp[i-1] < temp[i]){
                ascend = false;
                cnt = 1;
            }
            else cnt++;
        }

        if(flag1 && flag2) ans++;
    }
    cout << ans;
    
    return 0;
}