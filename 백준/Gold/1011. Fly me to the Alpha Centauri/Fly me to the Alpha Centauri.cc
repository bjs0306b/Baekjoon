#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int x,y; cin >> x >> y;
        int dis = y-x;
        int temp = ceil(sqrt(dis));
    
        if(temp*(temp-1) >= dis) cout << 2*temp - 2 << "\n";
        else cout << 2*temp - 1 << "\n";
    
    }

    return 0;
}