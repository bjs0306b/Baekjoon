#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[1001], sum=0; memset(arr, 0, 4004);
    for(int i=0;i<10;i++){int num; cin >> num; sum+=num; arr[num]++;}
    int max = 0, mxnum;
    for(int i=0;i<1000;i+=10){
        if(max < arr[i]){max = arr[i]; mxnum = i;}
    }
    cout << sum/10 << "\n" << mxnum;
    
    
    return 0;
}