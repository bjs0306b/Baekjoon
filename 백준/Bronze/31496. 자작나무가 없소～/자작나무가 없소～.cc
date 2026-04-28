#include <bits/stdc++.h>
using namespace std;

int n, ans; 
string s;

bool ss_in_s(string ss){
    string temp = "";
    for(int i=0;i<ss.size();i++){
        if(ss[i] == '_'){
            if(temp == s) return true;
            temp = "";
        }
        else{
            temp += ss[i];
        }
    }
    if(temp == s) return true;
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> s;

    for(int i=0;i<n;i++){
        string ss;
        int nn; 
        cin >> ss >> nn;
        
        if(ss_in_s(ss)){
            ans += nn;
        }
    }
    cout << ans;
    
    return 0;
}