#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    string s[n]; for(int i=0;i<n;i++) cin >> s[i];
    int size = s[0].size();
    for(int i=size-1;i>=0;i--){
        map<string, int> mp;
        bool key = true;
        for(int j=0;j<n;j++){
            string temp = s[j].substr(i, size);
            mp[temp]++;
            if(mp[temp] == 2){
                key = false;
            }
        }
        if(key){
            cout << size - i;
            break;
        }
    }
    
    return 0;
}