#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, sum=0,t,a,b;
    cin >> n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a>>b;
        sum += a*b;
    }
    if(n == sum) cout << "Yes";
    else cout << "No";
    
    return 0;
}