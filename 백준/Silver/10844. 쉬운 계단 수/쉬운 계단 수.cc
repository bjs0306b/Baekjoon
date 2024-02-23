#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <deque>
#include <cmath>
using namespace std;

long long dp[101][10];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<10;i++) dp[1][i] = 1;

    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j=1;j<9;j++){
            dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1])%1000000000;
        }
    }
    long long sum = 0;
    for(int i=0;i<=9;i++){
        sum =  (sum + dp[n][i])%1000000000;
    }
    cout << sum;
    return 0;
}


// 요건 메모리 초과
// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int n;
//     cin >> n;
//     deque<int> de;
//     for(int i=1;i<10;i++) de.push_back(i);
//     for(int i=1;i<n;i++){
//         int size = de.size();
//         for(int j=0;j<size;j++){
//             int fr = de.front();
//             if(fr == 0){de.push_back(1);}
//             else if(fr == 9){de.push_back(8);}
//             else{de.push_back(fr-1); de.push_back(fr+1);}
//             de.pop_front();
//         }
//     }
//     cout << (de.size())%1000000000;
    
//     return 0;
// }   

// 시간초과...
// long long arr[101], cnt = 0;
// int n;
// void dfs(int a){
//     if(a == n){cnt++; cnt%= 1000000000;}
//     else if(a==0){
//         for(int i=1;i<=9;i++){
//             arr[0] = i;
//             dfs(a+1);
//         }
//     }
//     else{
//         for(int i=0;i<=9;i++){
//             if(arr[a-1]-1 == i || arr[a-1]+1 == i){
//                 arr[a] = i;
//                 dfs(a+1);
//             }
//         }
//     }
// }
// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     cin >> n;
//     dfs(0);
//     cout << cnt;
//     return 0;
// }   