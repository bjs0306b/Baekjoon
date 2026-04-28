#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,max=0;
    cin >> n;
    int arr[n],arr2[n]; for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=i+1;j<n && arr[i] > arr[j];j++){
            cnt++;
        }
        if(max < cnt) max = cnt;
    }
    cout << max;
    
    return 0;
}