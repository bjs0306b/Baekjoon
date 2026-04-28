#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int sum[10];
    int cnt = 0;
    for(int i=0;i<10;i++){
        int num; cin >> num; cnt += num;
        sum[i] = cnt;
    }
    for(int i=1;i<10;i++){
        if(sum[i] >= 100){
            if(100 - sum[i-1] >= sum[i] - 100) {cout << sum[i]; break;}
            else {cout << sum[i-1]; break;}
        }
    }
    if(sum[9] < 100) cout << sum[9];
    
    
    return 0;
}