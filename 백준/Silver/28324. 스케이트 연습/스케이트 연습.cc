#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> A(n); 
    for(int i=0;i<n;i++)
        cin >> A[i];
    
    long long ans = 0;
    
    int temp = 0;
    for(int i=n-1;i>=0;i--){
        temp++;
        if(A[i] < temp)temp = A[i];
        ans += temp;
    }
    cout << ans;

    return 0;
}