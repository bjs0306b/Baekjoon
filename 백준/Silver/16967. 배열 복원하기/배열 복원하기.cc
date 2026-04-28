#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h,w,x,y; cin >> h >> w >> x >> y;
    int A[h+x][w+y];
    for(int i=0;i<h+x;i++) for(int j=0;j<w+y;j++) cin >> A[i][j];
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i < x || j < y) cout << A[i][j]<< " ";
            else{
                cout << A[i][j] - A[i-x][j-y] << " ";
                A[i][j] -= A[i-x][j-y];
            }
        }
        cout << '\n';
    }

    return 0;
}