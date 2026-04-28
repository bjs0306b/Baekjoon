#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r,c; cin >> r >> c;
    char A[r][c]; for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> A[i][j];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(A[i][j] == 'W'){
                int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
                for(int k=0;k<4;k++){
                    if(i+dx[k] >= 0 && i+dx[k] < r && j+dy[k] >= 0 && j+dy[k] < c){
                        if(A[i+dx[k]][j+dy[k]] == 'S'){
                            cout << 0;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "1\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(A[i][j] == '.') cout << "D";
            else cout << A[i][j];
        }
        cout << "\n";
    }

    return 0;
}