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
    int a,b,c; cin >>a>>b>>c;
    int pos = b, sum = 0;
    for(int i=0;i<c;i++){
        int num; cin >> num;
        if(pos < num){
            sum += num-pos;
            pos = num;
        }
        else if(pos-b+1 > num){
            sum += pos-b+1-num;
            pos = num+b-1;
        }
    }
    cout << sum;
    
    return 0;
}