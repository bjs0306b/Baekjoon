#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> mn(n+1);
    for(int i=0;i<=n;i++) mn[i] = i;

    int arr[3] = {2,5,7};

    for(int i=0;i<3;i++){
        for(int j=0;j<=n-arr[i];j++){
            mn[j+arr[i]] = min(mn[j+arr[i]], mn[j] + 1);
        }
    }
    cout << mn[n];

    return 0;
}