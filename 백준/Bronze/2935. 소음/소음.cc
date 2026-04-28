#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; char c; cin >> a>>c>>b;
    int aa = count(a.begin(), a.end(), '0'), bb = count(b.begin(), b.end(), '0');
    int mx = max(aa,bb), mn = min(aa,bb);
    
    if(c == '+'){
        if(a.size() == b.size()){
            cout << "2";
            for(int i=0;i<mn;i++) cout << "0";
        }
        else{
            cout << "1";
            for(int i=0;i<mx-mn-1;i++) cout << "0";
            cout << "1";
            for(int i=0;i<mn;i++) cout << "0";
        }
    }
    if(c == '*'){
        cout << "1";
        for(int i=0;i<mx+mn;i++) cout << "0";
    }
    return 0;
}