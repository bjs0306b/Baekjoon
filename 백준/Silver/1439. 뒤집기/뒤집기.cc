#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str; cin >> str;
    long long cnt=0;
    for(int i=1; i<str.size(); i++){
        if(str[i-1] != str[i]) cnt++;
    }
    cout << (cnt+1)/2;
    
    
    return 0;
}