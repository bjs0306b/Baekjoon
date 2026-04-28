#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b;
    cin >> a>>b;
    a = a - a%100;
    int cnt = 0;
    while(a % b) {cnt++; a++;}
    if(cnt == 0) cout << "00";
    else if(cnt > 0 && cnt < 10) cout << 0 << cnt;
    else cout << cnt;
    
    
    return 0;
}