#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;

    int ans = 0;
    for(int i=0;i<a;i++){
        int n1,n2; cin >> n1 >> n2;
        if(abs(n1-n2) <= b){
            ans += max(n1,n2);
        }
        else{
            int n3; cin >> n3;
            ans += n3;
        }
    }

    cout << ans;
    
    
    return 0;
}