#include <bits/stdc++.h>
using namespace std;

int scholarship[11], ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<11;i++) cin >> scholarship[i];
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a,c; double b;
        cin >> a >> b >> c;
        if(b >= 2.0 &&  c >= 17) ans += scholarship[a];
    }
    cout << ans;
    return 0;
}