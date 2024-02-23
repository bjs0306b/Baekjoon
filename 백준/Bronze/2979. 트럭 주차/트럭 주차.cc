#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int arr[101];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin >>a>>b>>c; memset(arr, 0, 404);
    for(int i=0;i<3;i++){
        int d,e; cin >> d>>e;
        for(int j=d;j<e;j++) arr[j]++;
    }
    int sum = 0;
    for(int i=1;i<101;i++){
        if(arr[i] == 1) sum += a;
        else if(arr[i] == 2) sum += 2*b;
        else if(arr[i] == 3) sum += 3*c;
    }
    cout << sum;
    
    return 0;
}