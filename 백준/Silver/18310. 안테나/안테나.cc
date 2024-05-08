#include <bits/stdc++.h>
using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int n; cin >> n;
//     vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
//     sort(v.begin(), v.end());
//     long long mn, mn_idx=0;
//     for(int i=1;i<n;i++) mn += v[i] - v[0];
//     long long arr[n]; arr[0] = mn;
//     for(int i=1;i<n;i++){
//        arr[i] = arr[i-1] - (v[i] - v[i-1])*(n-2*i);
//     }

//     cout << v[min_element(arr, arr+n)-arr];

//     return 0;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[(n-1)/2];
}