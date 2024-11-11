    #include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;
    for(long long i=0;i<n;i++){
        long long t,sum=0; cin >> t;
        long long arr[t]; for(long long j=0;j<t;j++) cin >>arr[j];

        for(long long a=0;a<t-1;a++){
            for(long long b=a+1;b<t;b++){
                sum += gcd(arr[a], arr[b]);
            }
        }
        cout << sum << "\n";
    }
    
    return 0;
}