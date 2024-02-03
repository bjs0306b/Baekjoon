#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int player[5];
    int bp,max = 0;
    for(int i=0;i<5;i++){
        int sum = 0;
        for(int j=0;j<4;j++){ int num; cin >> num; sum += num;}
        if(max < sum){ bp = i+1; max = sum;}
    }
    cout << bp << " " << max;
    
    return 0;
}