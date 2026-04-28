#include <bits/stdc++.h>
using namespace std;

map<string, int> cnt;
int total_cnt;
void input(){
    string s;
    while(getline(cin, s)){
        cnt[s]++;
        total_cnt++;
    }
}

void solve(){
    for(auto k : cnt){
        cout << k.first << " ";
        cout << fixed << setprecision(4) << k.second / (double) total_cnt * 100 << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}