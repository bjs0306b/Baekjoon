#include <bits/stdc++.h>
using namespace std;
unordered_map<int,bool> s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; 
    for(;;){
        cin >> a >> b;
        int cnt = 0;
        if(a == 0 && b == 0) break;
        s.clear();
        for(int i=0;i<a;i++){int num; cin >> num; s[num] = true;}
        for(int i=0;i<b;i++){int num; cin >> num; if(s[num]) cnt++;}
        cout << cnt << "\n";
    }

    return 0;
}