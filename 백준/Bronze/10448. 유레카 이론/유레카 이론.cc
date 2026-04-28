#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[100]; for(int i=1;i<50;i++) arr[i] = i*(i+1)/2;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        int check = 0;
        for(int j=1;j<50;j++){
             for(int k=1;k<50;k++){
                 for(int l=1;l<50;l++){
                    if(arr[j]+arr[k]+arr[l] == num) check = 1;
                 }
             }
        }
        cout << check << "\n";
    }
    
    return 0;
}