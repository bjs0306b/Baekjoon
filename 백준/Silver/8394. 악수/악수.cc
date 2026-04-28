#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int before[2] = {1,0}; // 0 : 해당 점이 이어져있지 않음, 1 : 해당 점이 전과 이어져 있음.
    
    int n; cin >> n;
    for(int i=1;i<n;i++){
        int current[2] = {(before[0]+before[1])%10, before[0]};

        before[0] = current[0], before[1] = current[1];
    }

    cout << (before[0] + before[1])%10;
    
    return 0;
}