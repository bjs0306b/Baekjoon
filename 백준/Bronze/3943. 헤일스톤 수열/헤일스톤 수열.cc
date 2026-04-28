#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    for(int i=0;i<n;i++){
        int num; cin >> num;


        int mx = num;
        for(;;){
            if(num == 1) break;

            if(num % 2){
                num = num * 3 + 1;
            }
            else num /=2;

            mx = max(mx, num);
        }

        cout << mx << '\n';
    }
    
    return 0;
}