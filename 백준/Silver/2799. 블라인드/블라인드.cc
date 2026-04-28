#include <bits/stdc++.h>
using namespace std;

vector<int> ans(5);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b; cin >> a >> b;
    vector<vector<int>> v(a, vector<int>(b, 0));
    for(int i=0;i<5*a+1;i++){
        for(int j=0;j<5*b+1;j++){
            char c; cin >> c;
            if(j % 5 == 1 && i != 5*a && j != 5*b && c == '*'){
                v[i/5][j/5]++;
            }
        }
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
           ans[v[i][j]]++;
        }
    }

    for(auto k : ans) cout << k << " ";

    return 0;
}