#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    long long num = 2;
    int num2 = 1;
    for(int i=0;i<n;i++){
        num += num2;
        num2*=2;
    }
    cout << num*num;
    
    return 0;
}