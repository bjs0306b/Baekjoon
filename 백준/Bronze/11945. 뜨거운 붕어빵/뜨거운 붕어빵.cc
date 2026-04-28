#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin >> a >> b;
    string str;
    for(int i=0;i<a;i++){
       cin >> str;
       for(string::reverse_iterator riter = str.rbegin(); riter != str.rend(); riter++){
            cout << *riter;
       }
       cout << "\n";
    }  
    return 0;
}