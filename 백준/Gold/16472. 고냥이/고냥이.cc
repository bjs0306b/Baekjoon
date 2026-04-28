#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26];
int n, used_total, ans;

void input(){
    cin >> n >> s;
}

void solve(){
    int f = 0, e = 0;
    int size = s.size();
    for(;e<size;e++){
        int num = s[e] - 'a';
        if(cnt[num] == 0){
            if(used_total < n){
                used_total++;
            }
            else{
                for(;;){
                    int temp = s[f] - 'a';
                    f++;
                    cnt[temp]--;
                    if(cnt[temp] == 0){
                        break;
                    }
                }
            }
        }
        cnt[num]++;
        ans = max(ans, e - f + 1);
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}