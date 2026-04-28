#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin >> a >> b;
    int mul = a*b;
    for(int i=0;i<5;i++){
        int num;
        cin >> num;
        cout << (num-mul) << " ";
    }
    
    
    return 0;
}