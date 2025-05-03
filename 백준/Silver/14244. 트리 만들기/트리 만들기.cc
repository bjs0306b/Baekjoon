#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n-m;i++){
        cout << i << " " << i+1 << "\n";
    }

    for(int i=n-m+1;i<n;i++){
        cout << n-m << " " << i << "\n";
    }

    return 0;
}