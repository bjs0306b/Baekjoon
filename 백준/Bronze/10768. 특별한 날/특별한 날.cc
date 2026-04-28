#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >>a>>b;
    if(a < 2) cout << "Before";
    else if(a == 2){
        if(b < 18)  cout << "Before";
        else if(b==18) cout << "Special";
        else cout << "After";
    }
    else cout << "After";
    
    return 0;
}