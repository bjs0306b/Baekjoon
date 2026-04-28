#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
void input(){
    cin >> n;
    v.resize(n);
    vector<int> temp1(n), temp2(n);
    for(int i=0;i<n;i++) cin >> temp1[i];
    for(int i=0;i<n;i++) cin >> temp2[i];
    for(int i=0;i<n;i++) v[i] = temp2[i] - temp1[i];
}

void solve(){
    int ans = 0;
    bool flag = false, flag2;
    for(;;){
        flag2 = true;
        for(int i=0;i<n;i++){
            if(v[i] > 0){
                flag = true;
                flag2 = false;
                v[i]--;
            }
            else{
                if(flag) ans++;
                flag = false;
            }
        }
        if(flag) ans++;
        flag = false;

        if(flag2) break;
    }
    flag = false;

    for(;;){
        flag2 = true;
        for(int i=0;i<n;i++){
            if(v[i] < 0){
                flag = true;
                flag2 = false;
                v[i]++;
            }
            else{
                if(flag) ans++;
                flag = false;
            }
        }
        if(flag) ans++;
        flag = false;
        if(flag2) break;
    }

    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}