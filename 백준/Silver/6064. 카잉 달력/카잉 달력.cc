#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    for(int i=0;i<n;i++){
        int m,n,x,y; cin >> m >> n >> x >> y;
        y %= n;
        bool flag = true;
        for(int i=0;i<n;i++){
            if((x+i*m)%n==y){
                cout << x+i*m << "\n";
                flag = false;
                break;
            }
        }
        if(flag) cout << "-1\n";
    }
    
    return 0;
}