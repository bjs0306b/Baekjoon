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
    long long arr[81]; arr[2]= 1; arr[1]=1;
    for(int i=3;i<=n;i++) arr[i] = arr[i-1]+arr[i-2];
    if(n==1) cout << 4;
    else if(n==2) cout << 6;
    else cout << 2*arr[n] + 4*arr[n-1] + 2*arr[n-2];
    
    return 0;
}