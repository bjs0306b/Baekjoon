#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int arr[100];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                arr[i+j+k]++;
            }
        }
    }
    cout << max_element(arr, arr+100)-arr;
    
    
    return 0;
}

