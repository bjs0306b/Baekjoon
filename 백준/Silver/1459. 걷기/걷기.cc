#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b,c,d; cin >> a >> b >> c >> d;

    long long ans = min(a,b)*min(2*c,d) + (max(a,b)-min(a,b))/2*2*min(c,d); 
    if((max(a,b) - min(a,b)) % 2)  ans += c;   
    cout << ans;
    
    
    return 0;
}   