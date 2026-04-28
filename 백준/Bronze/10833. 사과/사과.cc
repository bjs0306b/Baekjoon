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
    long long sum = 0;
    while(n--){
        int a,b; cin >> a>>b;
        sum += b%a;
    }
    cout << sum;
    return 0;
}