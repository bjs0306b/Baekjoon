#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int sum1=0,sum2=0;
    for(int i=0;i<s.size()/2;i++){
        int num = s[i] - '0';
        sum1 += num;
    }
    for(int i=s.size()/2;i<s.size();i++){
        int num = s[i] - '0';
        sum2 += num;
    }
    if(sum1 == sum2) cout << "LUCKY";
    else cout << "READY";
    
    return 0;
}