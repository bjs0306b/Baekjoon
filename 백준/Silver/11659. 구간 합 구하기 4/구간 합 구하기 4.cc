#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b; cin >>a>>b;
    long long arr[a+1]; arr[0]=0; for(long long i=1;i<a+1;i++) {int num; cin >> num; arr[i] = arr[i-1]+num;}
    for(long long i=0;i<b;i++){
        long long m,n,sum=0; cin >>m>>n;
        cout << arr[n]-arr[m-1] << "\n";
    }
    
    
    return 0;
}