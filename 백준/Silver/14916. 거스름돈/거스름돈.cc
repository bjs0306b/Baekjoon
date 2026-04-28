#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,cnt=0;
    cin >> n; if(n==1 || n==3){cout << -1; return 0;}
    while(n >= 5){
        n-=5; cnt++;
    }
    if(n%2){
        n+=5; cnt += (n/2-1);
    }
    else cnt += n/2;

    cout << cnt;
    
    return 0;
}