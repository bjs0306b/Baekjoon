#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    long long sum = 0, ans = 0;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        ans = (ans + sum * num) % 1000000007;
        sum = (sum + num) % 1000000007;
    }
    cout << ans;



    return 0;
}