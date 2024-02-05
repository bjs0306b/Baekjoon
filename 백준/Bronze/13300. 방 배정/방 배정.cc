#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m, arr[2][6]; for(int i=0;i<2;i++) for(int j=0;j<6;j++) arr[i][j]=0;
    cin >> n >> m;
    while(n--){
        int a,b; cin >> a>>b;
        arr[a][b-1]++;
    }
    int sum = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            sum += (arr[i][j]+m-1)/m;
        }
    }
    cout << sum;
    return 0;
}