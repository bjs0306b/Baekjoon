#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,m,M,T,R; cin >> N >> m >> M >> T >> R;
    int cnt = 0;
    int ans = 0;
    int temp = m;
    if(M-m < T){cout << -1; return 0;}
    while(cnt != N){
        if(temp + T <= M){
            temp += T;
            cnt++; ans++;
        }
        else{
            temp = max(temp - R, m);
            ans++;
        }
    }
    cout << ans;

    
    
    return 0;
}