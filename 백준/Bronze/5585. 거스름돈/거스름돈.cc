#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[6] = {500,100,50,10,5,1};
    int sum = 0;
    for(int i=0;i<6;i++){
        for(;;){
            if(n+arr[i] > 1000) break;
            n+=arr[i];
            sum++;
        }
    }
    cout << sum;
    
    return 0;
}