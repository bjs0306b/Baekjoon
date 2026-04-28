#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    long long arr[a+2][a+2];
    for(int i=1;i<a+1;i++) {arr[i][1] = 1; arr[i][i] = 1;}

    for(int i=2;i<a+1;i++){
        for(int j=1;j<i;j++){
            arr[i+1][j+1] = arr[i][j] + arr[i][j+1];
        }
    }
    cout << arr[a][b];

    
    
    return 0;
}