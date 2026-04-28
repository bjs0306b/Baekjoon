#include <bits/stdc++.h>
using namespace std;

string s;
int n; 

void input(){
    cin >> n;
    cin >> s;
}

int solve(){
    int ret = 0;
    int cnt_l = 0, cnt_s = 0;
    for(int i=0;i<n;i++){
        if(s[i] >= '1' && s[i] <= '9') ret++;
        if(s[i] == 'L') cnt_l++;
        if(s[i] == 'S') cnt_s++;
        if(s[i] == 'R'){
            if(cnt_l){
                cnt_l--;
                ret++;
            }
            else return ret;
        }
        if(s[i] == 'K'){
            if(cnt_s){
                cnt_s--;
                ret++;
            }
            else return ret;
        }
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}