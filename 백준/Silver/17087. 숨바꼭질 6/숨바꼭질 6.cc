#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a%b) return gcd(b, a%b);
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;

    vector<int> dif(n); for(int i=0;i<n;i++){int num; cin >> num; dif[i] = abs(s-num); }
    int ans = *max_element(dif.begin(), dif.end());
    for(int i=1;i<n;i++){
        ans = min(ans, gcd(dif[0], dif[i]));
    }
    cout << ans;

    return 0;
}