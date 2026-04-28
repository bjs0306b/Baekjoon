#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long m,n;
    cin >> m >> n;
    long long minus = m - n;
    if(minus < 0) cout << -minus;
    else cout << minus;
    
    return 0;
}