#include <iostream>
#include <string>
#include <list>
#include <set>
using namespace std;

int main(){
    string str;
    while(1){
        int cnt = 0;
        cin >> str;
        if(str == "0") break;
        int len = str.length();
        
        for(int i=0;i<(len/2+1);i++) {
            if(str[i] != str[len-1-i]){
                cnt++;
            }
        }
        if(cnt == 0) cout << "yes" << "\n";
        else cout << "no" << "\n";
       
    } 
}