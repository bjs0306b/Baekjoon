#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[1001][3];
    arr[0][0] =0, arr[0][1] = 0, arr[0][2]=0;
    for(int i=1;i<n+1;i++){
        int a,b,c; cin >>a>>b>>c;
        arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + a;
        arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + b;
        arr[i][2] = min(arr[i-1][1], arr[i-1][0]) + c;
    }
    cout << min({arr[n][0], arr[n][1], arr[n][2]});
    
    
    return 0;
}