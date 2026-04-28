#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        int cnt =0;
        for(;;){
            if(s == "6174"){cout << cnt << "\n"; break;}
            cnt++;
            string temp = s;
            sort(temp.begin(), temp.end());
            sort(s.begin(), s.end(), greater<char>());
            int num = stoi(s) - stoi(temp);
            if(num < 1000) s = "0" + to_string(num);
            else s = to_string(num);
        }
    }
    
    return 0;
}