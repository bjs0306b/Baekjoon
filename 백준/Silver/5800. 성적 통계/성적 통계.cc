#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        int arr[num];
        for(int j=0;j<num;j++) cin >> arr[j];
        sort(arr, arr+num);
        int mx_gap=0;
        for(int j=0;j<num-1;j++){
            mx_gap = max(mx_gap, arr[j+1]-arr[j]);
        }
        cout << "Class " << i+1 << "\nMax " << arr[num-1] << ", Min " << arr[0] << ", Largest gap " << mx_gap << "\n"; 
    }
    
    return 0;
}