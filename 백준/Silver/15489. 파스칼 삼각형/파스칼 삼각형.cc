#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long r,c,w; cin >> r >> c >> w;
    long long arr[r+w-1][r+w-1];
    for(long long i=0;i<r+w-1;i++){
        arr[i][0] = 1; arr[i][i] = 1;
    }
    for(long long i=2;i<r+w-1;i++){
        for(long long j=1;j<i;j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }

    long long sum = 0;
    for(long long i=r-1;i<r-1+w;i++){
        for(long long j=c-1;j<=c+i-r;j++){
            sum += arr[i][j];
        }
    }
    cout << sum;


    return 0;
}