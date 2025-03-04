#include <bits/stdc++.h>
using namespace std;

bool A[2048][2048];

void print(int x, int y, int temp, int n){
    if(n==0) return;
    
    if(n%2==0){
        for(int i=0;i<=temp;i++){
            A[x-i][y-i] = true;
            A[x-i][y+i] = true;
        }
        for(int i=0;i<=temp ;i++){
            A[x-temp][y-temp+i] = true;
            A[x-temp][y+temp-i] = true;
        }
        print(x-temp+1, y, (temp-2)/2, n-1);
    }
    else{
        for(int i=0;i<=temp;i++){
            A[x+i][y-i] = true;
            A[x+i][y+i] = true;
        }
        for(int i=0;i<=temp ;i++){
            A[x+temp][y-temp+i] = true;
            A[x+temp][y+temp-i] = true;
        }
        print(x+temp-1, y, (temp-2)/2, n-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int temp = 0;
    for(int i=1;i<n;i++){
        temp = temp * 2 + 2;
    }
    if(n%2) print(0, temp, temp, n);
    else print(temp, temp, temp, n);

    if(n%2){
        for(int i=0;i<=temp;i++){
            for(int j=0;j<temp+1+i;j++){
                if(A[i][j]) cout << '*';
                else cout << ' ';
            }
            cout << "\n";
        }
    }
    else{
        for(int i=0;i<=temp;i++){
            for(int j=0;j<temp*2+1-i;j++){
                if(A[i][j]) cout << '*';
                else cout << ' ';
            }
            cout << "\n";
        }
    }
    


    return 0;
}