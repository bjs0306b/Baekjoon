#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    long long sum = 0;
    cin >> n >> x;
    vector<long long> a(n),b(n); for(int i=0;i<n;i++)cin >> a[i]; for(int i=0;i<n;i++)cin >> b[i];

    for(int i=0;i<n;i++){
        sum += b[i];
        if(sum < a[i]){
            cout << -1;
            return 0;
        }
    }
    cout << (sum - a[n-1])/x;

    return 0;
}