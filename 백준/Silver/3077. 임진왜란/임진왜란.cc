#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<string, int> um;
    for(int i=0;i<n;i++){string s; cin >> s; um[s] = i;}

    vector<int> v;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        v.push_back(um[s]);
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(v[i] < v[j]) ans++;
        }
    }
    cout << ans << "/" << n*(n-1)/2;

    return 0;
}