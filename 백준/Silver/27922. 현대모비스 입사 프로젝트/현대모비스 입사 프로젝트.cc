#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,n;
    cin >> k >> n;
    
    vector<int> v[3];
    while(k--){
        int a,b,c; cin >> a >> b >> c;
        v[0].push_back(a+b), v[1].push_back(b+c), v[2].push_back(a+c);
    }


    int ans = 0;
    for(int i=0;i<3;i++){
        sort(v[i].begin(), v[i].end(), greater<int>());
        int temp = 0;
        for(int j=0;j<n;j++) temp += v[i][j];
        ans = max(ans, temp);
    }
    cout << ans;

    

    return 0;
}