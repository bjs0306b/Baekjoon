#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    char pre = ' ';
    int ans = 0;
    int N=-1,S=-1;
    for(int i=0;i<n;i++){
        char c; cin >> c;
        
        if(c != pre){
            ans = max(ans,min(N,S));
            if(c=='N') N=0;
            else S=0;
        }
        
        if(c == 'N') N++;
        else S++;

        pre = c;
    }
    ans = max(ans,min(N,S));
    
    cout << ans*2;

    
    return 0;
}