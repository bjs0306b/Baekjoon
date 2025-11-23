#include <bits/stdc++.h>
using namespace std;

int ans;

int main(){
    cin.tie(0)->sync_with_stdio(0); 
    
    string s; cin >> s;
    int size = s.size();
    bool used[size]; for(int i=0;i<size;i++) used[i] = false;

    int cnt_c = 0;
    for(int i=size-1;i>=0;i--){
        if(s[i] == 'C') cnt_c++;

        if(s[i] == 'B'){
            if(cnt_c > 0){
                cnt_c--;
                ans++;
                used[i] = true;
            }
        }
    }

    int cnt_b = 0;
    for(int i=size-1;i>=0;i--){
        if(s[i] == 'B' && !used[i]) cnt_b++;

        if(s[i] == 'A'){
            if(cnt_b > 0){
                cnt_b--;
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}