#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;
    map<long long,long long> m;
    while(n--){
       long long num; cin >> num;
        m[num]++;
    }
    long long max = 0;
    long long frequen;
    for(auto a : m){
        if(a.second > max){max = a.second; frequen = a.first;}
    }
    cout << frequen;
    
    return 0;
}