#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    for(;;){
        cin >> n; if(n==0) break;
        cin.ignore();
        int temp = 0;
        for(int i=0;i<n;i++){   
            string s; getline(cin, s);
            if(s.size() <= temp) continue;
            for(;;){
                if(s[temp] == ' ' || temp == s.size()) break;
                else temp++;
            }
        }
        cout << temp+1 << '\n';
    }
    
    return 0;
}