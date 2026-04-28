#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[21]; for(int i=1;i<21;i++) arr[i] = i;

    for(int i=0;i<10;i++){
        int a,b; cin >>a>>b;
        reverse(arr+a, arr+b+1);
    }

    for(int i=1;i<21;i++) cout << arr[i] << " ";
    
    
    return 0;
}