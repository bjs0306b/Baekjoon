#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int n; 
int centx, centy;
void func(int i, int j){
    if(abs(i - centx)%2==0 && abs(j - centy)%2==0) cout << "*";
    else if(abs(i - centx)%2==0){
        if(abs(j - centy) <= abs(i - centx)) cout << "*";
        else cout << " ";
    }
    else if(abs(j - centy)%2==0){
        if(abs(i - centx) <= abs(j - centy)) cout << "*";
        else cout << " ";
    }
    else cout << " ";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    centx = 2*n-2;
    centy = 2*n-2;
    for(int i=0;i<4*n-3;i++){
        for(int j=0;j<4*n-3;j++){
            func(i, j);
        }
        cout << "\n";
    }
    
    return 0;
}
