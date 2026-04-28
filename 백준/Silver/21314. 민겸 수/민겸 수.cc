#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    int size = s.size();
    vector<string> v;
    for(int i=size-1;i>=0;i--){
        if(s[i] == 'K'){
            int cnt = 0;
            for(;;){
                i--;
                if(i < 0 || s[i] == 'K') break; 
                cnt++;
            }
            i++;
            string temp = '5'+ string(cnt, '0');
            v.push_back(temp);
        }
        else v.push_back("1");
    }
    for(int i=v.size()-1;i>=0;i--) cout << v[i];
    cout << '\n';

    for(int i=0;i<size;i++){
        if(s[i] == 'M'){
            int cnt = -1;
            for(;;){
                if(i >= size || s[i] == 'K') break;
                i++; cnt++;
            }
            i--;
            string temp = '1' + string(cnt, '0');
            cout << temp;
        }
        else cout << "5";
    }

    return 0;
}