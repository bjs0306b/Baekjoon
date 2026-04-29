#include <bits/stdc++.h>
using namespace std;

int A[4][7][7];
int n; 
void rotate(int cnt){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[cnt][j][n-i-1] = A[cnt-1][i][j]; 
        }
    }
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=1;j<=3;j++){
            for(int k=0;k<n;k++){
                cout << A[j][i][k];
            }
            cout << " ";
        }
        cout << "\n";
    }
}

void solve(){
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[0][i][j];
    for(int i=1;i<=3;i++) rotate(i);
    print();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for(int i=1;i<=t;i++){
        cout << "#" << i << "\n";
        solve();
    }

    return 0;
}