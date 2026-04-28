#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[7] = {64,32,16,8,4,2,1};
    int cnt = 0, i=0;
    while(n){
        if(n - arr[i] >= 0){ n-=arr[i]; cnt++;}
        else i++;
    }
    cout << cnt;
    return 0;
}