#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    char c[n];
    for(int i=0;i<n;i++) cin >> c[i];
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(c[i] == 'p' && c[i+1] == 'P' && c[i+2] == 'A' && c[i+3] == 'p'){
            i+=3;
            cnt++;
        }
    }
    cout << cnt;
    
    
    return 0;
}