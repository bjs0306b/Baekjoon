#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int a,b; 

int func(int n){
    string s = to_string(n);
    int sum = 0;
    for(auto k : s){
        int num = k - '0';
        sum += pow(num,b);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a>>b;
    vector<int> v; v.push_back(a);
    for(;;){
        a = func(a);
        if(find(v.begin(), v.end(), a) == v.end()) v.push_back(a);
        else{
            int pos = find(v.begin(), v.end(), a) - v.begin();
            cout << pos;
            break;
        }
    }
    
    
    return 0;
}