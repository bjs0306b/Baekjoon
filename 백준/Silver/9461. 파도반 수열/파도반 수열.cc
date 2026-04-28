#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    long long arr[101] = {0,1,1,1,2,2,3,4,5,7,9};
    for(int i=10;i<100;i++){
        arr[i+1] = arr[i] + arr[i-4];
    }

    while(n--){
        int num; cin >> num;
        cout << arr[num] << "\n";
    }
    
    return 0;
}