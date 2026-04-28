#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        int cnt = 0;
        for(int j=0;j<s.size()/2;j++){
            if(s[j] == s[s.size()-j-1]) cnt++;
            else break;
        }
        if(s.size()/2 == cnt) cout << 1;
        else cout << 0;
        cout << " " << cnt+1 << "\n";
    }
    
    return 0;
}