#include <bits/stdc++.h>
using namespace std;

map<string, int> um;

bool func(){
    um.clear();
    int n; cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        string s; cin >> s;
        v[i] = s;
        while(s.size()){
            um[s]++;
            s.pop_back();
        }
    }

    for(int i=0;i<n;i++){
        if(um[v[i]] > 1) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) if(func()) cout << "YES\n"; else cout << "NO\n";
    
    return 0;
}