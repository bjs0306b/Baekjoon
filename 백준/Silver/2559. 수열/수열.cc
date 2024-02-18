#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b, max = INT64_MIN; cin >>a>>b; long long arr[a+1]; arr[0] = 0;
    for(long long i=1;i<=a;i++) {long long num; cin >> num; arr[i] = arr[i-1] + num;}
    for(long long i = b; i <= a; i++){
        long long num = arr[i] - arr[i-b];
        if(max < num) max = num;
    }
    cout << max;
    
    
    
    return 0;
}