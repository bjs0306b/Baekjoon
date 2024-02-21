#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a>>b;
    int num,sum=0; cin >> num;
    vector<int> v;
    for(int i=num-1;i>=0;i--){
        int n; cin >> n;
        sum += pow(a,i)*n;
    }
    while(sum){
        v.push_back(sum%b);
        sum /= b;
    }
    for(auto riter = v.rbegin(); riter != v.rend(); riter++) cout << *riter << " ";

    
    
    return 0;
}