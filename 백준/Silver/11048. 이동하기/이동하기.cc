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
    int a,b; cin >> a >> b;
    int arr[a][b], dp[a][b]; for(int i=0;i<a;i++) for(int j=0;j<b;j++){cin >> arr[i][j]; dp[i][j]=arr[i][j];}

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(i < a-1) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + arr[i+1][j]);
            if(j < b-1) dp[i][j+1] = max(dp[i][j+1], dp[i][j] + arr[i][j+1]);
        }
    }
    cout << dp[a-1][b-1];
    return 0;
}