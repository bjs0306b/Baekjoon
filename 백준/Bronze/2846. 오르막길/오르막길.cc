#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[n+1]; for(int i=0;i<n;i++) cin >> arr[i];
    arr[n] = 0;
    int max = 0, cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i+1] > arr[i]) cnt++;
        else {
            if(max < (arr[i] - arr[i-cnt])) max = arr[i] - arr[i-cnt];
            cnt = 0;
        }
    }
    cout << max;
    return 0;
}