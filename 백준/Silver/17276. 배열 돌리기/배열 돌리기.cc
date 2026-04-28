#include <bits/stdc++.h>
using namespace std;

int n, A[500][500], d;
void input(){
    cin >> n >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }
    d = (d + 360) % 360;
    d /= 45;
}

int dx[] = {-1,-1,-1,0,1,1,1,0}, dy[] = {-1,0,1,1,1,0,-1,-1};
void rotate(){
    int n_2 = n / 2;
    int temp[8][n_2];

    for(int i=0;i<8;i++){
        for(int j=0;j<n_2;j++){
            int nx = n_2 + (j+1) * dx[i], ny = n_2 + (j+1) * dy[i];
            temp[i][j] = A[nx][ny];
        }
    }

    for(int i=0;i<8;i++){
        for(int j=0;j<n_2;j++){
            int nx = n_2 + (j+1) * dx[i], ny = n_2 + (j+1) * dy[i];
            A[nx][ny] = temp[(i+7)%8][j];
        }
    }
}

void solve(){
    for(int i=0;i<d;i++) rotate();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        input();
        solve();
    }

    return 0;
}