#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int sum = 10;
    char temp = s[0];
    for(int i=1;i<s.size();i++){
        if(temp == s[i])  sum+=5;
        else{sum+=10; temp = s[i];}
    }
    cout << sum;
    
    return 0;
}