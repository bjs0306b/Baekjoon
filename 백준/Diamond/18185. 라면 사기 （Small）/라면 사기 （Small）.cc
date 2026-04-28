#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
}

void solve(){
    int ans = 0;
    for(int i=0;i<n-2;i++){
        while(v[i] && v[i+1] && v[i+2]){
            if(v[i+1] > v[i+2]){
                int temp = min(v[i], v[i+1] - v[i+2]);
                v[i] -= temp;
                v[i+1] -= temp;
                ans += 5 * temp;
            }else{
                int temp = min(v[i], v[i+1]);
                v[i] -= temp;
                v[i+1] -= temp;
                v[i+2] -= temp;
                ans += 7 * temp;
            }
        }
        ans += 3 * v[i];
        v[i] = 0;
    }
    int temp = min(v[n-2], v[n-1]);
    ans += 5 * temp;
    v[n-2] -= temp;
    v[n-1] -= temp;
    ans += 3*(v[n-2] + v[n-1]);
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}