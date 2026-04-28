#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int arr1[4] = {0,0,0,0};
        int num; cin >> num;
        int arr[4] = {25,10,5,1};
        for(int j=0;j<4;j++){
            while(num >= arr[j]){
                num-=arr[j];
                arr1[j]++;
            }
        }
        for(int i=0;i<4;i++) cout << arr1[i] << " ";
        cout <<"\n";
    }
    
    return 0;
}