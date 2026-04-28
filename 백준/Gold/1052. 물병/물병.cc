#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;

    if(n < k){
        cout << 0; return 0;
    }

    vector<int> v;

    int temp = pow(2,23);
    while(n){
        if(n >= temp){
            v.push_back(temp);
            n -= temp;
        }
        else temp /= 2;
    }

    if(v.size() <= k){
        cout << 0; return 0;
    }

    int ans = v[k-1];
    for(int i=k;i<v.size();i++) ans -= v[i];
    cout << ans;
        
    
    return 0;
}