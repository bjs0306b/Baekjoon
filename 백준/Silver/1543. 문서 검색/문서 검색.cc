#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b;
    getline(cin, a); getline(cin,b);
    int cnt = 0;
    int p = 0;
    for(;;){
        int k = a.find(b, p);
        if(k == string::npos)  break;
        p = k + b.size();
        cnt++;
    }
    cout << cnt;
    
    
    return 0;
}