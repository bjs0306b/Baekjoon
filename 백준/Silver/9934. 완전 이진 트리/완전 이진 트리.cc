#include <bits/stdc++.h>
using namespace std;

int n;
int num;
vector<int> v, w[10];
void input(){
    cin >> n;
    num = pow(2, n) - 1;
    v.resize(num);
    for(int i=0;i<num;i++) cin >> v[i];
}

void D_C(int s, int e, int dep){
    int m = (s+e)/2;
    w[dep].push_back(v[m]);
    if(s == e) return;
    D_C(s, m-1, dep+1);
    D_C(m+1,e,dep+1);
}

void solve(){
    D_C(0, num-1, 0);

    for(int i=0;i<n;i++){
        for(auto k : w[i]) cout << k << " ";
        cout << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}