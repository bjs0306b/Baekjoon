#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str; getline(cin,str);
    for(auto a : str){
        if(a >= 'A' && a <= 'M' || a >= 'a' && a<='m') a+=13;
        else if( a>= 'N' && a<= 'Z' || a >= 'n' && a<='z') a-=13;
        cout << a;
    }
    
    
    return 0;
}