#include <bits/stdc++.h>
using namespace std;

long long total[51], patty[51];
long long x, ans;

void func(int level){

    if(level == 0){x--; ans++; if(x == 0){cout << ans; exit(0); } }
    else{
        x--; if(x == 0){cout << ans; exit(0); }
        if(total[level-1] > x) func(level-1);
        else{x -= total[level-1]; ans += patty[level-1]; if(x == 0){cout << ans; exit(0); }}
        x--;
        ans++; if(x == 0){cout << ans; exit(0); }
        if(total[level-1] > x) func(level-1);
        else{x -= total[level-1]; ans += patty[level-1]; if(x == 0){cout << ans; exit(0); }}
        x--; if(x == 0){cout << ans; exit(0); }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long t = 1, p = 1;
    for(int i=0;i<=50;i++){
        total[i] = t, patty[i] = p;
        t = t*2 + 3;
        p = p*2 + 1;
    }
    long long n; cin >> n >> x;

    
    func(n);

    return 0;
}