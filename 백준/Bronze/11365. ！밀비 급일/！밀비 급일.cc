#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str;
    string::reverse_iterator riter;
    while(1){
        getline(cin, str);
        if(str == "END") break;
        for(riter = str.rbegin(); riter != str.rend(); riter++){
            cout << *riter;
        }
        cout << "\n";
    }
    
    
    return 0;
}