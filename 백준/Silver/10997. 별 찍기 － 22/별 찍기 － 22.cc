#include <bits/stdc++.h>
using namespace std;

bool A[400][400];

void func(int n){
    int x = 2*n, y = 2*n;
    for(int i=0;i<397-4*n;i++){
        A[x][y+i] = true;
        A[x+398-4*n][y+i] = true;
    }
    for(int i=0;i<399-4*n;i++){
        A[x+i][y] = true;
        if(i != 1) A[x+i][y+396-4*n] = true;
    }
    if(n != 99) A[x+2][y+395-4*n] = true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=0;i<100;i++) func(i);

    int n; cin >> n;
    if(n == 1){
        cout << "*";
        return 0;
    }
    for(int i=0;i<4*n-1;i++){
        if(i == 1){
            cout << "*\n";
            continue;
        }
        for(int j=0;j<4*n-3;j++){
            if(A[200-2*n+i][200-2*n+j]) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
    return 0;
}