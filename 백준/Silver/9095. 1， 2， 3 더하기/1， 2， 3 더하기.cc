#include <iostream>
#include <algorithm>
using namespace std;

int func1(int n){
    int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2] = 2;
    for(int i=3;i<n+1;i++){
        arr[i] = arr[i-1] + arr[i-2]+arr[i-3];
    }
    return arr[n];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        cout << func1(num) << "\n";
    }
    
    
    return 0;
}