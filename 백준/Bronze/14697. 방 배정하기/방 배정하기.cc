#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int arr[500];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,n; cin >> a >> b >> c >> n;
    arr[a] = 1, arr[b] =1, arr[c] = 1;
    for(int i=1;i<301;i++){
        if(arr[i]){
            arr[i+a] = 1;
            arr[i+b] = 1;
            arr[i+c] = 1;
        }
    }
    if(arr[n]) cout << 1;
    else cout << 0;
    return 0;
}