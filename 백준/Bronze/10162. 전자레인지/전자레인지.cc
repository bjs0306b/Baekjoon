#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    if(n%10==0){
        cout << n/300 << " "<<n%300/60 <<" "<< n%60/10;
    }
    else cout << -1;
    
    
    return 0;
}