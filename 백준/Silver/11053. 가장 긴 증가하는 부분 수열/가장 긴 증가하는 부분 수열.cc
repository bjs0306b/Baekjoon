#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int score[n]; for(int i=0;i<n;i++) cin >>score[i];
    int arr[n]; for(int i=0;i<n;i++) arr[i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(score[j] < score[i]){
                arr[i] = max(arr[i], arr[j]+1);
            }
        }
    }
    cout << *max_element(arr, arr+n);
    return 0;
}   