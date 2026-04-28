#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; getline(cin, s);
    for(int i=0;i<s.size()-1;i++){
        if((s[i] == 'd' || s[i] == 'D')&& s[i+1] == '2'){
            cout << "D2";
            return 0;
        }
    }
    cout << "unrated";
    return 0;
}