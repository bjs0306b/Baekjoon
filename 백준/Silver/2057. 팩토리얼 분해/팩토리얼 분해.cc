#include <bits/stdc++.h>
using namespace std;

long long fac[20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    if(n == 0){
        cout << "NO";
        return 0;
    }
    fac[0] = 1,fac[1] = 1;
    for(int i=2;i<20;i++){
        fac[i] = fac[i-1] * i;
    }

    for(int i=19;i>=0;i--){
        if(fac[i] <= n) n -= fac[i];
    }

    if(n) cout << "NO";
    else cout << "YES";


    return 0;
}