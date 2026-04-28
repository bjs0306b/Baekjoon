#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >>a>>b; int arr[a][b];
    for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[i][j];
    int n; cin >>n;
    for(int i=0;i<n;i++){
        int ii,jj,x,y; cin >>ii>>jj>>x>>y;
        int sum = 0;
        for(int j=ii-1;j<x;j++){
            for(int k=jj-1;k<y;k++){
                sum += arr[j][k];
            }
        }
        cout << sum << "\n";
    }
    
    
    return 0;
}