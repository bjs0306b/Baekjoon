#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<string> v(n); for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == 'S'){
                cout << v[i];
                break;
            }
        }
    }

    return 0;
}