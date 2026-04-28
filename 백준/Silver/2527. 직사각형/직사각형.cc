#include <bits/stdc++.h>
using namespace std;

int x[5], y[5];
void solve(){
    for(int i=0;i<4;i++){
        // input
        for(int j=1;j<=4;j++){
            cin >> x[j] >> y[j];
        }

        // d (공통 부분이 없음)
        if(x[2] < x[3] || x[4] < x[1] || y[2] < y[3] || y[4] < y[1]){
            cout << "d\n";
        }
        // c (점)
        else if((x[2] == x[3] && y[2] == y[3]) || (x[1] == x[4] && y[2] == y[3]) || (x[1] == x[4] && y[1] == y[4]) || (x[2] == x[3] && y[1] == y[4])){
            cout << "c\n";
        }
        // b (선분)
        else if((x[2] == x[3]) || (x[1] == x[4]) || (y[2] == y[3]) || y[1] == y[4]){
            cout << "b\n";
        }
        // a (직사각형)
        else cout << "a\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();

    return 0;
}