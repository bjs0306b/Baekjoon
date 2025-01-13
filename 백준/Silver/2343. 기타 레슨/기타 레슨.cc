#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int l, r = 0;
    vector<int> v(n); for(int i=0;i<n;i++){cin >> v[i]; r+=v[i];}
    l = *max_element(v.begin(), v.end());

    int mid;
    while(l <= r){
        mid = (l+r)/2;
        int cnt = 0;
        int sum = 0;
        for(auto k : v){
            if(sum + k > mid){
                sum = 0;
                cnt++;
            }
            sum += k;
        }
        if(sum) cnt++;

        if(cnt > m) l = mid + 1;
        else r = mid - 1;
    }
    cout << l;

    return 0;
}