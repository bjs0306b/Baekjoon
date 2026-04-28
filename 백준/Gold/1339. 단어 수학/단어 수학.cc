#include <bits/stdc++.h>
using namespace std;

vector<int> A(26, 0);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<string> vec(n); for(int i=0;i<n;i++) cin >> vec[i];
    for(int i=0;i<n;i++){
        int temp = 1;
        for(auto riter = vec[i].rbegin(); riter != vec[i].rend(); riter++){
            int num = *riter - 'A';
            A[num] += temp;
            temp *= 10;
        }
    }
    sort(A.begin(),  A.end(), greater<int>());
    int temp = 9;
    int ans = 0;
    for(int i=0;i<10;i++){
        ans += temp * A[i];
        temp--;
    }
    cout << ans;
    
    return 0;
}