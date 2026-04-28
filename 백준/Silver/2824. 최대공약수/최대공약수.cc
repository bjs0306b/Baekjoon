#include <bits/stdc++.h>
using namespace std;

int gcd(int n, int m){
    if(n % m) return gcd(m, n%m);
    return m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v1(n); for(int i=0;i<n;i++) cin >> v1[i];
    int m; cin >> m;
    vector<int> v2(m); for(int i=0;i<m;i++) cin >> v2[i];

    long long ans = 1;
    bool over_nine = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int gcd_num;
            if(v1[i] > v2[j]) gcd_num = gcd(v1[i], v2[j]);
            else gcd_num = gcd(v2[j], v1[i]);
            if(ans * gcd_num >= 1000000000) over_nine = true;
            ans = ans * gcd_num % 1000000000;
            v1[i] /= gcd_num;
            v2[j] /= gcd_num;
        }
    }
    string temp = to_string(ans);
    while(over_nine && temp.size() < 9){
        temp = '0' + temp;
    }
    cout << temp;

    return 0;
}