#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int arr[1001][1001]; 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    if(a/2 < b) b = a - b;
    
    for(int i=0;i<1001;i++){arr[i][0] = 1; arr[i][i] = 1;}
    for(int i=1;i<1000;i++){
        for(int j=0;j<i;j++){
             arr[i+1][j+1] = (arr[i][j] + arr[i][j+1])%10007;
        }
    }
    cout << arr[a][b];
    
    
    return 0;
}