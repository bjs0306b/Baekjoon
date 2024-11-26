#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    set<string> ss;

    for(int i=0;i<4;i++){
        string s; cin >> s;
        ss.insert(s);
    }

    for(auto k : ss){
        for(auto kk : ss){
            cout << k << " " << kk << "\n";
        }
    }

    return 0;
}