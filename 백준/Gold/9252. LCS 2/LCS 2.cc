#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;

    int dp[s2.size()+1][s1.size()+1];
    for(int i=0;i<=s1.size();i++) dp[0][i] = 0;
    for(int i=0;i<=s2.size();i++) dp[i][0] = 0;

    for(int i=1;i<=s2.size();i++){
        for(int j=1;j<=s1.size();j++){
            if(s2[i-1] == s1[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }



    // for(int i=0;i<=s2.size();i++){
    //     for(int j=0;j<=s1.size();j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    

    int x = s2.size(), y = s1.size();
    cout << dp[x][y] << "\n";

    deque<char> deq;
    while(dp[x][y]){

        if(s2[x-1] == s1[y-1]){
            deq.push_front(s2[x-1]);
            x--,y--;
        }
        else{
            if(dp[x-1][y] > dp[x][y-1]) x--;
            else y--;
        }
    }
    for(auto k : deq) cout << k;
    
    return 0;
}
