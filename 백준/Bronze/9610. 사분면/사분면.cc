#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int arr[4], axis=0;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        if(a > 0 && b >0) arr[0]++;
        else if(a<0 && b>0) arr[1]++;
        else if(a<0 && b<0) arr[2]++;
        else if(a>0 && b<0) arr[3]++;
        else axis++;
    }
    for(int i=0;i<4;i++){
        cout << "Q" << i+1 << ": " << arr[i] << "\n";
    }
    cout << "AXIS: " << axis;
    
    return 0;
}