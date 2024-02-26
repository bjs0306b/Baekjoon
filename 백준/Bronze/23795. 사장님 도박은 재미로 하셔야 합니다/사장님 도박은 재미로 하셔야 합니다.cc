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
    int num,sum=0;
    for(;;){
        cin >> num; if(num == -1) break;
        sum += num;
    }
    cout << sum;
    
    return 0;
}