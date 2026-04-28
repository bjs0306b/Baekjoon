#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long sum = 0;
    for(long long i=0;i<5;i++){
        long long num; cin >> num;
        sum += num;
    }
    cout << sum;
    
    return 0;
}