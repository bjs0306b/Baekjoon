#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,d; cin >> a >> b >> c >> d;
    int cnt = 0;
    for(;;){
        if(cnt++ == 10000) break;
        if(c == d){cout << c; return 0;}
        else if(c > d) d += b;
        else c += a;
    }
    cout << -1;
    
    
    return 0;
}