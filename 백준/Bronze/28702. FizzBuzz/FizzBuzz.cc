#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s[3]; for(int i=0;i<3;i++) cin >> s[i];

    int ans;
    for(int i=0;i<3;i++){
        bool flag = 1;
        for(auto k : s[i]){
            if(!(k >= '0' && k <= '9')){flag = 0; break;}
        }
        if(flag){
            ans = stoi(s[i]) + 3 - i;
            break;
        }
    }

    if(ans % 3==0){
        if(ans % 5==0) cout << "FizzBuzz";
        else cout << "Fizz";
    }
    else{
        if(ans % 5==0) cout << "Buzz";
        else cout << ans;
    }

    
    
    
    return 0;
}