#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[9];int sum = 0;for(int i=0;i<9;i++){int num; cin >> num;sum+=num; arr[i]=num;}
    sum -=100;
    int ii,jj;
    sort(arr, arr+9);
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            if(arr[i]+arr[j]==sum){ ii = i; jj = j; break;}
        }
    }
    for(int i=0;i<9;i++){
        if(i==ii || i==jj) continue;
        cout << arr[i] << "\n";
    }
    
    return 0;
}