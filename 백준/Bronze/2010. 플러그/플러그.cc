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
    int sum = 0;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        sum += num;
    }
    cout << sum -n+1;
    
    return 0;
}   