#include <iostream>
#include <algorithm>
using namespace std;

unsigned int a,b,imax,s,e,m,ans;
unsigned int arr[10001];
int count(int n){
    int sum = 0;
    for(int i=0;i<a;i++){
        sum += arr[i]/n;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a;i++) {cin >> arr[i];  imax = max(imax, arr[i]);}


    s=1, e=imax;
    while(s <= e){
        m = (s+e)/2;
        if(count(m) >= b){
            ans = m;
            s = m+1;
        }
        else e = m-1;
    } 
    cout << ans;
    return 0;
}