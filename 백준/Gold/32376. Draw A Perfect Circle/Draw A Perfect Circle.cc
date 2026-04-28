#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double n;
    double r; 
    vector<double> v;
    cin >> n >> r;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        double temp = sqrt(a*a + b*b);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    //for(auto k : v) cout << k << " ";

    double mx = 0;
    for(int i=0;i<n;i++){
        double temp = v[i] + r;
        double num = upper_bound(v.begin(), v.end(), temp) - v.begin() - i;
        mx = max(mx, num);
    }
    //cout << mx/n*100;

    printf("%.6f",  mx/n*100);

    return 0;
}