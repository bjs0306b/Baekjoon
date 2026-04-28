#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
long long arr[1000001];
long long a,b;

long long cutt(long long n){
    long long sum = 0;
    for(long long i=0;i<a;i++){
        if(arr[i] < n) break;
        sum += (arr[i] - n);
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >>a>>b;
    
    for(long long i=0;i<a;i++)cin>>arr[i];
    sort(arr,arr+a, greater<long long>());
    long long s=0,e=arr[0];
    if(cutt(s) == b) {cout << s; return 0;}
    if(cutt(e) == b) {cout << e; return 0;}
    long long m;
    while(s<=e){
        m= (s+e)/2;
        if(cutt(m) > b)
            s = m+1;
        else if(cutt(m) < b)
            e = m-1;
        else{
            cout << m; return 0;
        }
    }
    cout << s-1;
    
    return 0;
}