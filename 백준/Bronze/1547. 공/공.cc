#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[4] = {0,1,0,0};
    while(n--){
        int a,b; cin >>a>>b;
        swap(arr[a], arr[b]);
    }
    for(int i=1;i<4;i++){
        if(arr[i]) cout << i;
    }
    
    return 0;
}
