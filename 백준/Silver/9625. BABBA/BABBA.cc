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
    int a=1, b=0;
    for(int i=0;i<n;i++){
        int temp = a;
        a = b; b+= temp;
    }
    cout << a << " " << b;
    
    return 0;
}