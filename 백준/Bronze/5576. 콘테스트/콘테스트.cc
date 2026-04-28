#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr1[10],arr2[10];
    for(int i=0;i<10;i++) cin >>arr1[i];
    for(int i=0;i<10;i++) cin >>arr2[i];
    sort(arr1,arr1+10); sort(arr2,arr2+10);
    cout << arr1[8]+arr1[9]+arr1[7] << " " << arr2[7]+arr2[8]+arr2[9];
    
    
    
    return 0;
}