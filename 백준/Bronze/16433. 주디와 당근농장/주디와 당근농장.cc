#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int a,b; cin >> a >> b;

    if((a+b)%2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j)%2) cout << "v";
                else cout << ".";
            }
            cout << "\n";
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j)%2) cout << ".";
                else cout << "v";
            }
            cout << "\n";
        }
    }
    
    return 0;
}