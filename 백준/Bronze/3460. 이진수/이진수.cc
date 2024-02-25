#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        for(int j=0;num!=0;j++){
            int a = num%2;
            if(a) cout << j << " ";
            num/=2;
        }
    }
    
    return 0;
}