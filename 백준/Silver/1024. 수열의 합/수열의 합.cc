#include <bits/stdc++.h>
using namespace std;

bool def(int n, int m){
    if(m%2){
        if(n%m == 0){
            int temp = n/m;
            for(int i=temp-m/2;i<=temp+m/2;i++){
                cout << i << " ";
            }
            return true;
        }
    }
    else{
        m /= 2;
        if(n % m == 0){
            int temp = n/m;
            if(temp % 2){
                for(int i=temp/2-m+1;i<=temp/2+m;i++) cout << i << " ";
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l; cin >> n >> l;
    for(int i=l;i<=100;i++){
        if(i*(i-1)/2 > n) break;
        if(def(n, i)) return 0;
    }
    cout << -1;
    return 0;
}