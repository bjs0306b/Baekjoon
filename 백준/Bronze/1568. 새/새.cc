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
    int n; cin >> n;
    int temp = 1;
    int cnt = 0;
    while(n != 0){
        if(n < temp)temp=1;
        n-=temp; temp++;
        cnt++;;
    }
    cout << cnt;
    
    return 0;
}