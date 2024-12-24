#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string s; cin >> s;
        int pos = find(s.begin(), s.end(), '.') - s.begin();
        string temp = s.substr(pos+1, s.npos);
        m[temp]++;
    }
    for(auto k : m){
        cout << k.first << " " << k.second << "\n";
    }

    return 0;
}