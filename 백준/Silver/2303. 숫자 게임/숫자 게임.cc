#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int mxmx =0, ans;
    for(int i=1;i<=n;i++){
        int arr[5]; for(int j=0;j<5;j++) cin >> arr[j];
        int mx = 0;
        for(int j=0;j<3;j++){
            for(int k=j+1;k<4;k++){
                for(int l=k+1;l<5;l++){
                    mx = max(mx,(arr[j]+arr[k]+arr[l])%10);
                }
            }
        }
        if(mxmx <= mx){
            mxmx = mx;
            ans = i;
        }
    }
    cout << ans;
    
    
    return 0;
}