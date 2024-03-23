#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
bool arr[101][101];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    while(n--){
        int a,b; cin >> a >> b;
        for(int i=a;i<a+10;i++){
            for(int j=b;j<b+10;j++){
                arr[i][j] = 1;
            }
        }
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(arr[i][j]){
                if(arr[i-1][j] == 0) ans++;
                if(arr[i+1][j] == 0) ans++;
                if(arr[i][j-1] == 0) ans++;
                if(arr[i][j+1] == 0) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}