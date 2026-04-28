#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string n;
    cin >> n;
    switch(n[0]){
        case 'A':{
            if (n[1] == '+') cout << "4.3";
            else if(n[1] == '0') cout << "4.0";
            else cout << "3.7";
            break;
        }
        case 'B':{
            if (n[1] == '+') cout << "3.3";
            else if(n[1] == '0') cout << "3.0";
            else cout << "2.7";
            break;
        }
        case 'C':{
            if (n[1] == '+') cout << "2.3";
            else if(n[1] == '0') cout << "2.0";
            else cout <<"1.7";
            break;
        }
        case 'D':{
            if (n[1] == '+') cout << "1.3";
            else if(n[1] == '0') cout << "1.0";
            else cout << "0.7";
            break;
        }
        case 'F':
            cout << "0.0"; break;
    }
    
    
    return 0;
}