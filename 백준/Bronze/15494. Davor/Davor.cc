#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int d = n / 364 - 3;
    
    int x=0,k=1;

    if(d > 100){
        int temp = (d-98)/3;
        x = d - 3*temp;
        k += temp;
    }
    else{
        x = d;
    }
    
    cout << x << "\n" << k;

    return 0;
}