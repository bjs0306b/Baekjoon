#include <iostream>
#include <algorithm>
using namespace std;

int mulmul(int a, int b, int c){
    int i;
    for(i = a;!(i%b==0&&i%c==0);i+=a);
    return i;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[5]; for(int i=0;i<5;i++)cin>>arr[i];
    int min = 10000000;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<4;j++){
            for(int k=j+1;k<5;k++){
                int temp = mulmul(arr[i],arr[j],arr[k]);
                if(temp < min) min = temp;
            }
        }
    }
    cout << min;
    
    return 0;
}