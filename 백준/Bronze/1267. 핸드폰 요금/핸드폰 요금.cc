#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, y=0,m=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;

        y += 10*(1+num/30);
        m += 15*(1+num/60);
    }
    if(y < m){ cout << "Y " << y;}
    else if(y > m) {cout << "M " << m;}
    else cout << "Y M " << y;
    
    return 0;
}