#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int arr[100001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >>a>>b;
    arr[0] = (a*a)%b;
    for(int i=1;;i++){
        arr[i] = (arr[i-1]*a)%b;
        if(count(arr, arr+i, arr[i]) == 1){
           cout <<  i- (find(arr,arr+i,arr[i]) - arr);
           return 0;
        }
    }
    
    
    return 0;
}