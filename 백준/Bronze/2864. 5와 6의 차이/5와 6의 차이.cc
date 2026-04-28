#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b;cin>>a>>b;
    string mina=a,maxa=a,minb=b,maxb=b;
    for(int i=0;i<a.size();i++){
        if(a[i] == '5') maxa[i]='6';
        if(a[i] == '6') mina[i]='5';
    }
    for(int i=0;i<b.size();i++){
        if(b[i] == '5') maxb[i]='6';
        if(b[i] == '6') minb[i]='5';
    }
    cout << stoi(mina)+stoi(minb) << " " << stoi(maxa)+stoi(maxb);
    
    return 0;
}