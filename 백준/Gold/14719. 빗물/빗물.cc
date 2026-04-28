#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> A(m), L(m), R(m), mn(m);
    for (int i = 0; i < m; i++)
        cin >> A[i];
    int L_max = 0; for(int i=0;i<m;i++){ L_max = max(L_max, A[i]); L[i] = L_max;}
    int R_max = 0; for(int i=m-1;i>=0;i--){ R_max = max(R_max, A[i]); R[i] = R_max;}
    for(int i=0;i<m;i++) mn[i] = min(L[i], R[i]);
    int ans = 0;
    for(int i=0;i<m;i++) ans += mn[i] - A[i];
    cout << ans;

    return 0;
}