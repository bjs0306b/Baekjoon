#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> um;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b; cin >> a  >> b;
    vector<int> v(a); for(int i=0;i<a;i++) cin >> v[i];
    um[0] = 1;
    for(int i=0;i<a;i++){
        for(int j=0;j<=b-v[i];j++){
            um[j+v[i]] += um[j];
        }
    }
    // for(int i=0;i<=b;i++) cout << um[i] << " ";
    cout << um[b];
    return 0;
}