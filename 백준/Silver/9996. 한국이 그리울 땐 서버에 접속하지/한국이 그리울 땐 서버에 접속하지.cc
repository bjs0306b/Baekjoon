#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    string pa="", pb="";

    bool flag = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '*'){flag = 1; continue;}
        if(flag == 0){
            pa += s[i];
        }
        else pb += s[i];
    }

    while(n--){
        string str; cin >> str; 

        if(pa.size() + pb.size() > str.size()){cout << "NE\n"; continue;}

        for(int i=0;i<pa.size();i++){
            if(pa[i] != str[i]){cout << "NE\n"; goto end;}
        }
        for(int i = str.size()-1, j = pb.size()-1; j >= 0; i--, j--){
            if(pb[j] != str[i]){cout << "NE\n"; goto end;}
        }
        cout << "DA\n";
        end:;
    }
    
    return 0;
}