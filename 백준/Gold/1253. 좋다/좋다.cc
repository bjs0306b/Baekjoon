#include <bits/stdc++.h>
using namespace std;

int ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<n;j++){
            if(i == j) continue;

            int pos = lower_bound(v.begin(), v.end(), v[i]-v[j]) - v.begin();
            while(v[pos] == v[i] - v[j]){
                if(pos != i && pos != j){
                    flag = true;
                    break;
                }
                pos++;
            }
            if(flag) break;
        }
        if(flag) ans++;
    }
    cout << ans;
    
    return 0;
}