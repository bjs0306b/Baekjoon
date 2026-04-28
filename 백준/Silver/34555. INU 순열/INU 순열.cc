#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    if(n%2){
        cout << n/2 + 1 << " ";
        for(int i=1;i<=n/2;i++) cout << n/2 - i + 1 << " " << n/2 + i + 1<< " ";
    }
    else{
        cout << n/2 << " " << n/2 + 1 << " ";
        for(int i=1;i<n/2;i++) cout << n/2 - i << " " << n/2 + 1 + i << " ";
    }
    return 0;
}