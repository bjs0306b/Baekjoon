#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    double best = 0;
    int best_idx = -1;
    for(int i=0;i<3;i++){
        double a,b; cin >> a >> b;
        if(a >= 500) a -= 50;
        if(best < b/a){
            best = b/a;
            best_idx = i;
        }
    }
    if(best_idx == 0) cout << "S";
    else if(best_idx == 1) cout << "N";
    else if(best_idx == 2) cout << "U";

    return 0;
}