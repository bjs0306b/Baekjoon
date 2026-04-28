#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string n;
    cin >> n;
    for(int i=0;i<n.size();i++){
        if(n[i] >= 'a' && n[i] <= 'z') n[i] -= 32;
        else n[i] += 32;
    }
    cout << n;
    
    return 0;
}