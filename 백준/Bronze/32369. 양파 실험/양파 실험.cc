#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b; cin >> n >> a >> b;
    int A = 1, B = 1;

    for(int i=0;i<n;i++){
        A += a; B += b;
        if(A < B) swap(A,B);
        else if(A == B){
            B--;
        }
    }
    cout << A << " " << B;

    return 0;
}