#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int m, k; cin >> m >> k;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    int temp = m*k;
    for(int i=0;i<n;i++){
        temp -= v[i];
        if(temp <= 0){
            cout << i+1;
            return 0;
        }
    }
    cout << "STRESS";

    return 0;
}