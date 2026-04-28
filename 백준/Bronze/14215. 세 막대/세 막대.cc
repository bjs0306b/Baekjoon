#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[3]; for(int i=0;i<3;i++) cin >> arr[i];
    sort(arr, arr+3);
    if(arr[0] + arr[1] > arr[2]){ cout << arr[0]+arr[1]+arr[2];}
    else{ cout <<2*(arr[0]+arr[1])-1;}
    
    return 0;
}