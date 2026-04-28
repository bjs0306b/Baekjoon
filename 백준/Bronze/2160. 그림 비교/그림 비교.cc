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
    int mn = 10000000, ans1, ans2;
    char arr[n][5][7]; for(int i = 0; i < n; i++) for(int j = 0; j < 5; j++) for(int k=0;k<7;k++)cin >> arr[i][j][k];
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int cnt = 0;
            for(int k=0;k<5;k++){
                for(int l=0;l<7;l++){
                    if(arr[i][k][l] != arr[j][k][l])cnt++;
                }
            }
            if(cnt < mn){
                mn = cnt;
                ans1 = i+1;
                ans2 = j+1;
            }
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}