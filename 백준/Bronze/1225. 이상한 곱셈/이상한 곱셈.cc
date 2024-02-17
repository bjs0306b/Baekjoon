#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin >>a>>b;
    long long suma = 0, sumb =0;
    for(long long i=0;i<a.size();i++){long long num = a[i] - '0'; suma += num;}
    for(long long i=0;i<b.size();i++){long long num = b[i] - '0'; sumb += num;}
    cout << suma*sumb;
    
    
    return 0;
}