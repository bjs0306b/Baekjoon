#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int cnt=0;
    int i=0;
    while(n > i*(i+1)/2){
        if((n - i*(i+1)/2)%(i+1)==0) cnt++;
        i++;
    }
    cout << cnt;
    return 0;
}