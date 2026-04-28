#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s; int size = s.size();
    long long n = stoll(s), sum=0, ninesum=0, nine=9;
    for(int i=1;i<size;i++){
        ninesum += nine;
        sum += nine*i;
        nine*=10;
    }
    cout << sum + (n - ninesum)*size;
    
    
    return 0;
}