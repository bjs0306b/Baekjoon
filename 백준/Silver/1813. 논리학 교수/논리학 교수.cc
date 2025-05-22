#include <bits/stdc++.h>
using namespace std;

int A[51];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        A[num]++;
    }
    
    for(int i=50;i>=0;i--){
        if(A[i] == i){
            cout << i; return 0;
        }
    }
    cout << -1;

    return 0;
}